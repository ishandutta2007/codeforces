/*input
7
19 20 1
13 15 2
6 11 2
4 10 1
14 17 1
13 13 2
5 9 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct ST
{
	int l, r;
	ST *left, *right;
	int mx = 0;
	int lazy = 0;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void fix()
	{
		mx += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(int x, int y, int w)
	{
		fix();
		if (y < l || r < x)
			return;
		if (x <= l && r <= y)
		{
			lazy += w;
			fix();
		}
		else
		{
			left->add(x, y, w);
			right->add(x, y, w);
			mx = max(left->mx, right->mx);
		}
	}
	void set(int i, int w)
	{
		fix();
		if (l < r) {
			if (i <= (l + r) / 2)
				left->set(i, w);
			else
				right->set(i, w);
		}
		mx = max(mx, w);
	}
	int get(int x, int y)
	{
		fix();
		if (y < l || r < x)
			return 0;
		if (x <= l && r <= y)
		{
			return mx;
		}
		else
		{
			return max(left->get(x, y),
			           right->get(x, y));
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	pair<pair<int, int>, int>a[n];
	map<int, int>M;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first.first >> a[i].first.second >> a[i].second;
		a[i].second--;
		M[a[i].first.first] = 0;
		M[a[i].first.second] = 0;
	}
	int timer = 3;
	for (auto &i : M)
		i.second = timer++;
	sort(a, a + n, [&](auto c, auto d) {return c.first.second < d.first.second;});
	for (int i = 0; i < n; i++)
	{
		a[i].first.first = M[a[i].first.first];
		a[i].first.second = M[a[i].first.second];
	}
	ST* medis[2];
	medis[0] = new ST(0, 4e5 + 30);
	medis[1] = new ST(0, 4e5 + 30);
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		int l = a[i].first.first;
		int r = a[i].first.second;
		int t = a[i].second;
		medis[1 - t]->add(0, l - 1, 1);
		int x = medis[1 - t]->get(0, l - 1);
		medis[t]->set(r, x);
		ret = max(ret, x);
	}
	cout << ret << "\n";
	return 0;
}