/*input
6 1
2 1 2 3 4 3
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, I;
	cin >> n >> I;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll>b = a;
	b.erase(unique(b.begin(), b.end()), b.end());
	ll k = min((I * 8) / n, 35ll);
	ll kiek = (1ll << k);
	ll ans = n;
	if (kiek >= (ll)b.size())
		ans = 0;
	for (ll l = 0; l + kiek - 1 < (ll)b.size(); l++)
	{
		ll r = l + kiek - 1;
		ll gal = lower_bound(a.begin(), a.end(), b[l]) - a.begin();
		gal += a.end() - upper_bound(a.begin(), a.end(), b[r]);
		ans = min(ans, gal);
	}
	cout << ans << "\n";
}