/*input
5
1 1 1 1 1
1 0 1 0 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll sum = 0;
	for (ll w : {1ll, -1ll})
	{
		ll m = n;
		while (m--)
		{
			ll a;
			cin >> a;
			sum += a * w;
		}
	}
	if (sum >= 0)
		cout << "Yes\n";
	else
		cout << "No\n";
}