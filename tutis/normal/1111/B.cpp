/*input
2 4 6
4 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k, m;
	cin >> n >> k >> m;
	vector<ll>a(n);
	for (ll &i : a)
		cin >> i;
	sort(a.begin(), a.end(), greater<ll>());
	ld ans = 0;
	ll suma = 0;
	for (ll sz = 1; sz <= n; sz++)
	{
		suma += a[sz - 1];
		m -= (n - sz);
		if (m >= 0)
		{
			ll maxi = sz * k;
			ll prid = min(maxi, m);
			ans = max(ans, ld(suma + prid) / sz);
		}
		m += (n - sz);
	}
	cout << fixed << setprecision(15) << ans << "\n";
}