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
int m, n[maxn];
vector<int> a[maxn], ans[maxn];
set<pair<int, int> > col[maxn], row[maxn];
int b[maxn], cnt;
int vis[maxn];
int sta[maxn], top;
void work(int x, int y, int colr)
{
//	printf("%d %d %d\n", x, y, colr);
	row[x].erase(make_pair(x, y));
	col[a[x][y]].erase(make_pair(x, y));
	ans[x][y] = colr;
	if(colr == 1)
	{
		vis[x] = 1;
		sta[++top] = x;
		pair<int, int> nxt = *(col[a[x][y]].begin());
		work(nxt.first, nxt.second, 2);
		vis[x] = 0;
	}
	else
	{
		if(vis[x])
		{
			while(sta[top] != x) top--;
			top--;
			return;
		}
		int now = top;
		while(1)
		{
			pair<int, int> nxt = *row[x].begin();
			work(nxt.first, nxt.second, 1);
			if(top < now) break;
		}
	}
}
int main()
{
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &n[i]);
		for (int j = 1; j <= n[i]; j++)
		{
			int x = read();
			a[i].push_back(x);
			b[++cnt] = x;
			ans[i].push_back(0);
		}
	}
	sort(b + 1, b + cnt + 1);
	int len = unique(b + 1, b + cnt + 1) - b - 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			int &x = a[i][j];
			x = lower_bound(b + 1, b + len + 1, x) - b;
			row[i].insert(make_pair(i, j));
			col[x].insert(make_pair(i, j));
		}
	}
	for (int i = 1; i <= len; i++)
	{
		if(col[i].size() % 2 != 0)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			if(!ans[i][j])
			{
				work(i, j, 1);
			}
			if(ans[i][j] == 1) printf("L");
			else printf("R");
		}
		printf("\n");
	}
	return 0;
}