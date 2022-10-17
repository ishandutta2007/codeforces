/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define double long double
using namespace std;
const double eps = 1e-9;
const double INF = 1e9;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
double l, v1, v2;
int check(double t)
{
	double T = l - v1 * t;
	T = T / (v2 - v1) + T / (v2 + v1); //printf("%.5Lf %.5Lf ", t, T);
	int res = (int)(t / T); //printf("%.5f ", res);
	double pos = l - res * T * v1;
	double rem = t - res * T;
	res += (pos <= rem * v2);// printf("%d\n", res);
	return res;
}
int main()
{
	n = read(), l = read(), v1 = read(), v2 = read(), k = read();
//	check(5); return 0;
	double lans = 0, rans = l / v1, mans;
	while(rans - lans >= eps)
	{
		mans = (lans + rans) / 2.0;
		if((ll)check(mans) * k >= n) rans = mans;
		else lans = mans + eps;
	}
	printf("%.10Lf\n", lans);
	return 0;
}