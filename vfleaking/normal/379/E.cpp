#include <iostream>
#include <cstdio>
#include <complex>
#include <vector>
using namespace std;

const int MaxN = 300;
const int MaxK = 300;

inline int sgn(const double &a)
{
   const double Eps = 1e-7;
   if (a > Eps)
       return 1;
   else if (a < -Eps)
       return -1;
   else
       return 0;
}
inline int dblcmp(const double &a, const double &b)
{
	return sgn(a - b);
}

typedef complex<double> compVec;

inline double cross(const compVec &a, const compVec &b)
{
   return a.real() * b.imag() - a.imag() * b.real();
}
inline double cross(const compVec &a, const compVec &o, const compVec &b)
{
   return (a.real() - o.real()) * (b.imag() - o.imag()) - (a.imag() - o.imag()) * (b.real() - o.real());
}

inline compVec getIst(const compVec &a, const compVec &b, const compVec &c, const compVec &d)
{
	double s1 = cross(c, a, d), s2 = cross(d, b, c);
	return a + (b - a) * s1 / (s1 + s2);
}

double outcome[MaxN + 1];

int n;
compVec lp[MaxN + 1], rp[MaxN + 1];

inline void calc()
{
	vector<compVec> li;

	li.push_back(lp[1]);
	li.push_back(rp[1]);
	outcome[1] += (lp[1].imag() + rp[1].imag()) / 2;

	for (int i = 2; i <= n; i++)
	{
		double lk = rp[i].imag() - lp[i].imag();
		double lb = lp[i].imag() - lk * lp[i].real();

		bool blow = true;
		for (vector<compVec>::iterator it = li.begin(); it != li.end(); it++)
			if (dblcmp(lk * it->real() + lb, it->imag()) >= 0)
				blow = false;
		if (blow)
			continue;

		compVec sp, ep;

		static bool book[MaxN * 2];
		for (int j = 0; j < (int)li.size(); j++)
			book[j] = dblcmp(lk * li[j].real() + lb, li[j].imag()) >= 0;

		vector<compVec> newLi;

		if (book[0])
			sp = lp[i];
		else
		{
			int j = 0;
			while (!book[j])
				newLi.push_back(li[j]), j++;
			sp = getIst(lp[i], rp[i], li[j - 1], li[j]);
		}
		newLi.push_back(sp);

		if (book[(int)li.size() - 1])
		{
			ep = rp[i];
			newLi.push_back(ep);
		}
		else
		{
			int j = (int)li.size() - 1;
			while (!book[j])
				j--;
			ep = getIst(lp[i], rp[i], li[j], li[j + 1]);

			newLi.push_back(ep);
			for (int tj = j + 1; tj < (int)li.size(); tj++)
				newLi.push_back(li[tj]);
		}

		vector<compVec> pol;
		pol.push_back(sp);
		for (int j = 0; j < (int)li.size(); j++)
			if (book[j])
				pol.push_back(li[j]);
		pol.push_back(ep);
		pol.push_back(sp);

		double area = 0;
		for (int j = 0; j + 1 < (int)pol.size(); j++)
			area += cross(pol[j], pol[j + 1]);
		area /= 2;
		outcome[i] += abs(area);

		li = newLi;
	}
}

int main()
{
	int k;
	static int y[MaxN + 1][MaxK + 1];

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			scanf("%d", &y[i][j]);

	for (int j = 0; j < k; j++)
	{
		for (int i = 1; i <= n; i++)
			lp[i] = compVec((double)j, y[i][j]), rp[i] = compVec((double)j + 1, y[i][j + 1]);
		calc();
	}

	for (int i = 1; i <= n; i++)
		printf("%.10lf\n", outcome[i]);

	return 0;
}