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
#define maxn 600005
#define int long long
using namespace std;
const int INF = 2e9;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, x[maxn], p[maxn];
ll sum[maxn], cnt[maxn];
ll vpre[maxn], vsuf[maxn];
int tmp[maxn], tot;
void solve()
{
	n = read(), m = read(); tot = 0;
	ru(i, 1, n)
	{
		x[i] = read(), p[i] = read();
		tmp[++tot] = x[i], tmp[++tot] = x[i] - p[i], tmp[++tot] = x[i] + p[i] + 1;
	}
	sort(tmp + 1, tmp + tot + 1);
	tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
	ru(i, 0, tot + 1) sum[i] = cnt[i] = 0, vpre[i] = vsuf[i] = -INF;
	ru(i, 1, n)
	{
		int l = lower_bound(tmp + 1, tmp + tot + 1, x[i] - p[i]) - tmp;
		int pos = lower_bound(tmp + 1, tmp + tot + 1, x[i]) - tmp;
		int r = lower_bound(tmp + 1, tmp + tot + 1, x[i] + p[i] + 1) - tmp;
//		printf("%d %d %d\n", tmp[l], tmp[pos], tmp[r]);
		sum[l] += p[i] - x[i], cnt[l]++;
		sum[pos] -= p[i] - x[i], cnt[pos]--;
		sum[pos] += p[i] + x[i], cnt[pos]--;
		sum[r] -= p[i] + x[i], cnt[r]++;
	}
	tot--;
	ru(i, 1, tot) sum[i] += sum[i - 1], cnt[i] += cnt[i - 1];
	ru(i, 1, tot)
	{
		ll s = sum[i], c = cnt[i];
		ll res = s + max(tmp[i] * c, (tmp[i + 1] - 1) * c);
//		printf("%d %d %lld %lld\n", tmp[i], tmp[i + 1], s, c);
		if(res > m)
		{
			res = s + max(tmp[i] * (c - 1), (tmp[i + 1] - 1) * (c - 1));
			vpre[i] = max((ll)-tmp[i], res - m);
			res = s + max(tmp[i] * (c + 1), (tmp[i + 1] - 1) * (c + 1));
			vsuf[i] = max((ll)tmp[i + 1] - 1, res - m);
		}
	}
	ru(i, 1, tot) vpre[i] = max(vpre[i - 1], vpre[i]);
	rd(i, tot, 1) vsuf[i] = max(vsuf[i + 1], vsuf[i]);
	ru(i, 1, n)
	{
		int loc = lower_bound(tmp + 1, tmp + tot + 1, x[i]) - tmp;
//		printf("%lld %lld\n", vpre[loc - 1], vsuf[loc + 1]);
		if(p[i] - x[i] >= vpre[loc - 1] && p[i] + x[i] >= vsuf[loc]) printf("1");
		else printf("0");
	}
	printf("\n");
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}