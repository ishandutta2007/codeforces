/*input
100

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
const ll mod = 998244353;
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
int dal[1000001];
ll dp[1000001];
int main()
{
	for (int a = 1; a <= 1000000; a++)
		for (int b = a; b <= 1000000; b += a)
			dal[b]++;
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	dp[1] = 1;
	ll sum = 1;
	for (int n = 2; n <= 1000000; n++)
	{
		dp[n] = dal[n];
		dp[n] += sum;
		if (dp[n] >= mod)
			dp[n] -= mod;
		sum += dp[n];
		if (sum >= mod)
			sum -= mod;
	}
	int n;
	cin >> n;
	cout << dp[n] << "\n";
}