#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, f[Maxn], deg[Maxn];
bool vis[Maxn];
vector <int> G[Maxn], iG[Maxn];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > Pr;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), iG[y].push_back(x);
		deg[x]++;
	}
	memset(f, 0x3f, sizeof(int[n]));
	Pr.push(make_pair(0, n));
	while (!Pr.empty())
	{
		int v = Pr.top().second;
		Pr.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (auto u : iG[v])
			deg[u]--, f[u] = min(f[u], f[v] + 1 + deg[u]), Pr.push(make_pair(f[u], u));
	}
	printf("%d", f[1]);
	return 0;
}