#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>
using namespace std;

const double PI = 3.14159265358979;

// handle float
inline int sgn(const double &a)
{
	const double Epsilon = 1e-13;
	if (a < -Epsilon)
		return -1;
	else if (a > Epsilon)
		return 1;
	else
		return 0;
}
inline int dblcmp(const double &a, const double &b)
{
	return sgn(a - b);
}

template <class T>
inline T sqr(const T &a)
{
	return a * a;
}

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

// geometry
#include <complex>
class compVec : public complex<double>
{
public:
	inline compVec(){}
	inline compVec(const double &_x, const double &_y)
		: complex<double>(_x, _y){}
	inline compVec(const complex<double> &rhs)
		: complex<double>(rhs){}

	inline double &x()
	{
		return real();
	}
	inline double x() const
	{
		return real();
	}
	inline double &y()
	{
		return imag();
	}
	inline double y() const
	{
		return imag();
	}

	friend inline istream& operator>>(istream &lhs, compVec &rhs)
	{
		return lhs >> rhs.x() >> rhs.y();
	}
	friend inline ostream& operator<<(ostream &lhs, const compVec &rhs)
	{
		return lhs << rhs.x() << " " << rhs.y();
	}
};

struct segment
{
	compVec a, b;

	segment(){}
	segment(const compVec &_a, const compVec &_b)
		: a(_a), b(_b){}

	friend inline istream& operator>>(istream &lhs, segment &rhs)
	{
		lhs >> rhs.a >> rhs.b;
		return lhs;
	}
	friend inline ostream& operator<<(ostream &lhs, const segment &rhs)
	{
		return lhs << rhs.a << " " << rhs.b;
	}
};

inline double cross(
		const compVec &a, const compVec &b)
{
	return a.x() * b.y() - a.y() * b.x();
}
inline double dot(
		const compVec &a, const compVec &b)
{
	return a.x() * b.x() + a.y() * b.y();
}
inline double cross(
		const compVec &a, const compVec &o, const compVec &b)
{
	return   (a.x() - o.x()) * (b.y() - o.y())
		- (a.y() - o.y()) * (b.x() - o.x());
}
inline double dot(
		const compVec &a, const compVec &o, const compVec &b)
{
	return   (a.x() - o.x()) * (b.x() - o.x())
		+ (a.y() - o.y()) * (b.y() - o.y());
}

inline bool includeRP(
		const compVec &l, const compVec &r,
		const compVec &p)
{
	if (dblcmp(min(l.x(), r.x()), p.x()) > 0)
		return false;
	if (dblcmp(p.x(), max(l.x(), r.x())) > 0)
		return false;
	if (dblcmp(min(l.y(), r.y()), p.y()) > 0)
		return false;
	if (dblcmp(p.y(), max(l.y(), r.y())) > 0)
		return false;
	return true;
}

inline bool hasIstRR(
		compVec a, compVec b,
		compVec c, compVec d)
{
	if (a.x() > b.x())
		swap(a.x(), b.x());
	if (a.y() > b.y())
		swap(a.y(), b.y());
	if (c.x() > d.x())
		swap(c.x(), d.x());
	if (c.y() > d.y())
		swap(c.y(), d.y());

	if (dblcmp(max(a.x(), c.x()), min(b.x(), d.x())) > 0)
		return false;
	if (dblcmp(max(a.y(), c.y()), min(b.y(), d.y())) > 0)
		return false;
	return true;
}

inline bool hasIstSS(
		const segment &s, const segment &t)
{
	if (!hasIstRR(s.a, s.b, t.a, t.b))
		return false;
	if (sgn(cross(s.a, s.b, t.a)) * sgn(cross(s.a, s.b, t.b)) > 0)
		return false;
	if (sgn(cross(t.a, t.b, s.a)) * sgn(cross(t.a, t.b, s.b)) > 0)
		return false;
	return true;
}
inline compVec getIstSS(
		const segment &s, const segment &t)
{
	double s1 = cross(t.a, s.a, t.b);
	double s2 = cross(t.b, s.b, t.a);

	if (sgn(s1 + s2) == 0)
		return compVec(HUGE_VAL, HUGE_VAL);
	return s.a + (s.b - s.a) * s1 / (s1 + s2);
}

