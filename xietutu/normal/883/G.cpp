#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

struct re{
	int id, tp, v;
};

int n, m, S, Ans2, Ans1, Ans, Tp[600001], tp, x, y;
int vis[600001];

char Anst1[600001], Anst2[600001];

vector <pii> G;
vector <int> son[600001];
vector <re> es[600001];

void dfs(int u)
{
	vis[u] = 1; ++ Ans;
	for (auto v : son[u])
		if (!vis[v]) dfs(v);
	for (auto x : es[u])
		if (!vis[x.v])
		{
			Tp[x.id] = x.tp;
			dfs(x.v);
		}
}

int main()
{
	scanf("%d%d%d", &n, &m, &S);
	for (int i = 1; i <= m; ++ i)
	{
		scanf("%d%d%d", &tp, &x, &y);
		if (tp == 2) G.push_back(pii(x, y));
		else son[x].push_back(y);
	}
	Ans = 0; dfs(S);
	Ans2 = Ans;
	for (int i = 0; i < (int)G.size(); ++ i)
	{
		if (vis[G[i].first] && !vis[G[i].second]) Anst2[i] = '-';
		else if (!vis[G[i].first] && vis[G[i].second]) Anst2[i] = '+';
		else Anst2[i] = '-';
	}
	
	for (int i = 0; i < (int)G.size(); ++ i)
	{
		es[G[i].first].push_back((re){i, 0, G[i].second});
		es[G[i].second].push_back((re){i, 1, G[i].first});
	}
	for (int i = 1; i <= n; ++ i) vis[i] = 0;
	Ans = 0; dfs(S);
	Ans1 = Ans;
	
	printf("%d\n", Ans1);
	for (int i = 0; i < (int)G.size(); ++ i)
		printf("%c", Tp[i] ? '-' : '+');
	printf("\n");
	
	printf("%d\n", Ans2);
	printf("%s\n", Anst2);
	return 0;
}