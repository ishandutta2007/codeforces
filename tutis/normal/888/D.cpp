/*input
5 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll C(ll n, ll k)
{
	if (n < 0 || k < 0 || n - k < 0)
		return 0;
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	if (k == 2)
		return n * (n - 1) / 2;
	if (k == 3)
		return n * (n - 1) * (n - 2) / 6;
	if (k == 4)
		return n * (n - 1) * (n - 2) * (n - 3) / 24;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	ll n, k;
	cin >> n >> k;
	ll ans = 1;
	for (ll c = 1; c <= k; c++)
	{
		ll m = 0;
		vector<ll>x(c);
		for (ll i = 0; i < c; i++)
			x[i] = i;
		do
		{
			ll kiek = 0;
			for (ll i = 0; i < c; i++)
				if (x[i] != i)
					kiek++;
			if (kiek == c)
				m++;
		} while (next_permutation(x.begin(), x.end()));
		ans += m * C(n, c);
	}
	cout << ans << "\n";
}