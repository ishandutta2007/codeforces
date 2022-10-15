/*input
5
4
1 2
0
2 1 4
1 2
5
1 5
1 1
1 2
1 3
1 4
5
0
0
2 1 2
1 2
2 2 1
4
2 2 3
0
0
2 3 2
5
1 2
1 3
1 4
1 5
0

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
		int n;
		cin >> n;
		vector<int>adj[n + 1];
		vector<int>atg[n + 1];
		vector<int> cnt(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			for (int j = 0; j < k; j++)
			{
				int b;
				cin >> b;
				cnt[i]++;
				adj[i].push_back(b);
				atg[b].push_back(i);
			}
		}
		int dp[n + 1];
		for (int i = 1; i <= n; i++)
			dp[i] = -1;
		queue<int>Q;
		for (int i = 1; i <= n; i++)
			if (adj[i].size() == 0)
			{
				dp[i] = 1;
				Q.push(i);
			}
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			for (int b : atg[a])
			{
				cnt[b]--;
				if (cnt[b] == 0)
				{
					pair<int, int>mx = {1, 0};
					for (int c : adj[b])
					{
						mx = max(mx, {dp[c], c});
					}
					if (b > mx.second)
						dp[b] = mx.first;
					else
						dp[b] = mx.first + 1;
					Q.push(b);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i]);
		for (int i = 1; i <= n; i++)
			if (dp[i] == -1)
				ans = -1;
		cout << ans << "\n";
	}
}