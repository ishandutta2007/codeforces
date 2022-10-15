/***
4 6
1 2
2 3
3 4
1 2
1 2
2 2
1 3
2 2
2 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[1000007];
int par[1000007];
int mini[1000007];
bool visit[1000007];
bool black[1000007];
void dfs(int x, int p)
{
	par[x] = p;
	mini[x] = x;
	mini[x] = min(mini[p], mini[x]);
	for (int i : adj[x])
		if (i != p)
		{
			dfs(i, x);
		}
}
int ans = 1000000;
void dfs2(int a)
{
	ans = min(ans, a);
	if (!visit[par[a]])
	{
		visit[par[a]] = true;
		dfs2(par[a]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	fill_n(visit, n + 1, false);
	fill_n(black, n + 1, false);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int last = 0;
	int z;
	cin >> z >> z;
	int x = (z + last) % n + 1;
	dfs(x, x);
	black[x] = true;
	for (int i = 1; i < q; i++)
	{
		int t, z;
		cin >> t >> z;
		x = (z + last) % n + 1;
		if (t == 1)
		{
			if (!black[x])
			{
				ans = min(ans, x);
				dfs2(x);
				black[x] = true;
			}
		}
		if (t == 2)
		{
			int a = min(mini[x], ans);
			if (black[x])
				a = min(a, x);
			last = a;
			cout << a << "\n";
		}
	}
}