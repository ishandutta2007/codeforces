/*input
6
8 1 3 3 1 2

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
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int x[n + 1];
	x[0] = 0;
	for (int i = 1; i <= n; i++)
		x[i] = x[i - 1] ^ a[i];
	int ans = 0;
	for (int t = 0; t < 20; t++)
	{
		int l = 1;
		for (int i = 1; i <= n; i++)
		{
			if ((a[i] & (1 << t)) == 0)
			{
				l = i + 1;
			}
			else
			{
				if (i == n || ((a[i + 1] & (1 << t)) == 0))
				{
					int r = i;
					vector<pair<int, int>>A[2];
					for (int j = l - 1; j <= r; j++)
					{
						A[j % 2].push_back({x[j] & (~((1 << t) - 1)), j});
					}
					for (int c : {0, 1})
					{
						vector<pair<int, int>>&B = A[c];
						sort(B.begin(), B.end());
						int l = 0;
						for (int t = 1; t < B.size(); t++)
						{
							if (B[t].first == B[t - 1].first)
							{
								ans = max(ans, B[t].second - B[l].second);
							}
							else
							{
								l = t;
							}
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
}