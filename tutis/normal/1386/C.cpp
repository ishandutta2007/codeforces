/*input
6 8 2
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
4 8
4 7

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
int n, m, q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	vector<int> a(m + 2), b(m + 2);
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i];
	}
	a[0] = 0;
	b[0] = 0;
	a[m + 1] = 0;
	b[m + 1] = n + 1;
	vector<int> pa(n + 2, -2);
	function<pair<int, int>(int)>root = [&](int a)->pair<int, int>
	{
		if (pa[a] < 0)
		{
			return {a, 0};
		}
		else
		{
			pair<int, int>x = root(pa[a] / 2);
			return {x.first, (pa[a] % 2) ^ x.second};
		}
	};
	vector<int>x_, y_, p1_, p2_;
	vector<bool>OK;
	bool geras = true;
	function<bool(int, int)>merge = [&](int a, int b)->bool
	{
		pair<int, int>x = root(a);
		pair<int, int>y = root(b);
		if (x.first == y.first)
		{
			x_.push_back(-1);
			OK.push_back(geras);
			geras &= (x.second != y.second);
			return x.second != y.second;
		}
		if (pa[x.first] < pa[y.first])
			swap(x, y);
		x_.push_back(x.first);
		y_.push_back(y.first);
		p1_.push_back(pa[x.first]);
		p2_.push_back(pa[y.first]);
		pa[y.first] += pa[x.first];
		pa[x.first] = y.first * 2 + (1 ^ x.second ^ y.second);
		OK.push_back(geras);
		return true;
	};
	auto rollback = [&]()
	{
		assert(!x_.empty());
		int x = x_.back();
		x_.pop_back();
		assert(!OK.empty());
		bool cc = OK.back();
		OK.pop_back();
		geras = cc;
		if (x == -1)
			return;
		assert(!y_.empty());
		assert(!p1_.empty());
		assert(!p2_.empty());
		int y = y_.back();
		int p1 = p1_.back();
		int p2 = p2_.back();
		y_.pop_back();
		p1_.pop_back();
		p2_.pop_back();
		pa[x] = p1;
		pa[y] = p2;
	};
	vector<int> ans(m + 1);
	function<void(int, int, int, int)>rec = [&](int l1, int l2, int r1, int r2)
	{
		if (l1 > l2)
			return;
		assert(r1 <= r2);
		int l = (l1 + l2) / 2;
		for (int i = l1; i < l; i++)
			merge(a[i], b[i]);
		if (!geras)
		{
			ans[l] = r2;
		}
		else
		{
			int xx = -1;
			for (int i = r2; i >= r1; i--)
			{
				if (!merge(a[i], b[i]))
				{
					if (xx == -1)
						xx = i;
				}
			}
			assert(xx != -1);
			for (int i = r2; i >= r1; i--)
				rollback();
			ans[l] = xx;
		}
		assert(r1 <= ans[l] && ans[l] <= r2);
		merge(a[l], b[l]);
		rec(l + 1, l2, ans[l], r2);
		for (int i = l1; i <= l; i++)
			rollback();


		for (int i = ans[l] + 1; i <= r2; i++)
			merge(a[i], b[i]);
		rec(l1, l - 1, r1, ans[l]);
		for (int i = ans[l] + 1; i <= r2; i++)
			rollback();

	};
	rec(1, m, 0, m + 1);
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if (r + 1 <= ans[l])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}