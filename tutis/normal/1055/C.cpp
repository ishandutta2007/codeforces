/*input
0 2 5
1 3 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll lb, rb, tb;
ll ans = 0;
const ll delta = 100;
ll answer(ll L, ll R)
{
	ll ret = -2e18;
	vector<ll>k;
	for (ll k_ = - delta; k_ <= delta; k_++)
		k.push_back(k_);
	{
		ll K = (L - lb) / tb;
		for (ll k_ = K - delta; k_ <= K + delta; k_++)
			k.push_back(k_);
	}
	{
		ll K = (R - lb) / tb;
		for (ll k_ = K - delta; k_ <= K + delta; k_++)
			k.push_back(k_);
	}
	{
		ll K = (L - rb) / tb;
		for (ll k_ = K - delta; k_ <= K + delta; k_++)
			k.push_back(k_);
	}
	{
		ll K = (R - rb) / tb;
		for (ll k_ = K - delta; k_ <= K + delta; k_++)
			k.push_back(k_);
	}
	for (ll K : k)
	{
		ll l = max(lb + K * tb, L);
		ll r = min(rb + K * tb, R);
		ret = max(ret, r - l + 1);
	}
	ans = max(ans, ret);
	return ret;
}
int main()
{
	clock_t pradz = 0;
	ios_base::sync_with_stdio(false);
	ll la, ra, ta;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	if (la - lb <= 0)
	{
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	rb -= lb;
	ra -= lb;
	la -= lb;
	lb -= lb;
	ll T = __gcd(ta, tb);
	{
		ll k = (-la) / T;
		for (ll x = k - 100; x <= k + 100; x++)
			answer(x * T + la, x * T + ra);
	}
	{
		ll k = (tb - la) / T;
		for (ll x = k - 100; x <= k + 100; x++)
			answer(x * T + la, x * T + ra);
	}
	cout << ans << "\n";
}