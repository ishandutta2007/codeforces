#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1)
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
int Tc;
int n, k[maxn], d[maxn];
vector<int> G[maxn];
int vis[maxn], dis[maxn];
priority_queue<int> q[2];
void solve()
{
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= n; i++)
	{
		vis[i] = dis[i] = 0;
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++)
		{
			int x = read();
			G[x].push_back(i);
		}
		if(k[i] == 0) q[0].push(-i);
	}
	int ans = 0;
	while(!q[0].empty())
	{
		ans++;
		while(!q[0].empty())
		{
			int u = -q[0].top();
			q[0].pop();
			vis[u] = 1;
			for (register int i = 0; i < G[u].size(); i++)
			{
				int V = G[u][i];
				if(vis[V]) continue;
				k[V]--;
				if(k[V] == 0)
				{
					if(V > u) q[0].push(-V);
					else q[1].push(-V);
				} 
			}
		}
		while(!q[1].empty())
		{
			q[0].push(q[1].top());
			q[1].pop();
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d\n", vis[i]);
	for (int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			printf("-1\n");
			return;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	Tc = read();
	while(Tc--) solve();
	return 0;
}