/*input
6
5 2 3
100 1 4
1 10 5
1000000000 1 6
1 1 1000000000
1 1 999999999
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll a, b, k;
		cin >> a >> b >> k;
		if (k % 2 == 1)
		{
			ll c = k / 2;
			cout << a * c - b * c + a << "\n";
		}
		else
		{
			ll c = k / 2;
			cout << a * c - b * c << "\n";
		}
	}
}