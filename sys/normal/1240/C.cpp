#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, k, ct, cnt, T, head[Maxn];
long long f[Maxn][2];
struct edg
{
	int nxt, to, w;
}edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	vector <long long> Ve;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{ 
			dfs(to, u);
			Ve.push_back(f[to][0] - f[to][1] - edge[i].w);
			f[u][0] += f[to][1] + edge[i].w;
			f[u][1] += f[to][1] + edge[i].w;
		}
	}
	sort(Ve.begin(), Ve.end(), greater <long long> ());
	int siz = Ve.size();
	for (int i = 0; i < siz && (i < siz - k || Ve[i] >= 0); i++)
		f[u][0] += Ve[i];
	for (int i = 0; i < siz && (i < siz - k + 1 || Ve[i] >= 0); i++)
		f[u][1] += Ve[i];
	Ve.clear();
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		cnt = 0;
		memset(head, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			f[i][0] = f[i][1] = 0;
		for (int i = 1; i < n; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			add(x, y, w);
			add(y, x, w);
		}
		dfs(1, 0);
		printf("%lld\n", f[1][0]);
	}
	return 0;
}