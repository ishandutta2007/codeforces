#include <iostream>
#include <cstdio>
using namespace std;

// handle float
inline int sign(const double &a)
{
	const double Epsilon = 1e-5;
	if (a < -Epsilon)
		return -1;
	else if (a > Epsilon)
		return 1;
	else
		return 0;
}
inline int dblcmp(const double &a, const double &b)
{
	return sign(a - b);
}

template <class T>
inline T sqr(const T &a)
{
	return a * a;
}

// geometry
const double PI = 3.14159265358;

#include <complex>
typedef std::complex<double> ComplexVector;

inline ComplexVector::value_type cross(
		const ComplexVector &a,
		const ComplexVector &b)
{
	return   a.real() * b.imag()
		   - a.imag() * b.real();
}
inline ComplexVector::value_type dot(
		const ComplexVector &a,
		const ComplexVector &b)
{
	return   a.real() * b.real()
		   + a.imag() * b.imag();
}
inline ComplexVector::value_type cross(
		const ComplexVector &a,
		const ComplexVector &o,
		const ComplexVector &b)
{
	return   (a.real() - o.real()) * (b.imag() - o.imag())
		   - (a.imag() - o.imag()) * (b.real() - o.real());
}
inline ComplexVector::value_type dot(
		const ComplexVector &a,
		const ComplexVector &o,
		const ComplexVector &b)
{
	return   (a.real() - o.real()) * (b.real() - o.real())
		   + (a.imag() - o.imag()) * (b.imag() - o.imag());
}

int main()
{
	double y1, y2, yw;
	ComplexVector b;
	double r;

	cin >> y1 >> y2 >> yw;
	cin >> b.real() >> b.imag();
	cin >> r;

	yw -= r;

	if (dblcmp(yw, y1 + r) < 0)
	{
		cout << -1 << endl;
		return 0;
	}

	b.imag() = yw - b.imag() + yw;

	ComplexVector p1(0.0, y1 + r);
	ComplexVector p2(0.0, y2);
	double d = cross(p1, p2, b) / abs(b - p1);
	if (dblcmp(d, r) < 0)
	{
		double l = sqrt(r * r - d * d);
		ComplexVector v = (b - p1) / abs(b - p1) * l;
		ComplexVector s = (b - p1) * exp(complex<double>(0.0, -PI / 2.0)) / abs(b - p1) * d + p2;
		if (dblcmp((s - v).imag(), yw) < 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	ComplexVector aim;
	aim = (b - p1) / (b.imag() - p1.imag()) * (yw - p1.imag()) + p1;
	printf("%.8lf\n", aim.real());

	return 0;
}