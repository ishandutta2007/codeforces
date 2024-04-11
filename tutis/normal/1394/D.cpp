/*input
5
40 10 30 50 20
2 3 2 3 1
1 2
1 3
2 4
2 5

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int t[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	t[0] = 0;
	int h[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	h[0] = h[1];
	vector<int>adj[n + 1];
	adj[0].push_back(1);
	adj[1].push_back(0);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll dp[n + 1][2];
	function<void(int, int)>dfs = [&](int i, int p)
	{
		ll sum = t[p] + t[i];
		if (i == 1)
			sum = 0;
		ll k0 = 0;
		ll k1 = 0;
		vector<pair<ll, ll>> D;
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			dfs(j, i);
			if (h[j] == h[i])
			{
				D.push_back({dp[j][0], dp[j][1]});
			}
			else if (h[j] < h[i])
			{
				k1++;
				sum += dp[j][1];
			}
			else
			{
				k0++;
				sum += dp[j][0];
			}
		}
		sort(D.begin(), D.end(), [&](pair<ll, ll> a, pair<ll, ll> b) {
			return a.second - a.first > b.second - b.first;
		});
		function<ll()>calc = [&]()
		{
			ll ret = 1e17;
			ll sum = 0;
			for (auto i : D)
				sum += i.second;
			for (int c = 0; c <= (int)D.size(); c++)
			{
				if (c - 1 >= 0)
				{
					sum += D[c - 1].first;
					sum -= D[c - 1].second;
				}
				ll gal = sum;
				ll k0_ = k0 + c;
				ll k1_ = k1 + ((int)D.size() - c);
				gal -= t[i] * min(k0_, k1_);
				ret = min(ret, gal);
			}
			return ret;
		};
		dp[i][0] = dp[i][1] = 1e17;
		if (h[p] <= h[i])
		{
			if (i != 1)
				k1++;
			dp[i][0] = calc() + sum;
			if (i != 1)
				k1--;
		}
		if (h[p] >= h[i])
		{
			if (i != 1)
				k0++;
			dp[i][1] = calc() + sum;
			if (i != 1)
				k0--;
		}
	};
	dfs(1, 0);
	cout << min(dp[1][0], dp[1][1]) << "\n";
	return 0;
}