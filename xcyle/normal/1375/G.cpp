#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
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
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
long long a, b, c, x, y;
void work()
{
	long long ta = a, tb = b, tc = c;
	if(ta > tb) swap(ta, tb);
	if(tb > tc) swap(tb, tc);
	if(ta > tb) swap(ta, tb);
	x = tb - ta, y = tc - tb;
}
int n, cnt[2];
vector<int> G[maxn];
void dfs(int x, int fa, int dep)
{
	cnt[dep]++;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x, dep ^ 1);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x , y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 1, 0);
	printf("%d\n", min(cnt[0], cnt[1]) - 1);
	return 0;
}