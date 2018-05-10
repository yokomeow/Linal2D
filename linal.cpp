#include <iostream>

using namespace std;

class Vector2D
{
private:
	int x;
	int y;
public:
	Vector2D() {
		this->x = 0;
		this->y = 0;
	}

	Vector2D(int x, int y) {
		this->x = x;
		this->y = y;
	}

	~Vector2D() { }

	int getX() const{
		return x;
	}

	int getY() const{
		return y;
	}

	void setX(int x) {
		this->x = x;
	}

    void setY(int y) {
    	this->y = y;
    }

	bool operator== (const Vector2D& v2) {
		return ((x == v2.x) && (y == v2.y));
	}

	bool operator!= (const Vector2D& v2) {
		return ((x != v2.x) || (y != v2.y));
	}

	Vector2D operator* (const int a) {
		Vector2D v3;
		v3.x = x*a;
		v3.y = y*a;
		return v3;
	}

};

class Matrix2D {
private: 
	int x1, x2, x3, x4;
public:
	Matrix2D() {
		this->x1 = 0;
		this->x2 = 0;
		this->x3 = 0;
		this->x4 = 0;
	}

	~Matrix2D() {}

	Matrix2D(int x1, int x2, int x3, int x4) {
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->x4 = x4;
	}

	int getX1() const{
		return this->x1;
	}

	int getX2() const{
		return this->x2;
	}

	int getX3() const{
		return this->x3;
	}

	int getX4() const{
		return this->x4;
	}

	void setX1(int x1) {
		this->x1 = x1;
	}

	void setX2(int x2) {
		this->x2 = x2;
	}

	void setX3(int x3) {
		this->x3 = x3;
	}

	void setX4(int x4) {
		this->x4 = x4;
	}

};

Matrix2D operator* (const Matrix2D& m1, const Matrix2D& m2) {
		int x1 = m1.getX1() * m2.getX1() + m1.getX2() * m2.getX3();
		int x2 = m1.getX1() * m2.getX2() + m1.getX2() * m2.getX4();
		int x3 = m1.getX3() * m2.getX1() + m1.getX4() * m2.getX3();
		int x4 = m1.getX3() * m2.getX2() + m1.getX4() * m2.getX4();
		Matrix2D m3;
		m3.setX1(x1);
		m3.setX2(x2);
		m3.setX3(x3);
		m3.setX4(x4);
		return m3;
	}

Vector2D operator* (const Vector2D& v, const Matrix2D& m) {
		int x1 = v.getX() * m.getX1() + v.getY() * m.getX3();
		int x2 = v.getX() * m.getX2() + v.getY() * m.getX4();
		Vector2D v3;
		v3.setX(x1);
		v3.setY(x2);
		return v3;
	}

Vector2D operator* (const Matrix2D& m, const Vector2D& v) {
		int x1 = v.getX() * m.getX1() + v.getY() * m.getX2();
		int x2 = v.getX() * m.getX3() + v.getY() * m.getX4();
		Vector2D v3;
		v3.setX(x1);
		v3.setY(x2);
		return v3;
	}

Vector2D operator* (const Vector2D& v1, const Vector2D& v2) {
		Vector2D v4(v2.getX() * v1.getX(), v2.getY() * v1.getY());
		return v4;
	}

Vector2D operator* (const int a, const Vector2D& v2) {
		Vector2D v4(v2.getX() * a, v2.getY() * a);
		return v4;
	}

Matrix2D operator* (const Matrix2D& m, int a) {
		int x1 = m.getX1() * a;
		int x2 = m.getX2() * a;
		int x3 = m.getX3() * a;
		int x4 = m.getX4() * a;
		Matrix2D m3;
		m3.setX1(x1);
		m3.setX2(x2);
		m3.setX3(x3);
		m3.setX4(x4);
		return m3;
	}

Matrix2D operator* (int a, const Matrix2D& m) {
		int x1 = m.getX1() * a;
		int x2 = m.getX2() * a;
		int x3 = m.getX3() * a;
		int x4 = m.getX4() * a;
		Matrix2D m3;
		m3.setX1(x1);
		m3.setX2(x2);
		m3.setX3(x3);
		m3.setX4(x4);
		return m3;
	}

int det(const Matrix2D& m) {
		return m.getX1() * m.getX4() - m.getX2() * m.getX3();
	}

std::ostream& operator<<(std::ostream& os, Vector2D& v)
{
      os << "(" << v.getX() << "; " << v.getY() << ")";
      return os;
}

std::ostream& operator<<(std::ostream& osm, Matrix2D& m)
{
      osm << m.getX1() << " " << m.getX2() << endl << m.getX3() << " " << m.getX4() << endl;
      return osm;
}

std::istream& operator>>(std::istream &is, Vector2D &v)
{
	int a, b;
	is >> a;
	v.setX(a);
	is >> b;
	v.setY(b);
	return is;
}

std::istream& operator>>(std::istream &ism, Matrix2D &m)
{
	int x1, x2, x3, x4;
	ism >> x1;
	m.setX1(x1);
	ism >> x2;
	m.setX2(x2);
	ism >> x3;
	m.setX3(x3);
	ism >> x4;
	m.setX4(x4);
	return ism;
}

int main()
{
	Vector2D v1(1, 1);
	Vector2D v2(42, 42);

// Умножение вектора на скаляр, скаляр на вектор, вектор на вектор: 
	Vector2D v3 = v1 * 228;
	Vector2D v4 = 2 * v2;
	Vector2D v5 = v1 * v2;

	cout << "v1 * 228 = " << v3 << endl << endl;
	cout << "2 * v2 = " << v4 << endl << endl;
	cout << "v1 * v2 = " << v5 << endl;

	Matrix2D m1(1, 0, 0, 1);
	Matrix2D m2(4, 2, 2, 4);

// Умножение матрицы на скаляр, скаляр на матрицу, матрицу на матрицу: 
	Matrix2D m3 = m1 * 9;
	Matrix2D m4 = 23 * m1;
	Matrix2D m5 = m1 * m2;

	cout << "\nm1 * 9 =\n" << m3 << endl;
	cout << "23 * m1 =\n" << m4 << endl;
	cout << "m1 * m2 =\n" << m5 << endl;

// Ввод матрицы с клавиатуры:
	Matrix2D mi;
	cin >> mi;

// Умножение матрицы на вектор дает вектор:
	Vector2D v6 = m2 * v1;

// Умножение вектора на матрицу дает вектор:
	Vector2D v7 = v2 * m1;

// Детерминант матрицы:
	cout << "\n" << det(mi) << endl;

	return 0;
}