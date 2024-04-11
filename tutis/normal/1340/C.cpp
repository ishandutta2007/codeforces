/*input
13 4
0 3 7 13
9 9

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
const ll mod = 1000000007;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll>d(m);
	cin >> d;
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	m = d.size();
	ll r, g;
	cin >> g >> r;
	ll dp[m][g + 1];
	bool ok[m][g + 1];
	for (ll i = 0; i < m; i++)
		for (ll j = 0; j <= g; j++)
		{
			dp[i][j] = 1e18;
			ok[i][j] = false;
		}
	dp[0][0] = 0;
	deque<pair<ll, pair<ll, ll>>>Q;
	Q.push_back({0, {0, 0}});
	while (!Q.empty())
	{
		pair<ll, pair<ll, ll>>x = Q.front();
		ll i = x.second.first;
		ll j = x.second.second;
		Q.pop_front();
		if (ok[i][j])
			continue;
		ok[i][j] = true;
		if (j == g)
		{
			if (dp[i][0] > dp[i][g] + r)
			{
				dp[i][0] = dp[i][g] + r;
				Q.push_back({dp[i][0], {i, 0}});
			}
		}
		for (ll i1 : {i - 1, i + 1})
		{
			if (i1 < 0 || i1 >= m)
				continue;
			ll del = abs(d[i1] - d[i]);
			if (j + del <= g)
			{
				if (dp[i1][j + del] > dp[i][j] + del)
				{
					dp[i1][j + del] = dp[i][j] + del;
					Q.push_front({dp[i1][j + del], {i1, j + del}});
				}
			}
		}
	}
	ll ans = 1e18;
	bool gerai = false;
	for (ll i = 0; i <= g; i++)
	{
		if (ok[m - 1][i])
		{
			gerai = true;
			ans = min(ans, dp[m - 1][i]);
		}
	}
	if (gerai)
		cout << ans << "\n";
	else
		cout << "-1\n";
	return 0;
}