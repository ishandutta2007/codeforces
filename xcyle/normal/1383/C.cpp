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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, lk[20][20], t[20];
char a[maxn], b[maxn];
int f[(1 << 20)];
int fa[maxn];
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
	scanf("%d%s%s", &n, a + 1, b + 1);
	for (int i = 0; i < 20; i++) fa[i] = i;
	for (int i = 0; i < 20; i++) t[i] = 0;
	for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++) lk[i][j] = 0;
	for (int i = 1; i <= n; i++) lk[a[i] - 'a'][b[i] - 'a'] = 1;
	int tot = 20;
	for (int i = 1; i <= n; i++)
	{
		t[a[i] - 'a'] |= (1 << (b[i] - 'a'));
		int fA = find(a[i] - 'a'), fB = find(b[i] - 'a');
		if(fA != fB) fa[fA] = fB, tot--;
	}
	for (int i = 0; i < (1 << 20); i++) f[i] = 0;
	for (int i = 0; i < 20; i++) f[(1 << i)] = 1;
	int ans = 2 * 20;
	for (int i = 0; i < (1 << 20); i++)
	{
		if(!f[i]) continue;
		int cnt = 20, tmp = 0;
		for (int j = 0; j < 20; j++) tmp |= (((i >> j) & 1) << j);
		for (int j = 0; j < 20; j++)
		{
			if((i >> j) & 1) continue;
			cnt--;
			if(t[j] & tmp) continue;
			f[i ^ (1 << j)] = 1;
		}
		ans = min(ans, 2 * 20 - cnt - tot);
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}