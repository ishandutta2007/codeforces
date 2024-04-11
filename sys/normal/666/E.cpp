#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int m, q, las, ct, tree_ct, cnt, ord[2 * Maxn], head[2 * Maxn], l[Maxn], pos[Maxn], anc[2 * Maxn][21];
string str;
struct Tree
{
	int lson, rson, maxi_pos, maxi;
} tree[40 * Maxn];
void insert(int root, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
		tree[root].maxi++, tree[root].maxi_pos = lt;
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			if (!tree[root].rson) tree[root].rson = ++tree_ct;
			insert(tree[root].rson, mid, rt, pos);
		}
		else
		{
			if (!tree[root].lson) tree[root].lson = ++tree_ct;
			insert(tree[root].lson, lt, mid, pos);
		}
		tree[root].maxi = max(tree[tree[root].lson].maxi, tree[tree[root].rson].maxi);
		tree[root].maxi_pos = tree[tree[root].lson].maxi >= tree[tree[root].rson].maxi ? tree[tree[root].lson].maxi_pos : tree[tree[root].rson].maxi_pos;
	}
}
int merge(int root1, int root2)
{
	if (!root1 || !root2) return root1 + root2;
	int new_node = ++tree_ct;
	tree[new_node] = (Tree){merge(tree[root1].lson, tree[root2].lson), merge(tree[root1].rson, tree[root2].rson)};
	if (!tree[new_node].lson && !tree[new_node].rson)
	{
		tree[new_node].maxi = tree[root1].maxi + tree[root2].maxi;
		tree[new_node].maxi_pos = tree[root1].maxi_pos;
	}
	else
	{
		tree[new_node].maxi = max(tree[tree[new_node].lson].maxi, tree[tree[new_node].rson].maxi);
		tree[new_node].maxi_pos = tree[tree[new_node].lson].maxi >= tree[tree[new_node].rson].maxi ? tree[tree[new_node].lson].maxi_pos : tree[tree[new_node].rson].maxi_pos;
	}
	return new_node;
}
pair <int, int> ask(int root, int lt, int rt, int L, int R)
{
	if (!root) return make_pair(0, 0);
	if (lt == L && rt == R) return make_pair(tree[root].maxi_pos, tree[root].maxi);
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return ask(tree[root].rson, mid, rt, L, R);
		else if (R <= mid) return ask(tree[root].lson, lt, mid, L, R);
		else
		{
			pair <int, int> tmp1 = ask(tree[root].lson, lt, mid, L, mid);
			pair <int, int> tmp2 = ask(tree[root].rson, mid, rt, mid, R);
			if (tmp1.second > tmp2.second) return tmp1;
			if (tmp1.second < tmp2.second) return tmp2;
			return tmp1;
		}
	}
}
struct Node
{
	int trans[26], link, len, root;
} node[2 * Maxn];
void SAM_insert(int x, int id)
{
	if (node[las].trans[x])
	{
		if (node[las].len + 1 == node[node[las].trans[x]].len)
		{
			las = node[las].trans[x];
			if (!node[las].root) node[las].root = ++tree_ct;
			insert(node[las].root, 1, m + 1, id);
			return ;
		}
		else
		{
			int clone = ++ct, q = node[las].trans[x], tmp = las;
			node[clone] = node[q];
			node[clone].root = 0;
			node[clone].len = node[tmp].len + 1;
			for (; tmp && node[tmp].trans[x] == q; tmp = node[tmp].link)
				node[tmp].trans[x] = clone;
			node[q].link = clone;
			las = node[las].trans[x]; 
			insert(node[las].root = ++tree_ct, 1, m + 1, id);
			return ;
		}
	}
	int cur = ++ct, tmp = las;
	las = cur;
	node[cur].len = node[tmp].len + 1;
	node[cur].root = ++tree_ct;
	insert(node[cur].root, 1, m + 1, id);
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
			node[clone].root = 0;
			node[clone].len = node[tmp].len + 1;
			for (; tmp && node[tmp].trans[x] == q; tmp = node[tmp].link)
				node[tmp].trans[x] = clone;
			node[q].link = node[cur].link = clone;
		}
	}
}
struct edg
{
	int nxt, to;
} edge[4 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void work(void)
{
	for (int i = 1; i <= ct; i++) ord[i] = i;
	sort(ord + 1, ord + 1 + ct, [](int x, int y){return node[x].len < node[y].len;});
	for (int i = ct; i >= 2; i--)
	{
		node[node[ord[i]].link].root = merge(node[node[ord[i]].link].root, node[ord[i]].root);
		add(node[ord[i]].link, ord[i]);
	}
}
void dfs(int u, int fa)
{
	anc[u][0] = fa;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) dfs(to, u);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= ct; j++)
		for (int i = 1; i <= ct; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int main()
{
	ct = tree_ct = node[1].root = 1;
	ios::sync_with_stdio(false);
	cin >> str >> m;
	for (int i = 1; i <= m; i++)
	{
		string t;
		las = 1;
		cin >> t;
		int siz = t.size();
		for (int j = 0; j < siz; j++)
			SAM_insert(t[j] - 'a', i);
	}
	work();
	dfs(1, 0);
	init();
	int siz = str.size();
	pos[0] = 1;
	for (int i = 0; i < siz; i++)
	{
		if (i) l[i] = l[i - 1], pos[i] = pos[i - 1];
		while (pos[i] != 1 && !node[pos[i]].trans[str[i] - 'a'])
			pos[i] = node[pos[i]].link, l[i] = min(l[i], node[pos[i]].len);
		if (node[pos[i]].trans[str[i] - 'a']) pos[i] = node[pos[i]].trans[str[i] - 'a'], l[i]++;
	}
	cin >> q;
	while (q--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		l2--, r2--;
		int now = pos[r2];
		if (l[r2] < r2 - l2 + 1)
		{
			cout << l1 << ' ' << 0 << endl;
			continue;
		}
		for (int i = 20; i >= 0; i--)
			if (node[anc[now][i]].len >= r2 - l2 + 1) now = anc[now][i];
		pair <int, int> res = ask(node[now].root, 1, m + 1, l1, r1 + 1);
		if (!res.first) res.first = l1;
		cout << res.first << ' ' << res.second << endl;
	}
	return 0;
}