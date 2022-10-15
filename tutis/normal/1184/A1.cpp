/*input
19

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ll r;
	cin >> r;
	for (ll x = 1; x * x <= r; x++)
	{
		ll y = (r - x - 1 - x * x) / (2 * x);
		if (x * x + 2 * y * x + x + 1 == r && y > 0)
		{
			cout << x << " " << y << endl;
			return 0;
		}
	}
	cout << "NO\n";
}