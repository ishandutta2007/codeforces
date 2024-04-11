#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, ct, cnt[27];
string str;
struct Tree
{
	int lt, rt, sum, tag;
} tree[27][4 * Maxn];
void build(int ch, int root, int lt, int rt)
{
	tree[ch][root] = (Tree){lt, rt, 0, 0};
	if (lt + 1 == rt)
		tree[ch][root].sum = (str[lt - 1] - 'a' == ch);
	else
	{
		int mid = (lt + rt) >> 1;
		build(ch, root << 1, lt, mid);
		build(ch, root << 1 | 1, mid, rt);
		tree[ch][root].sum = tree[ch][root << 1].sum + tree[ch][root << 1 | 1].sum;
	}
}
void pushdown(int ch, int root)
{
	if (tree[ch][root].tag == 1)
	{
		tree[ch][root << 1].tag = 1;
		tree[ch][root << 1 | 1].tag = 1;
		tree[ch][root << 1].sum = tree[ch][root << 1].rt - tree[ch][root << 1].lt;
		tree[ch][root << 1 | 1].sum = tree[ch][root << 1 | 1].rt - tree[ch][root << 1 | 1].lt;
		tree[ch][root].tag = 0;
	}
	if (tree[ch][root].tag == -1)
	{
		tree[ch][root << 1].tag = -1;
		tree[ch][root << 1 | 1].tag = -1;
		tree[ch][root << 1].sum = 0;
		tree[ch][root << 1 | 1].sum = 0;
		tree[ch][root].tag = 0;
	}
}
void insert(int ch, int root, int lt, int rt, bool type)
{
	if (lt == rt) return ;
	if (lt == tree[ch][root].lt && rt == tree[ch][root].rt)
		tree[ch][root].sum = type * (rt - lt), tree[ch][root].tag = type ? 1 : -1;
	else
	{
		pushdown(ch, root);
		int mid = (tree[ch][root].lt + tree[ch][root].rt) >> 1;
		if (lt >= mid) insert(ch, root << 1 | 1, lt, rt, type);
		else if (rt <= mid) insert(ch, root << 1, lt, rt, type);
		else insert(ch, root << 1, lt, mid, type), insert(ch, root << 1 | 1, mid, rt, type);
		tree[ch][root].sum = tree[ch][root << 1].sum + tree[ch][root << 1 | 1].sum;
	}
}
int ask(int ch, int root, int lt, int rt)
{
	if (lt == tree[ch][root].lt && rt == tree[ch][root].rt)
		return tree[ch][root].sum;
	else
	{
		pushdown(ch, root);
		int mid = (tree[ch][root].lt + tree[ch][root].rt) >> 1;
		if (lt >= mid) return ask(ch, root << 1 | 1, lt, rt);
		else if (rt <= mid) return ask(ch, root << 1, lt, rt);
		else return ask(ch, root << 1, lt, mid) + ask(ch, root << 1 | 1, mid, rt);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> str;
	for (int i = 0; i <= 25; i++)
		build(i, 1, 1, n + 1);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ct = 0;
		for (int j = 0; j <= 25; j++)
		{
			cnt[j] = ask(j, 1, x, y + 1);
			ct += cnt[j] & 1;
		}
		if (ct > 1) continue;
		for (int j = 0; j <= 25; j++)
			insert(j, 1, x, y + 1, false);
		int now = x;
		for (int j = 0; j <= 25; j++)
			insert(j, 1, now, now + (cnt[j] >> 1), true), now += (cnt[j] >> 1);
		for (int j = 0; j <= 25; j++)
			if (cnt[j] & 1) insert(j, 1, now, now + 1, true), now++;
		for (int j = 25; j >= 0; j--)
			insert(j, 1, now, now + (cnt[j] >> 1), true), now += (cnt[j] >> 1);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 25; j++)
			if (ask(j, 1, i, i + 1)) putchar(j + 'a');
	return 0;
}