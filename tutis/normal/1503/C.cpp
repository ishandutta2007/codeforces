/*input
6
4 2
8 4
3 0
2 3
7 1
0 1

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll a[n], c[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i] >> c[i];
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ans += c[i];
	}
	ll p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](ll x, ll y) {
		if (a[x] == a[y])
			return c[x] > c[y];
		return a[x] < a[y];
	});
	ll dp[n];
	dp[0] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>Q;
	Q.push({a[p[0]] + c[p[0]], 0});
	multiset<ll>X, Y;
	Y.insert(dp[0]);
	for (ll i = 1; i < n; i++)
	{
		ll ai = a[p[i]];
		while (!Q.empty() && Q.top().first <= ai)
		{
			ll j = Q.top().second;
			Q.pop();
			Y.erase(Y.find(dp[j]));
			X.insert(dp[j] - a[p[j]] - c[p[j]]);
		}
		dp[i] = 1e18;
		if (!Y.empty())
		{
			dp[i] = min(dp[i], *Y.begin());
		}
		if (!X.empty())
		{
			dp[i] = min(dp[i], ai + (*X.begin()));
		}
		Y.insert(dp[i]);
		Q.push({a[p[i]] + c[p[i]], i});
	}
	ans += dp[n - 1];
	cout << ans << "\n";
}