#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 300005;
int n, m, k, ct, cnt, dfn_cnt, tree_ct, time_now, top, sum2[Maxn], siz[Maxn], node[Maxn], dep[Maxn], head[Maxn], sta[Maxn], dfn[Maxn], Time[Maxn], s[Maxn], t[Maxn], h1[Maxn], h2[Maxn], rt[Maxn], sum1[Maxn], vt_anc[Maxn][20], anc[Maxn][20];
vector <int> Vt, E[Maxn], Ve[Maxn], V[Maxn];
long long ans;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs1(int u, int fa)
{
	siz[u] = 1;
	anc[u][0] = fa;
	dep[u] = dep[fa] + 1;
	dfn[u] = ++dfn_cnt;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) dfs1(to, u), siz[u] += siz[to];
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
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
int get_dis(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
struct Tree
{
	int lson, rson, cnt;
} tree[60 * Maxn];
void insert(int root, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
		tree[root].cnt++;
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			if (!tree[root].rson)
			{
				tree[root].rson = ++tree_ct;
				tree[tree[root].rson] = (Tree){0, 0, 0};
			}
			insert(tree[root].rson, mid, rt, pos);
		}
		else
		{
			if (!tree[root].lson)
			{
				tree[root].lson = ++tree_ct;
				tree[tree[root].lson] = (Tree){0, 0, 0};
			}
			insert(tree[root].lson, lt, mid, pos);
		}
		tree[root].cnt = tree[tree[root].lson].cnt + tree[tree[root].rson].cnt;
	}
}
int merge(int root1, int root2)
{
	if (!root1 || !root2) return root1 + root2;
	int new_node = ++tree_ct;
	tree[new_node] = (Tree){merge(tree[root1].lson, tree[root2].lson), merge(tree[root1].rson, tree[root2].rson)};
	tree[new_node].cnt = tree[root1].cnt + tree[root2].cnt;
	return new_node;
}
int ask(int root, int L, int R, int lt, int rt)
{
	if (!root) return 0;
	if (L == lt && R == rt) return tree[root].cnt;
	else
	{
		int mid = (L + R) >> 1;
		if (lt >= mid) return ask(tree[root].rson, mid, R, lt, rt);
		else if (rt <= mid) return ask(tree[root].lson, L, mid, lt, rt);
		else return ask(tree[root].lson, L, mid, lt, mid) + ask(tree[root].rson, mid, R, mid, rt);
	}
}
void vt_build(int u)
{
	time_now++;
	tree_ct = ct = 0;
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
		node[++ct] = s[*it], node[++ct] = t[*it];
	sort(node + 1, node + 1 + ct, [](int x, int y){return dfn[x] < dfn[y];});
	ct = unique(node + 1, node + 1 + ct) - node - 1;
	top = 0;
	if (node[1] != u) E[u].clear(), rt[u] = ++tree_ct, tree[rt[u]] = (Tree){0, 0, 0}, V[u].clear(), Time[u] = time_now, sta[++top] = u;
	for (int i = 1; i <= ct; i++)
		E[node[i]].clear(), rt[node[i]] = ++tree_ct, tree[rt[node[i]]] = (Tree){0, 0, 0}, V[node[i]].clear(), Time[node[i]] = time_now;
	for (int i = 1; i <= ct; i++)
	{
		if (!top)
		{
			sta[++top] = node[i];
			continue;
		}
		int l = lca(sta[top], node[i]);
		if (Time[l] != time_now) Time[l] = time_now, rt[l] = ++tree_ct, tree[rt[l]] = (Tree){0, 0, 0}, V[l].clear(), E[l].clear();
		while (top > 1 && dep[sta[top - 1]] > dep[l]) E[sta[top - 1]].push_back(sta[top]), top--;
		if (dep[l] < dep[sta[top]]) E[l].push_back(sta[top]), top--;
		if (!top || sta[top] != l) sta[++top] = l;
		sta[++top] = node[i];
	}
	while (top > 1) E[sta[top - 1]].push_back(sta[top]), top--;
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
		insert(rt[s[*it]], 1, n + 1, dfn[t[*it]]), V[s[*it]].push_back(*it);
}
void vt_dfs1(int u)
{
	Vt.push_back(u);
	for (vector <int> :: iterator it = E[u].begin(); it != E[u].end(); it++)
	{
		vt_anc[*it][0] = u;
		vt_dfs1(*it);
	}
}
void vt_init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (vector <int> :: iterator it = Vt.begin(); it != Vt.end(); it++)
			vt_anc[*it][j] = vt_anc[vt_anc[*it][j - 1]][j - 1];
}
int jump1(int u, int dis)
{
	if (dis < 0) return 0;
	int v = u;
	for (int i = 19; i >= 0; i--)
		if (dep[u] - dep[vt_anc[v][i]] <= dis && vt_anc[v][i]) v = vt_anc[v][i];
	return v;
}
int jump2(int u, int dis)
{
	if (dis < 0) return 0;
	int v = u;
	for (int i = 19; i >= 0; i--)
		if (dep[u] - dep[anc[v][i]] <= dis && anc[v][i]) v = anc[v][i];
	return v;
}
void cal1(int l, int u, int v)
{
	for (vector <int> :: iterator it = V[v].begin(); it != V[v].end(); it++)
	{
		int now = jump1(t[*it], get_dis(l, t[*it]) - k);
		if (now)
			ans += ask(rt[u], 1, n + 1, dfn[now], dfn[now] + siz[now]);
	}
}
void cal2(int u)
{
	long long tmp_ans = 0;
	for (vector <int> :: iterator it = V[u].begin(); it != V[u].end(); it++)
	{
		int now = jump1(t[*it], get_dis(u, t[*it]) - k);
		if (now)
			tmp_ans += ask(rt[u], 1, n + 1, dfn[now], dfn[now] + siz[now]) - 1;
	}
	ans += tmp_ans / 2;
}
void vt_dfs2(int u)
{
	cal2(u);
	for (vector <int> :: iterator it1 = E[u].begin(); it1 != E[u].end(); it1++)
	{
		vt_dfs2(*it1);
		if (V[u].size() > V[*it1].size()) cal1(u, u, *it1);
		else cal1(u, *it1, u), V[u].swap(V[*it1]);
		for (vector <int> :: iterator it2 = V[*it1].begin(); it2 != V[*it1].end(); it2++)
			V[u].push_back(*it2);
		rt[u] = merge(rt[u], rt[*it1]);
	}
}
void work1(int u)
{
	vt_build(u);
	Vt.clear();
	vt_dfs1(u);
	vt_init();
	vt_dfs2(u);
}
int lowbit(int x)
{
	return x & -x;
}
void bit_add1(int x, int y)
{
	if (!x) return ;
	for (int i = x; i <= n; i += lowbit(i))
		sum1[i] += y;
}
int bit_ask1(int x)
{
	int tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		tmp += sum1[i];
	return tmp;
}
void bit_add2(int x, int y)
{
	if (!x) return ;
	for (int i = x; i <= n; i += lowbit(i))
		sum2[i] += y;
}
int bit_ask2(int x)
{
	int tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		tmp += sum2[i];
	return tmp;
}
void work2(int u)
{
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
	{
		ans += bit_ask2(dfn[s[*it]]);
		int now = jump2(t[*it], get_dis(t[*it], u) - k);
		if (now)
			bit_add2(dfn[now], 1), bit_add2(dfn[now] + siz[now], -1);
	}
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
	{
		int now = jump2(t[*it], get_dis(t[*it], u) - k);
		if (now)
			bit_add2(dfn[now], -1), bit_add2(dfn[now] + siz[now], 1);
	}
}
void dfs2(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dfs2(to, u);
	}
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
		ans += bit_ask1(dfn[s[*it]]), ans += bit_ask1(dfn[t[*it]]);
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
	{
		bit_add1(dfn[h1[*it]], 1), bit_add1(dfn[h1[*it]] + siz[h1[*it]], -1);
		bit_add1(dfn[h2[*it]], 1), bit_add1(dfn[h2[*it]] + siz[h2[*it]], -1);
	}
	work1(u);
	work2(u);
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs1(1, 0);
	init();
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &s[i], &t[i]);
		if (dfn[s[i]] > dfn[t[i]]) swap(s[i], t[i]);
		if (get_dis(s[i], t[i]) < k) m--, i--;
	}
	for (int i = 1; i <= m; i++)
	{
		int l = lca(s[i], t[i]);
		Ve[l].push_back(i);
		h1[i] = s[i], h2[i] = t[i];
		for (int j = 19; j >= 0; j--)
			if (((dep[s[i]] - dep[l]) - k) & (1 << j)) h1[i] = anc[h1[i]][j];
		for (int j = 19; j >= 0; j--)
			if (((dep[t[i]] - dep[l]) - k) & (1 << j)) h2[i] = anc[h2[i]][j];
	}
	for (int i = 1; i <= n; i++)
		sort(Ve[i].begin(), Ve[i].end(), [](int x, int y){return dfn[s[x]] < dfn[s[y]];});
	dfs2(1, 0);
	printf("%lld", ans);
	return 0;
}