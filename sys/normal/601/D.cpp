#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, ct, cnt, ans, tree_ct, w[Maxn], head[Maxn], rt[Maxn];
string str;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
struct Tree
{
	int siz, son[26];
} tree[10 * Maxn];
int merge(int x, int y)
{
	if (!x || !y) return x + y;
	int new_node = ++tree_ct;
	tree[tree_ct].siz = 1;
	for (int i = 0; i < 26; i++)
		tree[new_node].son[i] = merge(tree[x].son[i], tree[y].son[i]), tree[new_node].siz += tree[tree[new_node].son[i]].siz;
	return new_node;
}
void dfs(int u, int fa)
{
	int tmp_rt[27];
	memset(tmp_rt, 0, sizeof(tmp_rt));
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			tmp_rt[str[to - 1] - 'a'] = merge(tmp_rt[str[to - 1] - 'a'], rt[to]);
		}
	}
	tree[rt[u] = ++tree_ct].siz = 1;
	for (int i = 0; i < 26; i++)
		tree[rt[u]].son[i] = tmp_rt[i], tree[rt[u]].siz += tree[tmp_rt[i]].siz;
	if (tree[rt[u]].siz + w[u] == ans) ct++;
	else if (tree[rt[u]].siz + w[u] > ans)
		ans = tree[rt[u]].siz + w[u], ct = 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	cin >> str;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	printf("%d\n%d", ans, ct);
	return 0;
}