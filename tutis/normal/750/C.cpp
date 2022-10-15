/*input
3
-7 1
5 2
8 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll lo = -1e12;
	ll hi = 1e12;
	ll n;
	cin >> n;
	while (n--)
	{
		ll c, d;
		cin >> c >> d;
		if (d == 1)
			lo = max(lo, 1900ll);
		else
			hi = min(hi, 1899ll);
		if (lo > hi)
		{
			cout << "Impossible\n";
			return 0;
		}
		lo += c;
		hi += c;
	}
	if (hi > 1e10)
		cout << "Infinity\n";
	else
		cout << hi << "\n";
}