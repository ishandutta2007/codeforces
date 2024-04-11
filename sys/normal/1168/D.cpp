#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, q, cnt, err, maxi, fa[Maxn], dep[Maxn], opt[Maxn], down[Maxn], head[Maxn], c[Maxn][29], f[Maxn][29];
vector <int> tmp_Ve, G[Maxn];
bool vis[Maxn];
char ch[Maxn];
struct edg
{
	int nxt, to;
} edge[Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void init_dfs(int u)
{
	maxi = max(maxi, dep[u]);
	if (!G[u].size() && dep[u] != maxi)
	{
		while (q--) puts("Fou");
		exit(0);
	}
	if (G[u].size() != 1 || u == 1) vis[u] = true;
	for (vector <int> :: iterator it = G[u].begin(); it != G[u].end(); it++)
		dep[*it] = dep[u] + 1, init_dfs(*it);
}
int tmp_c[29];
void dfs1(int u, int f)
{
	tmp_Ve.push_back(u);
	if (u != 1 && ch[u] != '?') tmp_c[ch[u] - 'a']++;
	if (vis[u])
	{
		for (vector <int> :: iterator it = tmp_Ve.begin(); it != tmp_Ve.end(); it++)
			down[*it] = u;
		tmp_Ve.clear();
		memcpy(c[u], tmp_c, sizeof(tmp_c));
		memset(tmp_c, 0, sizeof(tmp_c));
		if (f) add(f, u);
		f = u;
	}
	for (vector <int> :: iterator it = G[u].begin(); it != G[u].end(); it++)
		dfs1(*it, f);
}
void dfs2(int u)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		fa[to] = u, dfs2(to);
		for (int j = 0; j < 26; j++)
			f[u][j] = max(f[u][j], f[to][j] + c[to][j]);
	}
	int sum = 0;
	for (int i = 0; i < 26; i++)
		sum += f[u][i];
	if (sum > maxi - dep[u]) err++;
}
void work(int u)
{
	if (!u) return ;
	int sum = 0;
	for (int i = 0; i < 26; i++)
		sum += f[u][i];
	if (sum > maxi - dep[u]) err--;
	memset(f[u], 0, sizeof(f[u]));
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		for (int j = 0; j < 26; j++)
			f[u][j] = max(f[u][j], f[to][j] + c[to][j]);
	}
	sum = 0;
	for (int i = 0; i < 26; i++)
		sum += f[u][i];
	if (sum > maxi - dep[u]) err++;
	work(fa[u]);
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		G[x].push_back(i);
		ch[i] = getchar();
		while (!isalpha(ch[i]) && ch[i] != '?') ch[i] = getchar();
	}
	init_dfs(1);
	dfs1(1, 0);
	dfs2(1);
	while (q--)
	{
		int x;
		scanf("%d", &x);
		if (ch[x] != '?') c[down[x]][ch[x] - 'a']--;
		ch[x] = getchar();
		while (!isalpha(ch[x]) && ch[x] != '?') ch[x] = getchar();
		if (ch[x] != '?') c[down[x]][ch[x] - 'a']++;
		work(fa[down[x]]);
		if (err) puts("Fou");
		else
		{
			long long tot = 0;
			int sum = 0;
			for (int i = 0; i < 26; i++)
				sum += f[1][i];
			for (int i = 0; i < 26; i++)
				tot += (maxi - sum + f[1][i]) * (i + 1LL);
			printf("Shi %lld\n", tot);
		}
	}
	return 0;
}