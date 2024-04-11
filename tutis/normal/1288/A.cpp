/*input
3
1 1
4 5
5 11
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
	int T;
	cin >> T;
	while (T--)
	{
		ll n, d;
		cin >> n >> d;
		ll x = 0;
		while (x + (d - 1) / (x + 1) + 1 > n && x <= 1000000)
			x++;
		if (x >= 1000000)
			cout << "NO\n";
		else
			cout << "YES\n";
	}


}