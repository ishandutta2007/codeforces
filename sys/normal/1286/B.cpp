#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
int s, n, cnt, C, ct, head[Maxn], siz[Maxn], p[Maxn], c[Maxn], val[Maxn];
vector <int> Ve[Maxn];
map <double, int> Ma;
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		dfs(to), siz[u] += siz[to];
		for (vector <int> :: iterator it = Ve[to].begin(); it != Ve[to].end(); it++)
			Ve[u].push_back(*it);
	}
	if (siz[u] - 1 < c[u])
	{
		puts("NO");
		exit(0);
	}
	if (siz[u] == 1) Ve[u].push_back(u);
	else
	{
		if (Ve[u].size() == c[u]) Ve[u].push_back(u);
		else
		{
			vector <int> tmp = Ve[u];
			Ve[u].clear();
			for (int i = 0; i < c[u]; i++)
				Ve[u].push_back(tmp[i]);
			Ve[u].push_back(u);
			for (int i = c[u]; i < tmp.size(); i++)
				Ve[u].push_back(tmp[i]);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &p[i], &c[i]);
		if (!p[i]) s = i;
		else add(p[i], i);
	}
	dfs(s);
	for (vector <int> :: iterator it = Ve[s].begin(); it != Ve[s].end(); it++)
		val[*it] = ++C;
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d ", val[i]);
	return 0;
}