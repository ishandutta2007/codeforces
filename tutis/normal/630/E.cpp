/*input
1 0 5 6
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if ((x1 + y1) % 2 == 0)
	{
		ll k1 = (y2 - y1 + 2) / 2;
		ll k2 = (y2 - y1 + 1) / 2;
		cout << k1 *((x2 - x1) / 2 + 1) + k2*((x2 - x1) / 2) << "\n";
	}
	else
	{
		ll k1 = (y2 - y1 + 1) / 2;
		ll k2 = (y2 - y1 + 2) / 2;
		cout << k1 *((x2 - x1) / 2 + 1) + k2*((x2 - x1) / 2) + 1 << "\n";
	}
}