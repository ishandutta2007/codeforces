/*input
4
29 34 19 38

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
	int t;
	cin >> t;
	while (t--)
	{
		ll x;
		cin >> x;
		bool ok = false;
		for (int t = 1; t <= 6; t++)
		{
			ll top = 21 - t;
			if (x >= top)
			{
				ll a = x - top;
				if (a % 14 == 0)
					ok = true;
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}