int main()
{
	double w, h, alpha;

	cin >> w >> h >> alpha;

	if (alpha == 90.0)
	{
		printf("%lf\n", min(w, h) * min(w, h));
		return 0;
	}

	alpha = alpha / 180 * PI;

	if (alpha > PI / 2)
		alpha = PI - alpha;

	compVec a = compVec(-w / 2.0,  h / 2.0);
	compVec b = compVec(-w / 2.0, -h / 2.0);
	compVec c = compVec( w / 2.0, -h / 2.0);
	compVec d = compVec( w / 2.0,  h / 2.0);

	compVec ra = compVec(-w / 2.0,  h / 2.0) * exp(compVec(0.0, alpha));
	compVec rb = compVec(-w / 2.0, -h / 2.0) * exp(compVec(0.0, alpha));
	compVec rc = compVec( w / 2.0, -h / 2.0) * exp(compVec(0.0, alpha));
	compVec rd = compVec( w / 2.0,  h / 2.0) * exp(compVec(0.0, alpha));

	int nSeqX = 0;
	static double seqX[1000];

	seqX[nSeqX++] = -w / 2.0;
	seqX[nSeqX++] =  w / 2.0;
	seqX[nSeqX++] = ra.x();
	seqX[nSeqX++] = rb.x();
	seqX[nSeqX++] = rc.x();
	seqX[nSeqX++] = rd.x();

	if (hasIstSS(segment(a, b), segment(ra, rb)))
		seqX[nSeqX++] = getIstSS(segment(a, b), segment(ra, rb)).x();
	if (hasIstSS(segment(a, b), segment(rb, rc)))
		seqX[nSeqX++] = getIstSS(segment(a, b), segment(rb, rc)).x();
	if (hasIstSS(segment(a, b), segment(rc, rd)))
		seqX[nSeqX++] = getIstSS(segment(a, b), segment(rc, rd)).x();
	if (hasIstSS(segment(a, b), segment(rd, ra)))
		seqX[nSeqX++] = getIstSS(segment(a, b), segment(rd, ra)).x();

	if (hasIstSS(segment(b, c), segment(ra, rb)))
		seqX[nSeqX++] = getIstSS(segment(b, c), segment(ra, rb)).x();
	if (hasIstSS(segment(b, c), segment(rb, rc)))
		seqX[nSeqX++] = getIstSS(segment(b, c), segment(rb, rc)).x();
	if (hasIstSS(segment(b, c), segment(rc, rd)))
		seqX[nSeqX++] = getIstSS(segment(b, c), segment(rc, rd)).x();
	if (hasIstSS(segment(b, c), segment(rd, ra)))
		seqX[nSeqX++] = getIstSS(segment(b, c), segment(rd, ra)).x();

	if (hasIstSS(segment(c, d), segment(ra, rb)))
		seqX[nSeqX++] = getIstSS(segment(c, d), segment(ra, rb)).x();
	if (hasIstSS(segment(c, d), segment(rb, rc)))
		seqX[nSeqX++] = getIstSS(segment(c, d), segment(rb, rc)).x();
	if (hasIstSS(segment(c, d), segment(rc, rd)))
		seqX[nSeqX++] = getIstSS(segment(c, d), segment(rc, rd)).x();
	if (hasIstSS(segment(c, d), segment(rd, ra)))
		seqX[nSeqX++] = getIstSS(segment(c, d), segment(rd, ra)).x();

	if (hasIstSS(segment(d, a), segment(ra, rb)))
		seqX[nSeqX++] = getIstSS(segment(d, a), segment(ra, rb)).x();
	if (hasIstSS(segment(d, a), segment(rb, rc)))
		seqX[nSeqX++] = getIstSS(segment(d, a), segment(rb, rc)).x();
	if (hasIstSS(segment(d, a), segment(rc, rd)))
		seqX[nSeqX++] = getIstSS(segment(d, a), segment(rc, rd)).x();
	if (hasIstSS(segment(d, a), segment(rd, ra)))
		seqX[nSeqX++] = getIstSS(segment(d, a), segment(rd, ra)).x();

	sort(seqX, seqX + nSeqX);

	int tSeqX = 0;
	for (int i = 0, j = 0; i < nSeqX; i = j)
	{
		while (j < nSeqX && dblcmp(seqX[i], seqX[j]) == 0)
			j++;
		seqX[tSeqX++] = seqX[i];
	}
	nSeqX = tSeqX;

	static double lenY[1000];
	static bool valid[1000];
	for (int i = 0; i < nSeqX; i++)
	{
		double x = seqX[i];
		if (-w / 2.0 <= x && x <= w / 2.0)
		{
			double low = -h / 2.0, high = h / 2.0;
			vector<double> istY;
			compVec p1(x, -1e7), p2(x, 1e7);
			if (hasIstSS(segment(p1, p2), segment(ra, rb)))
				istY.push_back(getIstSS(segment(p1, p2), segment(ra, rb)).y());
			if (hasIstSS(segment(p1, p2), segment(rb, rc)))
				istY.push_back(getIstSS(segment(p1, p2), segment(rb, rc)).y());
			if (hasIstSS(segment(p1, p2), segment(rc, rd)))
				istY.push_back(getIstSS(segment(p1, p2), segment(rc, rd)).y());
			if (hasIstSS(segment(p1, p2), segment(rd, ra)))
				istY.push_back(getIstSS(segment(p1, p2), segment(rd, ra)).y());

			if (istY.empty())
				lenY[i] = 0.0;
			else
			{
				sort(istY.begin(), istY.end());
				relax(low, istY.front());
				tension(high, istY.back());
	
				if (dblcmp(low, high) <= 0)
				{
					lenY[i] = high - low;
					valid[i] = true;
				}
				else
					lenY[i] = 0.0;
			}
		}
		else
			lenY[i] = 0.0;
	}

	double res = 0.0;
	for (int i = 1; i < nSeqX; i++)
	{
		if (valid[i] && valid[i - 1])
			res += (lenY[i] + lenY[i - 1]) * (seqX[i] - seqX[i - 1]) / 2.0;
	}

	printf("%.10lf", res);

	return 0;
}