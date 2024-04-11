/*input
3 2
1 3 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	map<ll, ll>K;
	ll XOR = 0;
	K[0]++;
	for (ll &i : a)
	{
		XOR ^= i;
		ll c = min(XOR, XOR ^ ((1ll << k) - 1));
		K[c]++;
	}
	ll ans = n * (n + 1) / 2;
	for (pair<ll, ll>i : K)
	{
		ll c = i.second;
		ll a = c / 2;
		ll b = c - a;
		ll mini = a * (a - 1) / 2 + b * (b - 1) / 2;
		ans -= mini;
	}
	cout << ans << "\n";
}