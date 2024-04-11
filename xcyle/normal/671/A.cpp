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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
double ax, ay, bx, by, tx, ty, x[maxn], y[maxn], ans;
inline double dist(int id) {return sqrt((tx - x[id]) * (tx - x[id]) + (ty - y[id]) * (ty - y[id]));}
inline double disa(int id) {return dist(id) - sqrt((ax - x[id]) * (ax - x[id]) + (ay - y[id]) * (ay - y[id]));}
inline double disb(int id) {return dist(id) - sqrt((bx - x[id]) * (bx - x[id]) + (by - y[id]) * (by - y[id]));}
inline double work(double A, double B) {return max(A + B, max(A, B));}
int main()
{
	ax = read(), ay = read(), bx = read(), by = read(), tx = read(), ty = read();
	n = read();
	ru(i, 1, n) x[i] = read(), y[i] = read(), ans += dist(i) * 2;
	x[0] = tx, y[0] = ty;
	int mna[2] = {0, 0}, mnb[2] = {0, 0};
	ru(i, 1, n) 
	{
		if(disa(i) > disa(mna[0])) mna[1] = mna[0], mna[0] = i;
		else if(disa(i) > disa(mna[1])) mna[1] = i;
		if(disb(i) > disb(mnb[0])) mnb[1] = mnb[0], mnb[0] = i;
		else if(disb(i) > disb(mnb[1])) mnb[1] = i;
	}
	if(mna[0] != mnb[0]) ans -= work(disa(mna[0]), disb(mnb[0]));
	else ans -= max(work(disa(mna[0]), disb(mnb[1])), work(disa(mna[1]), disb(mnb[0])));
	printf("%.10f", ans);
	return 0;
}