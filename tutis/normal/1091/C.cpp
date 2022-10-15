/*input
16
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
	set<ll>V;
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			for (ll d : {i, n / i})
			{
				ll x = n / d;
				ll ans = x;
				ans += d * (x * (x - 1)) / 2;
				V.insert(ans);
			}
		}
	}
	for (ll i : V)
		cout << i << "\n";
}