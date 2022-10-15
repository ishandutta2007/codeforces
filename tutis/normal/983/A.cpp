/*input
4
1 1 2
9 36 2
4 12 3
3 5 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		ll p, q, b;
		cin >> p >> q >> b;
		if (p == 0)
		{
			cout << "Finite\n";
			continue;
		}
		ll g = __gcd(p, q);
		p /= g;
		q /= g;
		ll Q = q;
		while (Q > 1)
		{
			ll x = __gcd(Q, b);
			if (x == 1)
				break;
			while (Q % x == 0)
				Q /= x;
		}
		if (Q == 1 || q == 1)
		{
			cout << "Finite\n";
			continue;
		}
		cout << "Infinite\n";
	}
}