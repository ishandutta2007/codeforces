/*input
7
1 2 1 2 1 2 1

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
mt19937_64 rng(123);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
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
	a[0] = -1;
	map<int, int>dp;
	set<pair<int, int>>vals;
	vals.insert({0, -1});
	dp[-1] = 0;
	int del = 0;
	for (int i = 1; i <= n; i++)
	{
		int mx = 100000000;
		int cnt = 0;
		for (pair<int, int>v : vals)
		{
			cnt++;
			if (v.second != a[i])
				v.first++;
			mx = min(mx, v.first + del);
			if (cnt == 2)
				break;
		}
		if (dp.count(a[i]))
			mx = min(mx, dp[a[i]] + del);
		if (a[i] != a[i - 1])
			del++;
		if (dp.count(a[i - 1]))
		{
			if (dp[a[i - 1]] > mx - del)
			{
				vals.erase({dp[a[i - 1]], a[i - 1]});
				dp[a[i - 1]] = mx - del;
				vals.insert({dp[a[i - 1]], a[i - 1]});
			}
		}
		else
		{
			dp[a[i - 1]] = mx - del;
			vals.insert({dp[a[i - 1]], a[i - 1]});
		}
	}
	cout << ((vals.begin())->first + del) << "\n";
}