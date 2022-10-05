#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, ans, tree_ct, node_ct, f[2 * Maxn], top[2 * Maxn];
string str;
vector <int> Ve[2 * Maxn];
struct Tree
{
	int lson, rson;
} tree[80 * Maxn];
void insert(int root, int lt, int rt, int pos)
{
	if (lt + 1 == rt) return ;
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
	}
}
int merge(int root1, int root2)
{
	if (!root1 || !root2) return root1 + root2;
	int new_node = ++tree_ct;
	tree[new_node] = (Tree){merge(tree[root1].lson, tree[root2].lson), merge(tree[root1].rson, tree[root2].rson)};
	return new_node;
}
bool ask(int root, int lt, int rt, int L, int R)
{
	if (!root) return false;
	if (lt == L && rt == R) return true;
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return ask(tree[root].rson, mid, rt, L, R);
		else if (R <= mid) return ask(tree[root].lson, lt, mid, L, R);
		else return ask(tree[root].lson, lt, mid, L, mid) | ask(tree[root].rson, mid, rt, mid, R);
	}
}
int las;
struct Node
{
	int trans[26], link, len, pos, root;
} node[2 * Maxn];
void insert(int x, int pos)
{
	int cur = ++node_ct, tmp = las;
	las = cur;
	node[cur].len = node[cur].pos = node[tmp].len + 1;
	node[cur].root = ++tree_ct;
	insert(node[cur].root, 1, n + 1, pos);
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
			int clone = ++node_ct;
			node[clone] = node[q];
			node[clone].len = node[tmp].len + 1;
			for (; tmp && node[tmp].trans[x] == q; tmp = node[tmp].link)
				node[tmp].trans[x] = clone;
			node[cur].link = node[q].link = clone;
		}
	}
}
void dfs1(int u)
{
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
	{
		dfs1(*it);
		node[u].pos = max(node[u].pos, node[*it].pos);
		node[u].root = merge(node[*it].root, node[u].root);
	}
}
void dfs2(int u)
{
	ans = max(ans, f[u]);
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
	{
		if (u == 1 || ask(node[top[u]].root, 1, n + 1, node[*it].pos - node[*it].len + node[top[u]].len, node[*it].pos))
			f[*it] = f[u] + 1, top[*it] = *it;
		else f[*it] = f[u], top[*it] = top[u]; 
		dfs2(*it);
	}
}
int main()
{
	las = node_ct = top[1] = 1;
	ios::sync_with_stdio(false);
	cin >> n >> str;
	if (n == 1)
	{
		puts("1");
		return 0;
	}
	for (int i = 0; i < n; i++)
		insert(str[i] - 'a', i + 1);
	for (int i = 2; i <= node_ct; i++) Ve[node[i].link].push_back(i);
	dfs1(1), dfs2(1);
	cout << ans;
	return 0;
}