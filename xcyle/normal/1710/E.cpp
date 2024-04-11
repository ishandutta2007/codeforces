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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, a[maxn], b[maxn], A, B, pa[maxn], pb[maxn];
int check(int t)
{
	pb[0] = n, pa[0] = m;
	ru(i, 1, m)
	{
		pb[i] = pb[i - 1];
		while(pb[i] && a[pb[i]] + b[i] > t) pb[i]--;
	}
	ru(i, 1, n)
	{
		pa[i] = pa[i - 1];
		while(pa[i] && a[i] + b[pa[i]] > t) pa[i]--;
	}
	ll mx = 0, sum = 0; int now = 0;
	ru(i, 1, n) sum += m - pa[i];
	ru(i, 0, n)
	{
		while(now < m && min(i, pb[now + 1]) > min(n - i, n - pb[now + 1]))
		{
			sum += min(i, pb[now + 1]);
			sum -= min(n - i, n - pb[now + 1]);
			now++;
		}
		mx = max(mx, sum);
		sum += min(now, pa[i + 1]);
		sum -= min(m - now, m - pa[i + 1]);
	}
	ll tmp = mx;
	mx = sum = now = 0;
	ru(i, 1, n) sum += m - pa[i]; mx = --sum;
	ru(i, 0, n)
	{
		while(now < m && min(i, pb[now + 1]) > min(n - i, n - pb[now + 1]) - (A > i && B == now + 1))
		{
			sum += min(i, pb[now + 1]);
			sum -= min(n - i, n - pb[now + 1]) - (A > i && B == now + 1);
			now++;
		}
//		printf("%d %d %d %d %d\n", i, now, sum, A, B);
		mx = max(mx, sum);
		sum += min(now, pa[i + 1]);
		sum -= min(m - now, m - pa[i + 1]) - (A == i + 1 && B > now);
	}
//	printf("%d %d %d\n", t, tmp, mx);
	return mx >= tmp;
}
int main()
{
	n = read(), m = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, m) b[i] = read();
	A = a[1], B = b[1];
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
	int l = 1, r = A + B;
	A = lower_bound(a + 1, a + n + 1, A) - a;
	B = lower_bound(b + 1, b + m + 1, B) - b;
	while(l < r) check(mid) ? r = mid : l = mid + 1;
	printf("%d\n", l);
	return 0;
}