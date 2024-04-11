/*input
1 30 200

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll C(ll n, ll k)
{
	if (k > n || k < 0)
		return 0;
	ll s = 1;
	ll f = 1;
	for (int i = 0; i < k; i++)
		f *= i + 1;
	for (int i = 0; i < k; i++)
	{
		ll x = n - i;
		ll g = __gcd(x, f);
		f /= g;
		x /= g;
		s *= x;
	}
	s /= f;
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ld a, b, c;
	cin >> a >> b >> c;
	ld D = sqrtl(b * b - 4 * a * c);
	ld x1 = (-b + D) / (2 * a);
	ld x2 = (-b - D) / (2 * a);
	if (x1 < x2)
		swap(x1, x2);
	cout << fixed << setprecision(20) << x1 << "\n" << x2 << "\n";
}