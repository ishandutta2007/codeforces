/*input
10
4 7 3 2 5 1 9 10 6 8
-4 40 -46 -8 -16 4 -10 41 12 3

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
using ld = double;
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll h[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	ll dp[n + 1];
	dp[0] = 0;
	h[0] = n + 1;
	b[0] = 0;
	vector<pair<ll, ll>>V;
	V.push_back({0, 0});
	vector<ll>vals = { (ll) - 1e18, 0ll};
	for (int i = 1; i <= n; i++)
	{
		V.push_back({i, dp[i - 1]});
		vals.push_back(max(vals.back(), b[i] + dp[i - 1]));
		while (V.size() >= 2 && h[V[V.size() - 2].first] >= h[V.back().first])
		{
			vals.pop_back();
			vals.pop_back();
			V[V.size() - 2].first = V.back().first;
			V[V.size() - 2].second = max(V.back().second, V[V.size() - 2].second);
			V.pop_back();
			vals.push_back(max(vals.back(), b[V.back().first] + V.back().second));
		}
		dp[i] = vals.back();
	}
	cout << dp[n] << "\n";
}