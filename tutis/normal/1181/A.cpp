/*input
6 8 2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll x, y, z;
	cin >> x >> y >> z;
	ll k = (x + y) / z;
	ll ans = min(x, y);
	if (x / z + y / z == k)
		ans = 0;
	else
	{
		ans = min(ans, x % z);
		ans = min(ans, y % z);
		ans = min(ans, z - (x % z));
		ans = min(ans, z - (y % z));
	}
	cout << k << " " << ans << "\n";
}