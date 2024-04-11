/*input
8 8 0 2 8 3 4 5
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
	ld px, py, vx, vy;
	cin >> px >> py >> vx >> vy;
	ld r = sqrtl(vx * vx + vy * vy);
	vx /= r;
	vy /= r;
	ld a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(12) << px + vx*b << " " << py + vy*b << "\n";
	cout << fixed << setprecision(12) << px - vy*a / 2 << " " << py + vx*a / 2 << "\n";
	cout << fixed << setprecision(12) << px - vy*c / 2 << " " << py + vx*c / 2 << "\n";
	cout << fixed << setprecision(12) << px - vy*c / 2 - vx*d << " " << py + vx*c / 2 - vy*d << "\n";
	cout << fixed << setprecision(12) << px + vy*c / 2 - vx*d << " " << py - vx*c / 2 - vy*d << "\n";
	cout << fixed << setprecision(12) << px + vy*c / 2 << " " << py - vx*c / 2 << "\n";
	cout << fixed << setprecision(12) << px + vy*a / 2 << " " << py - vx*a / 2 << "\n";
}