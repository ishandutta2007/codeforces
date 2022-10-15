/*input
4
1 3 4
1 10 100
10000000000000000 10000000000000000 10000000000000000
23 34 45

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--)
	{
		ll a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << (a[0] + a[1] + a[2]) / 2 << "\n";
	}
}