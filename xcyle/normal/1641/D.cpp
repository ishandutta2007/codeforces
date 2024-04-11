/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 100005
#define maxm 10
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int val[33], idd[maxn];
int n, m, w[maxn], v[maxn], a[maxn][maxm], b[maxn][maxm];
ll id[maxn][32], tmp[maxn * 33], tot;
inline ll Hash(int t)
{
	//return (ll)t * t;
	return (ll)((ll)t * t % 998244353 + t) * (t ^ 2147483647);
}
int cnt[maxn * 33], cnt2[maxn * 33];
inline bool cmp(int x, int y)
{
	return w[x] < w[y];
}
int main()
{
	n = read(), m = read();
	val[0] = -1;
	for (int i = 1; i < 32; i++) val[i] = (i & 1) ? -val[i >> 1] : val[i >> 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) b[i][j] = a[i][j] = read();
		v[i] = w[i] = read();
		idd[i] = i;
	}
	sort(idd + 1, idd + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) a[i][j] = b[idd[i]][j];
		w[i] = v[idd[i]];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < (1 << m); j++)
		{
			for (int k = 0; k < m; k++)
			{
				if((j >> k) & 1) id[i][j] ^= Hash(a[i][k + 1]);
			}
			tmp[++tot] = id[i][j];
//			printf("hash %d %d %lld\n", i, j, id[i][j]);
		}
	}
	sort(tmp + 1, tmp + tot + 1);
	int len = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j < (1 << m); j++) id[i][j] = lower_bound(tmp + 1, tmp + len + 1, id[i][j]) - tmp;
	ll ans = 2e9 + 1;
	ll tot = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < (1 << m); j++)
		{
			cnt[id[i][j]]++;
		}
	}
	w[n + 1] = 2e9;
	for (int i = 1, j = n; i <= n; i++)
	{
		ll tmp = tot;
		for (int k = 1; k < (1 << m); k++) tot += cnt[id[i][k]] * val[k], cnt2[id[i][k]]++;//, printf("? %d %d %d\n", i, k, cnt[id[i][k]]);
		while(tot != (ll)i * j && j >= 1)
		{
			for (int k = 1; k < (1 << m); k++)
			{
				tot -= val[k] * cnt2[id[j][k]];
				cnt[id[j][k]]--;
			}
			j--;
		}
		ans = min(ans, (ll)w[i] + w[j + 1]);
	}
	if(ans > 2e9) ans = -1;
	printf("%lld\n", ans);
	return 0;
}