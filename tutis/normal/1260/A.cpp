/*input
4
1 10000
10000 1
2 6
4 6

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
	int n;
	cin >> n;
	while (n--)
	{
		ll c, s;
		cin >> c >> s;
		ll a = s / c;
		s -= a * c;
		ll b = a + 1;
		ll kb = s;
		ll ka = c - kb;
		cout << a*a*ka + b*b*kb << "\n";
	}
}