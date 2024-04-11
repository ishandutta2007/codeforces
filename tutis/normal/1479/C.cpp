/*input
1 1

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
	ll L, R;
	cin >> L >> R;
	ll n = 32;
	vector<pair<pair<int, int>, int>>ans;
	ll lo[n + 1];
	ll hi[n + 1];
	lo[n] = hi[n] = 0;
	for (int i = n - 1; i >= 2; i--)
	{
		lo[i] = hi[i] = 1;
		ans.push_back({{i, n}, 1});
		for (int j = n - 1; j > i; j--)
		{
			if (hi[j] <= 1000000)
				ans.push_back({{i, j}, hi[j]});
			hi[i] += hi[j] - lo[j] + 1;
		}
	}
	while (L <= R)
	{
		if (L == 1)
		{
			L++;
			ans.push_back({{1, n}, 1});
			continue;
		}
		ll sz = 1;
		while (L + sz * 2 - 1 <= R)
			sz *= 2;
		for (int j = n - 1; j >= 2; j--)
		{
			if (hi[j] == sz)
			{
				ans.push_back({{1, j}, L - 1});
			}
		}
		L += sz;
	}
	cout << "YES\n";
	cout << n << " " << ans.size() << "\n";
	for (pair<pair<int, int>, int>i : ans)
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
}