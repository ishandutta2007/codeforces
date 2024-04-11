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
#define maxn 1000005
using namespace std;
const ll INF = 1e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
double p[maxn], r[maxn];
struct cmp
{
	inline bool operator ()(int x, int y)
	{
		return (1.0 - r[x] * (1.0 - p[x])) / (1.0 - r[x]) < (1.0 - r[y] * (1.0 - p[y])) / (1.0 - r[y]);
	}
};
priority_queue<int, vector<int>, cmp> q;
int main()
{
	n = read();
	ru(i, 1, n) r[i] = 1.0, p[i] = read() / 100.0, q.push(i);
	double ans = 0;
	ru(i, 1, 200000)
	{
		double s = 1.0;
		ru(j, 1, n) s *= 1.0 - r[j];
		ans += 1.0 - s;
		int x = q.top(); q.pop();
		r[x] *= (1.0 - p[x]), q.push(x);
	}
	printf("%.10f", ans);
	return 0;
}