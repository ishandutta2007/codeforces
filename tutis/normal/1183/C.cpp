/*input
6
15 5 3 2
15 5 4 3
15 5 2 1
15 5 5 1
16 7 5 2
20 5 7 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		ll k, n, a, b;
		cin >> k >> n >> a >> b;
		ll lo = 0;
		ll hi = n;
		while (lo < hi)
		{
			ll x = (lo + hi + 1) / 2;
			if (k - x * a - (n - x) * b > 0)
				lo = x;
			else
				hi = x - 1;
		}
		ll x = (lo + hi) / 2;
		if (k - x * a - (n - x) * b <= 0)
			x = -1;
		cout << x << "\n";
	}


}