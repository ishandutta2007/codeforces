/*input
4
5 1
1 1 2 3 1
4 2
6 4 8 5
2 2
1 6
3 5
5 2 5
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
		ll n, k;
		cin >> n >> k;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll lo = 1;
		ll hi = 1e18;
		for (int i = 0; i < n; i++)
		{
			lo = max(lo, a[i] - k);
			hi = min(hi, a[i] + k);
		}
		if (lo <= hi)
			cout << hi << "\n";
		else
			cout << "-1\n";
	}
}