#include <bits/stdc++.h>
#define y1 y11
using namespace std;

const int Maxn = 1000005, p = 1e9 + 7;
int n, m, k;
set <pair <int, int> > Se;
vector <pair <int, int> > In[Maxn], Out[Maxn];
struct Tree
{
	int lt, rt;
	long long sum;
	bool tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, false};
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
		tree[root << 1].tag = tree[root << 1 | 1].tag = true;
		tree[root << 1].sum = tree[root << 1 | 1].sum = 0;
		tree[root].tag = false;
	}
}
void modify(int root, int pos, long long val)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].sum = val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify(root << 1 | 1, pos, val);
		else modify(root << 1, pos, val);
		tree[root].sum = (tree[root << 1].sum + tree[root << 1 | 1].sum) % p;
	}
}
void clear(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].sum = 0, tree[root].tag = true;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) clear(root << 1 | 1, lt, rt);
		else if (rt <= mid) clear(root << 1, lt, rt);
		else clear(root << 1, lt, mid), clear(root << 1 | 1, mid, rt);
		tree[root].sum = (tree[root << 1].sum + tree[root << 1 | 1].sum) % p;
	}
}
long long ask(int root, int lt, int rt)
{
	if (lt >= rt) return 0;
	if (lt == tree[root].lt && rt == tree[root].rt)
		return tree[root].sum;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return ask(root << 1 | 1, lt, rt);
		else if (rt <= mid) return ask(root << 1, lt, rt);
		else return (ask(root << 1, lt, mid) + ask(root << 1 | 1, mid, rt)) % p;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	Se.insert(make_pair(0, 0));
	for (int i = 1; i <= k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		In[x1].push_back(make_pair(y1, y2));
		Out[x2 + 1].push_back(make_pair(y1, y2));
	}
	build(1, 1, m + 1);
	modify(1, 1, 1);
	for (vector <pair <int, int> > :: iterator it = In[1].begin(); it != In[1].end(); it++)
		Se.insert(*it);
	for (int i = 2; i <= n; i++)
	{
		sort(In[i].begin(), In[i].end());
		reverse(In[i].begin(), In[i].end());
		for (vector <pair <int, int> > :: iterator it = In[i].begin(); it != In[i].end(); it++)
		{
			if (it -> second == m) continue;
			modify(1, it -> second + 1, ask(1, (--Se.lower_bound(make_pair(it -> second + 1, 0x3f3f3f3f))) -> second + 1, it -> second + 2));
		}
		for (vector <pair <int, int> > :: iterator it = Out[i].begin(); it != Out[i].end(); it++)
			Se.erase(Se.find(*it));
		for (vector <pair <int, int> > :: iterator it = In[i].begin(); it != In[i].end(); it++)
		{
			Se.insert(*it);
			clear(1, it -> first, it -> second + 1);
		}
	}
	if (Se.rbegin() -> second == m)
		puts("0");
	else printf("%lld\n", ask(1, Se.rbegin() -> second + 1, m + 1));
	return 0;
}