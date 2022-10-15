/*input
3
1 3
3
6 2
19 8 19 69 9 4
7 12
1 1 1 17 1 1 1

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
using ld = long double;
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, W;
		cin >> n >> W;
		pair<int, int> a[n];
		ll s = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i + 1;
		}
		sort(a, a + n, greater<pair<int, int>>());
		vector<int>ans;
		for (auto i : a)
		{
			if (s + i.first <= W)
			{
				s += i.first;
				ans.push_back(i.second);
			}
		}
		if (s >= (W + 1) / 2)
		{
			cout << ans.size() << "\n";
			for (int i : ans)
				cout << i << " ";
			cout << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}

}