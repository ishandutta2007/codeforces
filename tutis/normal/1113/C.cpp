/*input
3
42 4 2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	map<ll, ll>K[2];
	K[1][0] = 1;
	ll X = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		X ^= a;
		ans += K[i % 2][X];
		K[i % 2][X]++;
	}
	cout << ans << "\n";
}