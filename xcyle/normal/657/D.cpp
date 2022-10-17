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
#define maxn 150005
using namespace std;
const double eps = 1e-9;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
double T;
struct node
{
	ll p, t, xmn, xmx;
	inline bool operator < (const node &a) const
	{
		return (ll)p * a.t > (ll)a.p * t;
	}
	inline bool operator == (const node &a) const
	{
		return (ll)p * a.t == (ll)a.p * t;
	}
}a[maxn];
inline int check(double c)
{
	double mx = 0;
	ru(i, 1, n)
	{
		int j = i;
		double vmn = a[i].p * (1.0 - c * a[i].xmx / T);
		double vmx = a[i].p * (1.0 - c * a[i].xmn / T);
		while(j <= n && a[j + 1].p == a[j].p)
		{
			j++;
			vmn = min(vmn, a[j].p * (1.0 - c * a[j].xmx / T));
			vmx = max(vmx, a[j].p * (1.0 - c * a[j].xmn / T));
		}
		i = j;
		if(mx > vmn) return 1;
		mx = max(mx, vmx);
	}
	return 0;
}
int main()
{
	n = read();
	ru(i, 1, n) a[i].p = read();
	ru(i, 1, n) a[i].t = read(), T += a[i].t;
	sort(a + 1, a + n + 1);
	ll sum = 0;
	ru(i, 1, n)
	{
		int j = i;
		ll tmp = sum; sum += a[i].t;
		while(j <= n && a[j] == a[j + 1]) sum += a[++j].t;
		ru(k, i, j)
		{
			a[k].xmn = tmp + a[k].t;
			a[k].xmx = sum;
		}
		i = j;
	}
	sort(a + 1, a + n + 1, [](const node &a, const node &b) {return a.p < b.p;});
	double l = 0, r = 1.0, mid;
	while(r - l > eps)
	{
		mid = (l + r + eps) / 2;
		if(!check(mid)) l = mid;
		else r = mid - eps;
	}
	printf("%.9f", l);
	return 0;
}