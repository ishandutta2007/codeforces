#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, cnt, dfn_cnt, head[Maxn], siz[Maxn], dfn[Maxn], deg[Maxn];
string str[Maxn];
long long ans;
struct quest
{
	int lt, rt, val;
};
vector <quest> Q[Maxn];
struct edg
{
	int nxt, to;
} edge[Maxn];
void add(int x, int y)
{
	if (!x) return ;
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
	deg[y]++;
}
void dfs(int u)
{
	siz[u] = 1;
	dfn[u] = ++dfn_cnt;
	for (int i = head[u]; i; i = edge[i].nxt)
		dfs(edge[i].to), siz[u] += siz[edge[i].to];
}
struct Tree
{
	int lt, rt, mini, mini_cnt, tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, rt - lt, 0};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void pushdown(int root)
{
	if (tree[root].tag)
	{
		tree[root << 1].tag += tree[root].tag;
		tree[root << 1 | 1].tag += tree[root].tag;
		tree[root << 1].mini += tree[root].tag;
		tree[root << 1 | 1].mini += tree[root].tag;
		tree[root].tag = 0;
	}
}
void insert(int root, int lt, int rt, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].mini += val, tree[root].tag += val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) insert(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) insert(root << 1, lt, rt, val);
		else insert(root << 1, lt, mid, val), insert(root << 1 | 1, mid, rt, val);
		tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
		tree[root].mini_cnt = (tree[root << 1].mini == tree[root].mini) * tree[root << 1].mini_cnt + (tree[root << 1 | 1].mini == tree[root].mini) * tree[root << 1 | 1].mini_cnt;
	}
}
int id(int x, int y)
{
	if (!(1 <= x && x <= n)) return 0;
	if (!(0 <= y && y < m)) return 0;
	return (x - 1) * m + y + 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		cin >> str[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == 'U') add(id(i + 2, j), id(i, j));
			if (str[i][j] == 'D') add(id(i - 2, j), id(i, j));
			if (str[i][j] == 'L') add(id(i, j + 2), id(i, j));
			if (str[i][j] == 'R') add(id(i, j - 2), id(i, j));
		}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if (!deg[id(i, j)]) dfs(id(i, j));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if ((i + j) & 1)
			{
				int u = id(i, j), v;
				if (str[i][j] == 'U') v = id(i + 1, j);
				if (str[i][j] == 'D') v = id(i - 1, j);
				if (str[i][j] == 'L') v = id(i, j + 1);
				if (str[i][j] == 'R') v = id(i, j - 1);
				Q[dfn[u]].push_back((quest){dfn[v], dfn[v] + siz[v] - 1, 1});
				Q[dfn[u] + siz[u]].push_back((quest){dfn[v], dfn[v] + siz[v] - 1, -1});
			}
	build(1, 1, dfn_cnt + 1);
	for (int i = 1; i <= dfn_cnt; i++)
	{
		for (auto now : Q[i])
			insert(1, now.lt, now.rt + 1, now.val);
		ans += dfn_cnt - tree[1].mini_cnt * !tree[1].mini;
	}
	printf("%lld", ans);
	return 0;
}