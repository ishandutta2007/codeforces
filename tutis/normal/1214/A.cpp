/*input
600
60
70

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, d, e;
	cin >> n >> d >> e;
	e *= 5;
	ll ans = min((n % e) % d, (n % d) % e);
	for (ll x = 0; x <= n && x <= 100000; x += e)
	{
		ll liko = n - x;
		ans = min(ans, min((liko % e) % d, (liko % d) % e));
	}
	cout << ans << "\n";
}