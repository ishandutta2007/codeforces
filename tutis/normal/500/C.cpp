/*input
3 5
1 2 3
1 3 2 3 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll w[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> w[i];
	ll b[m];
	for (ll i = 0; i < m; i++)
		cin >> b[i];
	ll p[n + 1];
	fill_n(p, n + 1, 1000000);
	for (ll i = m - 1; i >= 0; i--)
		p[b[i]] = i;
	ll ans = 0;
	for (ll t = 0; t < m; t++)
	{
		for (ll j = 1; j <= n; j++)
		{
			if (p[j] < p[b[t]])
				ans += w[j];
		}
		p[b[t]] = -t - 1;
	}
	cout << ans << "\n";
}