/*input
6
6 90 12 18 30 18

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	ll G = 0;
	for (ll &i : a)
		G = __gcd(G, i);
	ll ret = 0;
	for (ll i = 1; i * i <= G; i++)
	{
		if (G % i == 0)
		{
			ret += 2;
			if (i * i == G)
				ret--;
		}
	}
	cout << ret << "\n";
}