/*input
3
3 3 3
1 5 2
2 1 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		ll a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		ll n = a[0] + a[1] + a[2];
		if (a[2] > (n + 1) / 2)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
	}
}