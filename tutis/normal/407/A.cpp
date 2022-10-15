/*input
5 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll a, b;
	cin >> a >> b;
	for (ll x = 1; x <= 1000; x++)
	{
		for (ll y = 1; y <= 1000; y++)
		{
			if (x * x + y * y == a * a)
			{
				ll z = -y;
				ll t = x;
				ll g = __gcd(abs(z), abs(t));
				z /= g;
				t /= g;
				ll k = max(1ll, ll(round(sqrt(ld(b * b) / ld(z * z + t * t)))));
				z *= k;
				t *= k;
				if (z * z + t * t == b * b && x != z && y != t)
				{
					cout << "YES\n0 0\n";
					cout << x << " " << y << "\n";
					cout << z << " " << t << "\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
}