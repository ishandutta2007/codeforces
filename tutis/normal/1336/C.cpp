/*input
cacdcdbbbb
bdcaccdbbb

*/
#pragma GCC optimize ("O3")
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace {
template<typename A, typename B>
istream &operator>>( istream  &input, pair<A, B> &X ) {
	input >> X.first >> X.second;
	return input;
}
template<typename A, typename B>
ostream &operator<<( ostream &output, const pair<A, B> &X ) {
	output << X.first << " " << X.second;
	return output;
}
template<typename T>
istream &operator>>( istream  &input, vector<T> &X ) {
	for (T&i : X)
		input >> i;
	return input;
}
template<typename T>
ostream &operator<<( ostream &output, const vector<T> &X ) {
	for (ll t = 0; t < (ll)X.size(); t++)
	{
		if (t + 1 != (ll)X.size())
			cout << X[t] << " ";
		else
			cout << X[t];
	}
	return output;
}
}
namespace {
const ll mod = 998244353;
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
const ll maxsz = 10;
ll I[maxsz];
bool calc = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxsz)
	{
		if (!calc)
		{
			calc = true;
			I[1] = 1;
			I[0] = 0;
			for (ll i = 2; i < maxsz; ++i)
				I[i] = (mod - (mod / i) * I[mod % i] % mod) % mod;
		}
		return I[x];
	}
	return power(x, mod - 2);
}
}
ll dp[3030][3030];
ll dp2[3030][3030];
ll P2[3030];
int main()
{
	P2[0] = 1;
	for (int i = 1; i < 3030; i++)
	{
		P2[i] = 2 * P2[i - 1];
		P2[i] %= mod;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string S, T;
	cin >> S >> T;
	int n = T.size();
	int m = S.size();
	for (int sz = 1; sz <= n; sz++)
	{
		for (int l = 0; l + sz - 1 < n; l++)
		{
			int r = l + sz - 1;
			if (sz == 1)
			{
				if (T[l] == S[0])
					dp[l][r] = 2;
			}
			else
			{
				if (T[l] == S[sz - 1])
				{
					dp[l][r] += dp[l + 1][r];
				}
				if (T[r] == S[sz - 1])
				{
					dp[l][r] += dp[l][r - 1];
				}
				dp[l][r] %= mod;
			}
		}
	}
	for (int mx = 0; mx < m; mx++)
	{
		for (int l = 0; l < n; l++)
		{
			if (mx == n - l - 1)
				dp2[l][mx] = dp[l][n - 1];
			else if (mx > n - l - 1)
			{
				dp2[l][mx] += dp2[l][mx - 1];
				if (T[l] == S[mx])
				{
					dp2[l][mx] += dp2[l + 1][mx - 1];
					dp2[l][mx] %= mod;
				}
				if (l == n - 1 && S[mx] == T[l])
					dp2[l][mx] += P2[mx];
				dp2[l][mx] %= mod;
			}
		}
	}
	ll ans = 0;
	for (int j = 0; j < m; j++)
	{
		ans += dp2[0][j];
		ans %= mod;
	}
	cout << ans << "\n";
	return 0;
}