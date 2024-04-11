/*input
400 234567899

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
ll dp[402][402][2];
ll po(ll v, ll p, ll m)
{
	if (p == 0)
		return 1;
	if (p % 2 == 1)
		return (po(v, p - 1, m) * v) % m;
	ll x = po(v, p / 2, m);
	x *= x;
	x %= m;
	return x;
}
ll F[402];
ll iF[402];
ll c[402];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, M;
	cin >> n >> M;
	dp[0][0][0] = 1;
	F[0] = 1;
	for (int i = 1; i < 402; i++)
		F[i] = (F[i - 1] * i) % M;
	for (int i = 0; i < 402; i++)
		iF[i] = po(F[i], M - 2, M);
	for (int k = 1; k < 402; k++)
	{
		c[k] = 0;
		for (int l = 0; l < k; l++)
		{
			int r = k - l - 1;
			c[k] += (((F[k - 1] * iF[l]) % M) * iF[r]) % M;
			c[k] %= M;
		}
		c[k] *= iF[k];
		c[k] %= M;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			for (int cnt = 1; cnt <= min(i, k); cnt++)
			{
				dp[i][k][1] += dp[i - cnt][k - cnt][0] * c[cnt];
				dp[i][k][1] %= M;
			}
			dp[i][k][0] = dp[i - 1][k][1];
		}
	}
	ll ans = 0;
	for (int k = 1; k <= n; k++)
	{
		ans += dp[n][k][1] * F[k];
		ans %= M;
	}
	if (ans < 0)
		ans += M;
	cout << ans << "\n";
}