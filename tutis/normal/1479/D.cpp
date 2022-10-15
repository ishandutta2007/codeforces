/*input
6 8
3 2 1 3 1 3
1 2
1 3
2 4
2 5
4 6
3 5 1 1
3 5 1 3
3 5 1 3
1 1 2 2
1 1 3 3
1 4 1 5
1 6 1 3
1 6 1 3

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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(1234);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int pa[300005 + 1][20];
int d[300005 + 1];
int a[300005 + 1];
ull H[300005 + 1];
vector<int>adj[300005 + 1];
struct ST
{
	int l, r;
	ull H = 0;
	ST *left, *right;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	ST(int l, int r, ull H, ST*left, ST*right): l(l), r(r), H(H), left(left), right(right)
	{
	}
	ST* add(int x, ull h)
	{
		if (l == r)
			return new ST(l, r, H ^ h, NULL, NULL);
		if (x <= (l + r) / 2)
			return new ST(l, r, H ^ h, left->add(x, h), right);
		else
			return new ST(l, r, H ^ h, left, right->add(x, h));
	}
};
ST* med[300005 + 2];
void dfs(int i, int p, ST* medis)
{
	pa[i][0] = p;
	for (int j = 1; j < 20; j++)
		pa[i][j] = pa[pa[i][j - 1]][j - 1];
	if (a[i] != -1)
		medis = medis->add(a[i], H[a[i]]);
	med[i] = medis;
	for (int j : adj[i])
	{
		if (j != p)
		{
			d[j] = d[i] + 1;
			dfs(j, i, medis);
		}
	}
}
int bs(int lo, int hi, int i, ST*m1, ST*m2)
{
	if (hi < m1->l || m1->r < lo)
		return -1;
	ull h = m1->H ^ m2->H;
	if (m1->l <= i && i <= m1->r)
		h ^= H[i];
	if (h == 0)
		return -1;
	if (m1->l == m1->r)
		return m1->l;
	int v = bs(lo, hi, i, m1->left, m2->left);
	if (v == -1)
		v = bs(lo, hi, i, m1->right, m2->right);
	return v;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
		H[i] = rng();
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	d[1] = 0;
	dfs(1, 1, new ST(0, n + 1));
	auto lca = [&](int a, int b)->int
	{
		if (d[a] < d[b])
			swap(a, b);
		for (int t = 19; t >= 0; t--)
		{
			if (d[pa[a][t]] >= d[b])
				a = pa[a][t];
		}
		for (int t = 19; t >= 0; t--)
		{
			if (pa[a][t] != pa[b][t])
			{
				a = pa[a][t];
				b = pa[b][t];
			}
		}
		if (a != b)
			return pa[a][0];
		else
			return a;
	};
	while (q--)
	{
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		int w = lca(u, v);
		cout << bs(l, r, a[w], med[u], med[v]) << "\n";
	}
}