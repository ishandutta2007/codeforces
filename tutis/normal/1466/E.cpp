/*input
8
2
1 7
3
1 2 4
4
5 5 5 5
5
6 2 2 1 0
1
0
1
1
6
1 12 123 1234 12345 123456
5
536870912 536870911 1152921504606846975 1152921504606846974 1152921504606846973

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
using uint = unsigned int;
using ll = long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const uint mod = 1000000007;
uint P[60];
uint V[60];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	P[0] = 1;
	for (int i = 1; i < 60; i++)
	{
		P[i] = P[i - 1] * 2;
		if (P[i] >= mod)
			P[i] -= mod;
	}
	while (t--)
	{
		int n;
		cin >> n;
		for (int j = 0; j < 60; j++)
			V[j] = 0;
		ull x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
			for (int j = 0; j < 60; j++)
			{
				if ((x[i] & (1ll << j)) != 0)
				{
					V[j] += P[j];
					if (V[j] >= mod)
						V[j] -= mod;
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			uint s1 = 0;
			ll s2 = (x[i] % mod) * n;
			for (int j = 0; j < 60; j++)
			{
				if ((x[i] & (1ll << j)) != 0)
				{
					s1 += V[j];
				}
				else
				{
					s2 += V[j];
				}
				if (s1 >= mod)
					s1 -= mod;
			}
			s2 %= mod;
			ans += s1 * s2;
			ans %= mod;
		}
		cout << ans << "\n";
	}
}