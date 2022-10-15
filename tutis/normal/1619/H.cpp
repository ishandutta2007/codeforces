/*input
5 9
2 3 5 1 4
2 3 5
2 5 5
2 5 1
2 5 3
2 5 4
1 5 4
2 5 3
2 2 5
2 5 1

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node
{
	unsigned int w;
	int l, r, p;
	int sz;
	int v;
	node() {
		l = r = p = sz = v = w = 0;
	}
	node(int x)
	{
		w = (unsigned int)rng();
		sz = 1;
		v = x;
		l = r = p = 0;
	}
} treap[100001];
int merge(int a, int b)
{
	if (a == 0 || b == 0)
		return a ^ b;
	if (treap[a].w < treap[b].w)
	{
		treap[a].sz += treap[b].sz;
		treap[treap[a].r].p = 0;
		int x = merge(treap[a].r, b);
		treap[x].p = a;
		treap[a].r = x;
		return a;
	}
	else
	{
		treap[b].sz += treap[a].sz;
		treap[treap[b].l].p = 0;
		int x = merge(a, treap[b].l);
		treap[x].p = b;
		treap[b].l = x;
		return b;
	}
}
void split(int x, int sz, int &l, int &r)
{
	if (treap[x].sz <= sz)
	{
		l = x;
		r = 0;
	}
	else if (sz <= 0)
	{
		l = 0;
		r = x;
	}
	else if (sz <= treap[treap[x].l].sz)
	{
		treap[x].sz -= sz;
		treap[treap[x].l].p = 0;
		split(treap[x].l, sz, l, r);
		treap[x].l = r;
		treap[r].p = x;
		r = x;
	}
	else
	{
		treap[x].sz = sz;
		treap[treap[x].r].p = 0;
		split(treap[x].r, sz - treap[treap[x].l].sz - 1, l, r);
		treap[x].r = l;
		treap[l].p = x;
		l = x;
	}
}
pair<int, int> id(int x)
{
	if (treap[x].p == 0)
		return {x, treap[treap[x].l].sz};
	else
	{
		int p = treap[x].p;
		pair<int, int>v = id(p);
		if (treap[p].r == x)
			v.second += treap[treap[x].l].sz + 1;
		else
			v.second -= treap[treap[x].r].sz + 1;
		return v;
	}
}
int rot1(pair<int, int>x)
{
	int a, b;
	split(x.first, x.second, a, b);
	return merge(b, a);
}
int rot2(pair<int, int>x)
{
	int a, b;
	split(x.first, x.second + 1, a, b);
	return merge(b, a);
}
void print(int x)
{
	if (x == 0)
		return;
	cout << "(";
	if (treap[x].l != 0)
		assert(treap[treap[x].l].p == x);
	if (treap[x].r != 0)
		assert(treap[treap[x].r].p == x);
	print(treap[x].l);
	cout << treap[x].v << " ";
	print(treap[x].r);
	cout << ")";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		treap[i] = node(i);
	for (int i = 1; i <= n; i++)
	{
		int p;
		cin >> p;
		pair<int, int>a = id(i);
		pair<int, int>b = id(p);
		if (a.first != b.first)
			merge(rot2(a), rot1(b));
	}
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x, y;
			cin >> x >> y;
			pair<int, int>a = id(x);
			pair<int, int>b = id(y);
			if (a.first == b.first)
			{
				if (a.second > b.second)
					swap(a, b);
				int x, y, z;
				split(a.first, a.second + 1, x, y);
				split(y, b.second - a.second, y, z);
				merge(z, x);
			}
			else
			{
				merge(rot2(a), rot2(b));
			}
		}
		else
		{
			int i, k;
			cin >> i >> k;
			pair<int, int>a = id(i);
			int s = treap[a.first].sz;
			a.second += k;
			a.second %= s;
			int x, y, z;
			split(a.first, a.second, x, y);
			split(y, 1, y, z);
			merge(x, merge(y, z));
			cout << treap[y].v << "\n";
		}
	}
}