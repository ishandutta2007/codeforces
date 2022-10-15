/*input
3
1 5 3
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
	ll a[n + 1];
	a[0] = 0;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	vector<ll>ans;
	for (ll k = 1; k <= n; k++)
	{
		ll x[k];
		for (ll i = 0; i < k; i++)
			x[i] = a[i + 1] - a[i];
		ll b[n + 1];
		b[0] = 0;
		bool ok = true;
		for (ll i = 1; i <= n; i++)
		{
			b[i] = x[(i - 1) % k] + b[i - 1];
			if (b[i] != a[i])
				ok = false;
		}
		if (ok)
			ans.push_back(k);
	}
	cout << ans.size() << "\n";
	for (ll i : ans)
		cout << i << " ";
}