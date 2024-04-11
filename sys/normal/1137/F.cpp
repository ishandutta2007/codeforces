#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600005;
int n, q, col_ct, sum[Maxn];
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int y)
{
	if (!x) return ;
	for (int i = x; i <= 600000; i += lowbit(i))
		sum[i] += y;
}
int ask(int x)
{
	int result = 0;
	for (int i = x; i; i -= lowbit(i))
		result += sum[i];
	return result;
}
struct Node
{
	int son[2], fa, col, siz;
	bool tag;
} node[Maxn];
void update(int t)
{
	node[t].siz = 1 + node[node[t].son[0]].siz + node[node[t].son[1]].siz;
}
bool get_son(int t)
{
	return node[node[t].fa].son[1] == t;
}
bool heavy(int t)
{
	return node[node[t].fa].son[0] == t || node[node[t].fa].son[1] == t;
}
void rotate(int t)
{
	int fa = node[t].fa, gf = node[fa].fa;
	if (heavy(fa))
		node[gf].son[get_son(fa)] = t;
	bool s = get_son(t);
	node[fa].son[s] = node[t].son[!s];
	node[node[fa].son[s]].fa = fa;
	node[t].son[!s] = fa, node[fa].fa = t;
	node[t].fa = gf;
	update(fa), update(t);
}
void pushdown(int t)
{
	if (node[t].tag)
	{
		swap(node[t].son[0], node[t].son[1]);
		node[node[t].son[0]].tag ^= 1;
		node[node[t].son[1]].tag ^= 1;
		node[t].tag = 0;
	}
	node[node[t].son[0]].col = node[node[t].son[1]].col = node[t].col;
}
stack <int> St;
void splay(int t)
{
	int tmp = t;
	St.push(tmp);
	while (heavy(tmp)) tmp = node[tmp].fa, St.push(tmp);
	while (!St.empty()) pushdown(St.top()), St.pop();
	while (heavy(t))
	{
		int fa = node[t].fa;
		if (!heavy(fa)) rotate(t);
		else
		{
			if (get_son(t) ^ get_son(fa))
				rotate(t), rotate(t);
			else rotate(fa), rotate(t);
		}
	}
}
void access(int t, int col)
{
	int tmp = 0;
	for (; t; tmp = t, t = node[t].fa)
	{
		splay(t);
		add(node[t].col, -node[node[t].son[0]].siz - 1);
		node[t].son[1] = tmp;
		update(t);
	}
	add(col, node[tmp].siz);
	node[tmp].col = col;
}
void makeroot(int t)
{
	access(t, ++col_ct);
	splay(t);
	node[t].tag ^= 1;
}
void link(int x, int y)
{
	makeroot(x);
	node[x].fa = y;
}
int get_rank(int t)
{
	splay(t);
	return node[node[t].son[1]].siz + ask(node[t].col - 1) + 1;
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) node[i].siz = 1;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < y) swap(x, y);
		link(x, y);
	}
	for (int i = 1; i <= n; i++)
		makeroot(i);
	while (q--)
	{
		string str;
		cin >> str;
		if (str == "up")
		{
			int x;
			scanf("%d", &x);
			makeroot(x);
		}
		if (str == "when")
		{
			int x;
			scanf("%d", &x);
			printf("%d\n", get_rank(x));
		}
		if (str == "compare")
		{
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", min(make_pair(get_rank(x), x), make_pair(get_rank(y), y)).second);
		}
	}
	return 0;
}