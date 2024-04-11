/*input
5
12
5 4 4 3 2 2 1 1 1 1 1 1
4
4 3 2 1
1
1000000
20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
32
64 64 63 58 58 58 58 58 37 37 37 37 34 34 28 28 28 28 28 28 24 24 19 17 17 17 17 16 16 16 16 11
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll p[n];
		for (ll i = 0; i < n; i++)
			cin >> p[i];
		if (n < 6)
		{
			cout << "0 0 0\n";
			continue;
		}
		ll k = n / 2;
		ll k1 = k;
		while (k > 0 && p[k - 1] == p[k1])
			k--;
		set<ll>sk;
		for (ll i = 3; i < k; i++)
			if (p[i] != p[i - 1])
				sk.insert(i);
		sk.insert(1e9);
		for (ll g = 1; g < k; g++)
		{
			if (p[g] == p[g - 1])
				continue;
			ll gs = *sk.upper_bound(2 * g);
			ll b = k - gs;
			ll s = gs - g;
			if (g > 0 && s > 0 && b > 0 && g < s && g < b)
			{
				cout << g << " " << s << " " << b << "\n";
				goto X;
			}
		}
		cout << "0 0 0\n";
X:;
	}
}