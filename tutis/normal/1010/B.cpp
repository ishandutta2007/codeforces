/*input
5 2
1
-1
-1
1
0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	ll m, n;
	cin >> m >> n;
	bool meluoja[n];
	for (ll i = 0; i < n; i++)
	{
		cout << 1 << "\n" << flush;
		ll x;
		cin >> x;
		if (x == 0)
			exit(0);
		if (x == 1)
			meluoja[i] = false;
		else
			meluoja[i] = true;
	}
	ll lo = 1;
	ll hi = m;
	ll k = 0;
	while (lo <= hi)
	{
		ll m = (lo + hi) / 2;
		cout << m << "\n" << flush;
		ll x;
		cin >> x;
		if (x == 0)
			exit(0);
		if (meluoja[k])
			x *= -1;
		if (x == 1)
			lo = m + 1;
		else
			hi = m - 1;
		k = (k + 1) % n;
	}
}