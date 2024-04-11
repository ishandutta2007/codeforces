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
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll a[maxn], b[maxn];
inline ll low(ll x, int k) {return x & ((1ll << k) - 1);}
inline int val(ll x, int k) {return (x >> k) & 1;}
int i;
inline bool cmp(ll x, ll y)
{
	return low(x, i) > low(y, i);
}
int f[65][maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 0; i < 65; i++) for (int j = 0; j <= n + 1; j++) f[i][j] = INF;
	f[0][0] = 0;
	for (i = 0; i <= 62; i++)
	{
		sort(a + 1, a + n + 1, cmp);
		int pre[2] = {0, 0}, suf[2] = {0, 0};
		for (int j = 1; j <= n; j++) suf[val(a[j], i)]++;
		for (int j = 0; j <= n; j++)
		{
			f[i + 1][pre[1]] = min(f[i + 1][pre[1]], f[i][j] + pre[1] + suf[0]);
			f[i + 1][j + suf[1]] = min(f[i + 1][j + suf[1]], f[i][j] + pre[0] + suf[1]);
			if(j == n) continue;
			suf[val(a[j + 1], i)]--;
			pre[val(a[j + 1], i)]++;
		}
	}
	printf("%d", f[63][0]);
	return 0;
}