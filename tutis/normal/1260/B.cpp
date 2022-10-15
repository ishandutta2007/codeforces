/*input
3
6 9
1 1
1 2
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
		ll a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		if (b > a * 2 || ((a + b) % 3 != 0))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}