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
const ll INF = 1e15;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int TT, n;
char s[maxn], t[maxn];
ll a[maxn], x;
int T[maxn];
inline void add(int x, int d)
{
	for (; x <= n; x += (x & (-x))) T[x] += d;
}
inline int que(int x)
{
	int res = 0;
	for (; x; x -= (x & (-x))) res += T[x];
	return res;
}
vector<int> buc[30];
ll work(int x)
{
	if(!buc[x].size()) return INF;
	return que(buc[x].back());
}
void solve()
{
	scanf("%d%s%s", &n, s + 1, t + 1);
	for (int i = 0; i < 26; i++) buc[i].clear();
	for (int i = n; i >= 1; i--)
	{
		buc[s[i] - 'a'].push_back(i);
	}
	memset(T, 0, sizeof(T));
	for (int i = 1; i <= n; i++) add(i, 1);
	ll ans = INF, now = 0;
	for (int i = 1; i <= n; i++)
	{
		ll pos = INF;
		for (int j = 0; j < t[i] - 'a'; j++) pos = min(pos, work(j));
		ans = min(ans, now + pos - i);
		if(work(t[i] - 'a') == INF) break;
		now += work(t[i] - 'a') - i;
		add(1, 1);
		add(buc[t[i] - 'a'].back(), -1);
		buc[t[i] - 'a'].pop_back();
//		printf("%lld\n", now);
	}
	if(ans >= (ll)n * n) printf("-1\n");
	else printf("%lld\n", ans);
}
int main()
{
	int TT;
	scanf("%d", &TT);
	while(TT--) solve();
	return 0;
}