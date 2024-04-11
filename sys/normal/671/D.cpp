#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 300005;
int n, m, ct, cnt, dep[Maxn], rt[Maxn], head[Maxn];
long long ans;
vector <int> Ve[Maxn];
struct line
{
	int x, y, w;
} L[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
struct Node
{
	int lson, rson, val, tag, id;
} node[Maxn];
void pushdown(int root)
{
	node[node[root].lson].val += node[root].tag;
	node[node[root].lson].tag += node[root].tag;
	node[node[root].rson].val += node[root].tag;
	node[node[root].rson].tag += node[root].tag;
	node[root].tag = 0;
}
int merge(int root1, int root2)
{
	if (!root1 || !root2) return root1 + root2;
	pushdown(root1), pushdown(root2);
	if (node[root1].val > node[root2].val) swap(root1, root2);
	node[root1].rson = merge(node[root1].rson, root2);
	if (rand() & 1) swap(node[root1].lson, node[root1].rson);
	return root1;
}
int erase(int root)
{
	return merge(node[root].lson, node[root].rson);
}
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			rt[u] = merge(rt[u], rt[to]);
		}
	}
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
		node[++ct] = (Node){0, 0, L[*it].w, 0, *it}, rt[u] = merge(rt[u], ct);
	while (dep[L[node[rt[u]].id].y] >= dep[u]) rt[u] = erase(rt[u]);
	if (!rt[u] && u != 1)
	{
		puts("-1");
		exit(0);
	}
	if (rt[u]) ans += node[rt[u]].val, node[rt[u]].tag -= node[rt[u]].val, node[rt[u]].val = 0;
}
int main()
{
    srand(time(NULL));
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &L[i].x, &L[i].y, &L[i].w);
		Ve[L[i].x].push_back(i);
	}
	dfs(1, 0);
	printf("%lld", ans);
	return 0;
}