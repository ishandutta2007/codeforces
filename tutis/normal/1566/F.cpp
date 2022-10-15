/*input
2
4 11
2 6 14 18
0 3
4 5
11 15
3 5
10 13
16 16
1 4
8 12
17 19
7 13
14 19
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19

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
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		vector<ll>a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		vector<pair<ll, ll>>lr;
		{
			pair<ll, ll>x[m];
			for (int i = 0; i < m; i++)
			{
				cin >> x[i].first >> x[i].second;
				auto it = lower_bound(a.begin(), a.end(), x[i].first);
				if (it != a.end() && (*it) <= x[i].second)
				{

				}
				else
				{
					lr.push_back(x[i]);
				}
			}
		}
		sort(lr.begin(), lr.end(), [&](pair<ll, ll>x, pair<ll, ll>y) {
			ll i = x.second - x.first;
			ll j = y.second - y.first;
			if (i != j)
				return i < j;
			return x.first < y.first;
		});
		map<ll, ll>LR;
		for (auto i : lr)
		{
			auto it = LR.lower_bound(i.first);
			if (it != LR.end() && it->second <= i.second)
				continue;
			LR[i.first] = i.second;
		}
		for (int i = 0; i < n; i++)
			LR[a[i]] = a[i];
		lr = {};
		for (auto i : LR)
			lr.push_back(i);
		if (lr.empty())
			cout << "0\n";
		else
		{
			m = lr.size();
			vector<ll>l(m + 2);
			vector<ll>r(m + 2);
			l[0] = r[0] = -4e9;
			for (int i = 0; i < m; i++)
			{
				l[i + 1] = lr[i].first;
				r[i + 1] = lr[i].second;
			}
			l[m + 1] = r[m + 1] = 4e9;
			ll dp[m + 2];
			for (int i = 0; i <= m + 1; i++)
				dp[i] = 4e15;
			dp[0] = 0;
			int id11 = 0;
			int id12 = 0;
			int id21 = 0;
			int id22 = 0;
			for (int i = 0; i < n; i++)
			{
				id11 = id21;
				id12 = id22;
				while (id12 + 1 <= m + 1 && r[id12 + 1] <= a[i])
					id12++;
				while (l[id21] < a[i])
					id21++;
				id22 = id21;
				if (i + 1 < n)
				{
					while (id22 + 1 <= m + 1 && r[id22 + 1] <= a[i + 1])
						id22++;
				}
				else
					id22 = m + 1;
				ll v1 = dp[id12];
				ll v2 = dp[id12];
				assert(r[id12] <= a[i]);
				assert(a[i] <= l[id21]);
				assert(id11 <= id12);
				assert(id21 <= id22);
				vector<pair<int, ll>>upd;
				for (int j = max(1, id11); j <= id12; j++)
				{
					v2 = min(v2, dp[j - 1] + (a[i] - r[j]));
					v1 = min(v1, dp[j - 1] + 2 * (a[i] - r[j]));
					upd.push_back({j, dp[j - 1] + (a[i] - r[j])});
				}
				for (int j = id21; j <= id22; j++)
				{
					upd.push_back({j, min({
							v1 + (l[j] - a[i]),
							v2 + (l[j] - a[i]) * 2,
							dp[j - 1] + (l[j] - a[i])
						})
					});
					// dp[j] = min(dp[j], v1 + (l[j] - a[i]));
					// dp[j] = min(dp[j], v2 + (l[j] - a[i]) * 2);
					// dp[j] = min(dp[j], dp[j - 1] + (l[j] - a[i]));
				}
				for (auto i : upd)
				{
					dp[i.first] = min(dp[i.first], i.second);
				}
			}
			cout << dp[m] << "\n";
		}
	}
}