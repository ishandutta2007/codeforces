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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int pos[maxn], tot, tag[maxn], k, n, ch[maxn][2], nxt[maxn];
char c[maxn], s[maxn];
void dfs(int x)
{
	if(!x) return;
	dfs(ch[x][0]);
	s[++tot] = c[x], pos[x] = tot;
	dfs(ch[x][1]);
}
void work(int x, int &dep, int nowdep, int ban)
{
	if(!x) return;
	work(ch[x][0], dep, nowdep + 1, ban);
	dep = min(dep, nowdep);
	if(ban && dep < nowdep && nxt[pos[x]] > c[x] - 'a' && nowdep - dep <= k)
	{
		k -= nowdep - dep;
		dep = nowdep;
	}
	if(dep == nowdep) tag[pos[x]] = 1;
	else ban &= (nxt[pos[x]] > c[x] - 'a');
	work(ch[x][1], dep, nowdep + 1, ban);
}
int main()
{
	scanf("%d%d%s", &n, &k, c + 1);
	for (int i = 1; i <= n; i++) scanf("%d%d", &ch[i][0], &ch[i][1]);
	dfs(1);
	int las = -1;
	for (int i = n; i >= 1; i--)
	{
		nxt[i] = las;
		if(i && s[i - 1] != s[i]) las = s[i] - 'a';
	}
	int beg = 0;
	work(1, beg, 1, 1);
	for (int i = 1; i <= n; i++)
	{
		if(tag[i]) printf("%c", s[i]);
		printf("%c", s[i]);
	}
	return 0;
}