#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, m, A, B, s, t, p, q;
long long dis[Maxn];
bool vis[Maxn];
priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > Pr;
vector <pair <int, int> > G[Maxn];
string str[Maxn];
void add(int u, int v, int w, bool type = false)
{
	if (type) swap(u, v);
	G[u].push_back(make_pair(v, w));
}
void dijkstra(void)
{
	Pr.push(make_pair(0, s));
	memset(dis, 0x3f, sizeof(long long[t + 1]));
	dis[s] = 0;
	while (!Pr.empty())
	{
		int u = Pr.top().second;
		Pr.pop();
		if (vis[u]) continue;
		vis[u] = true;
		int v, w;
		for (auto _ : G[u])
			if (dis[v = _.first] > dis[u] + (w = _.second))
				dis[v] = dis[u] + w, Pr.push(make_pair(dis[v], v));
	}
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &p, &q);
	s = n * m, t = s + 1;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if ((i + j) & 1)
			{
				if (j) add(i * m + j, i * m + j - 1, 0);
				if (j != m - 1) add(i * m + j, i * m + j + 1, 0);
				if (i) add(i * m + j, (i - 1) * m + j, 0);
				if (i != n - 1) add(i * m + j, (i + 1) * m + j, 0);
			}
			if (str[i][j] == '.')
			{
				if ((i + j) & 1) add(s, i * m + j, 0);
				else add(i * m + j, t, 0);
			}
			if (str[i][j] == 'L')
			{
				if (j + 2 < m) add(i * m + j, i * m + j + 2, q, (i + j) & 1);
				if (i) add(i * m + j, (i - 1) * m + j + 1, p, (i + j) & 1);
				if (i != n - 1) add(i * m + j, (i + 1) * m + j + 1, p, (i + j) & 1);
			}
			if (str[i][j] == 'R')
			{
				if (j >= 2) add(i * m + j, i * m + j - 2, q, (i + j) & 1);
				if (i) add(i * m + j, (i - 1) * m + j - 1, p, (i + j) & 1);
				if (i != n - 1) add(i * m + j, (i + 1) * m + j - 1, p, (i + j) & 1);
			}
			if (str[i][j] == 'U')
			{
				if (i <= n - 3) add(i * m + j, (i + 2) * m + j, q, (i + j) & 1);
				if (j) add(i * m + j, (i + 1) * m + j - 1, p, (i + j) & 1);
				if (j != m - 1) add(i * m + j, (i + 1) * m + j + 1, p, (i + j) & 1);
			}
			if (str[i][j] == 'D')
			{
				if (i >= 2) add(i * m + j, (i - 2) * m + j, q, (i + j) & 1);
				if (j) add(i * m + j, (i - 1) * m + j - 1, p, (i + j) & 1);
				if (j != m - 1) add(i * m + j, (i - 1) * m + j + 1, p, (i + j) & 1);
			}
		}
	dijkstra();
	printf("%lld\n", dis[t] >= 1e18 ? -1 : dis[t]);
	return 0;
}