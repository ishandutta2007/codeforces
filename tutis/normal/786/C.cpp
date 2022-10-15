/*input
8
1 5 7 8 1 7 6 1

*/
#pragma GCC optimize ("O3")
//#pragma GCC target ("avx2")
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
using ld = long double;
mt19937_64 rng(123);
const int mod = 1000000007;
const int inf = 200008;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int p[n + 1];
	for (int i = 1; i <= n; i++)
		p[i] = 0;
	int F[n + 2];
	for (int i = 0; i <= n + 1; i++)
		F[i] = 0;
	auto add = [&](int x, int d)
	{
		while (x <= n + 1)
		{
			F[x] += d;
			x += x & -x;
		}
	};
	auto get = [&](int x)
	{
		int ret = 0;
		while (x)
		{
			ret += F[x];
			x -= x & -x;
		}
		return ret;
	};
	vector<pair<int, int>>FF[n + 1];
	for (int i = 1; i <= n; i++)
	{
		//[i, n][a, b]++;
		add(p[a[i]] + 1, 1);
		add(i + 1, -1);
		FF[i].push_back({p[a[i]] + 1, -1});
		FF[i].push_back({i + 1, -1});
		p[a[i]] = i;
	}
	vector<int>X[n + 1];
	int ans[n + 1];
	for (int i = 1; i <= n; i++)
	{
		ans[i] = 0;
		X[n].push_back(i);
	}
	for (int i = n; i >= 1; i--)
	{
		for (int k : X[i])
		{
			int lo = 1;
			int hi = i;
			while (lo < hi)
			{
				int m = (lo + hi) / 2;
				if (get(m) <= k)
					hi = m;
				else
					lo = m + 1;
			}
			ans[k]++;
			X[lo - 1].push_back(k);
		}
		for (pair<int, int>a : FF[i])
			add(a.first, a.second);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}