#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, ct, tree_ct, las, ord[Maxn];
string str, ans;
struct Tree
{
	int lson, rson;
} tree[40 * Maxn];
void modify(int root, int lt, int rt, int pos)
{
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			tree[root].rson = ++tree_ct;
			modify(tree[root].rson, mid, rt, pos);
		}
		else
		{
			tree[root].lson = ++tree_ct;
			modify(tree[root].lson, lt, mid, pos);
		}
	}
}
int merge(int A, int B)
{
	if (!A || !B) return A + B;
	int newnode = ++tree_ct;
	tree[newnode] = (Tree){merge(tree[A].lson, tree[B].lson), merge(tree[A].rson, tree[B].rson)};
	return newnode;
}
struct Node
{
	int trans[26], link, len, root;
} node[2 * Maxn];
void insert(int x, int pos)
{
	int cur = ++ct, tmp = las;
	las = cur;
	node[cur].len = node[tmp].len + 1;
	node[cur].root = ++tree_ct;
	modify(node[cur].root, 1, n + 1, pos);
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
			node[clone].len = node[tmp].len + 1;
			for (; tmp && node[tmp].trans[x] == q; tmp = node[tmp].link)
				node[tmp].trans[x] = clone;
			node[cur].link = node[q].link = clone;
		}
	}
}
void work(void)
{
	for (int i = 1; i <= ct; i++)
		ord[i] = i;
	sort(ord + 1, ord + 1 + ct, [](int x, int y){return node[x].len < node[y].len;});
	for (int i = ct; i >= 2; i--)
		node[node[ord[i]].link].root = merge(node[node[ord[i]].link].root, node[ord[i]].root);
}
bool ask(int root, int lt, int rt, int L = 1, int R = n + 1)
{
	if (!root) return false;
	if (lt == L && rt == R) return true;
	else
	{
		int mid = (L + R) >> 1;
		if (lt >= mid) return ask(tree[root].rson, lt, rt, mid, R);
		else if (rt <= mid) return ask(tree[root].lson, lt, rt, L, mid);
		else return ask(tree[root].lson, lt, mid, L, mid) | ask(tree[root].rson, mid, rt, mid, R);
	}
}
int lt, rt;
bool dfs(int u, int now, int siz, int type)
{
	if (now == siz)
	{
		if (type) return true;
		for (int i = 0; i < 26; i++)
			if (node[u].trans[i] && ask(node[node[u].trans[i]].root, lt + now, rt + 1))
			{
				ans += i + 'a';
				return true;
			}
		return false;
	}
	ans += str[now];
	if (node[u].trans[str[now] - 'a'] && ask(node[node[u].trans[str[now] - 'a']].root, lt + now, rt + 1)
		&& dfs(node[u].trans[str[now] - 'a'], now + 1, siz, false)) return true;
	ans.pop_back();
	for (int i = str[now] - 'a' + 1; i < 26; i++)
		if (node[u].trans[i] && ask(node[node[u].trans[i]].root, lt + now, rt + 1))
		{
			ans += i + 'a';
			return true;
		}
	return false;
}
int main()
{
	las = ct = 1;
	cin >> str;
	n = str.size();
	for (int i = 0; i < n; i++)
		insert(str[i] - 'a', i + 1);
	work();
	scanf("%d", &T);
	while (T--)
	{
		cin >> lt >> rt >> str;
		int siz = str.size();
		ans = "";
		if (dfs(1, 0, siz, false)) cout << ans << endl;
		else cout << "-1" << endl;
	}
	return 0;
}