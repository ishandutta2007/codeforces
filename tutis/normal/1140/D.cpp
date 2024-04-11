/*input
3
4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	while (cin >> n)
	{
		ll ans = 0;
		for (ll i = n; i >= 3; i--)
			ans += i * (i - 1);
		cout << ans << "\n";
	}
}