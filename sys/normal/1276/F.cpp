#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 300005;
string str;
int n, ct, las, cnt, tree_ct, dfn_cnt, p[Maxn], dep[Maxn], id[Maxn], dfn[Maxn], len[Maxn], fa[Maxn], rt[Maxn], pos[Maxn], head[Maxn], anc[Maxn][20];
long long ans = 2, f[Maxn];
vector <int> G[Maxn];
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
	int trans[26], link, len;
	void clear(void)
	{
		memset(trans, 0, sizeof(trans));
		link = len = 0;
	}
} node[2 * Maxn];
void insert(int x, int id, bool type = false)
{
	int cur = ++ct, tmp = las;
	node[cur].clear();
	if (id != -1) rt[cur] = ++tree_ct;
	las = cur;
	node[cur].len = node[tmp].len + 1;
	for (; tmp && !node[tmp].trans[x]; tmp = node[tmp].link)
		node[tmp].trans[x] = cur;
	if (!tmp)
		node[cur].link = 1;
	else
	{
		int q = node[tmp].trans[x];
		if (node[tmp].len + 1 == node[q].len)
			node[cur].link = q;
		else
		{
			int clone = ++ct;
			node[clone] = node[q];
			if (id != -1) rt[clone] = ++tree_ct;
			node[clone].len = node[tmp].len + 1;
			for (; tmp && node[tmp].trans[x] == q; tmp = node[tmp].link)
				node[tmp].trans[x] = clone;
			node[q].link = node[cur].link = clone;
		}
	}
	if (!type && id != -1 && id + 2 < n) pos[cur] = id;
	if (type) p[id] = cur;
}
struct Tree
{
	int lson, rson, mini, maxi;
	long long sum;
} tree[40 * Maxn];
void insert(int root, int lt, int rt, int pos)
{
	tree[root].mini = tree[root].maxi = pos, tree[root].sum = node[id[pos]].len;
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			tree[root].rson = ++tree_ct;
			insert(tree[root].rson, mid, rt, pos);
		}
		else
		{
			tree[root].lson = ++tree_ct;
			insert(tree[root].lson, lt, mid, pos);
		}
	}
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
int merge(int root1, int root2)
{
	if (!root1 || !root2) return root1 + root2;
	int new_node = ++tree_ct;
	tree[new_node] = (Tree){merge(tree[root1].lson, tree[root2].lson), merge(tree[root1].rson, tree[root2].rson)};
	tree[new_node].mini = min(tree[root1].mini, tree[root2].mini);
	tree[new_node].maxi = max(tree[root1].maxi, tree[root2].maxi);
	tree[new_node].sum = tree[tree[new_node].lson].sum + tree[tree[new_node].rson].sum;
	if (tree[tree[new_node].lson].maxi && tree[tree[new_node].rson].mini != 0x3f3f3f3f)
		tree[new_node].sum -= node[lca(id[tree[tree[new_node].lson].maxi], id[tree[tree[new_node].rson].mini])].len;
	return new_node;
}
void cal(string s, bool type = false)
{
	ct = las = 1, node[1].clear();
	for (int i = 0; i < (int) s.size(); i++)
		insert(s[i] - 'a', type ? i : -1);
	for (int i = 2; i <= ct; i++)
		ans += node[i].len - node[node[i].link].len;
}
void init_dfs(int u, int fa)
{
	anc[u][0] = fa;
	dep[u] = dep[fa] + 1;
	dfn[u] = ++dfn_cnt;
	id[dfn_cnt] = u;
	for (int i = head[u]; i; i = edge[i].nxt)
		init_dfs(edge[i].to, u);
}
void init(void)
{
	for (int j = 1; (1 << j) <= ct; j++)
		for (int i = 1; i <= ct; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
void dfs(int u)
{
	if (pos[u] != -1) insert(rt[u], 1, ct + 1, dfn[p[pos[u] + 2]]);
	for (auto to : G[u])
	{
		dfs(to);
		rt[u] = merge(rt[u], rt[to]);
	}
	if (u != 1) ans += (len[u] - len[fa[u]]) * tree[rt[u]].sum;
}
int main()
{
	tree[0].mini = 0x3f3f3f3f;
	memset(pos, -1, sizeof(pos));
	cin >> str;
	n = str.size();
	cal(str.substr(0, n - 1)), cal(str.substr(1, n - 1)), cal(str, true);
	for (int i = 2; i <= ct; i++) G[node[i].link].push_back(i), len[i] = node[i].len, fa[i] = node[i].link;
	ct = las = 1, node[1].clear();
	for (int i = str.size() - 1; i >= 0; i--)
		insert(str[i] - 'a', i, true);
	for (int i = 2; i <= ct; i++) add(node[i].link, i);
	dep[0] = -1, init_dfs(1, 0), init();
	dfs(1);
	printf("%lld", ans);
	return 0;
}