/*input
3
1 11
4 2
191 31415926
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		ll A, B;
		cin >> A >> B;
		ll ans = 0;
		for (ll w = 1; w <= B; w *= 10)
		{
			ll lo = w;
			ll hi = min(B, w * 10 - 1);
			ll b = 10 * w - 1;
			if (lo <= b && b <= hi)
				ans += A;
		}
		cout << ans << "\n";
	}
}