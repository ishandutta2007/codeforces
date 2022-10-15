/**
2 2 5000000
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD (1000000007ll)
#define mod(x) ((x+MOD)%MOD)
ll p[5000007];
ll F[5000007];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t, l, r;
	cin >> t >> l >> r;
	for (ll i = 0; i < r + 1; i++)
		p[i] = i;
	for (ll i = 2; i < min(ll(sqrtl(r) + 3), r + 1); i++)
		if (p[i] == i)
			for (ll j = i; j < r + 1; j += i)
				p[j] = min(p[j], i);
	F[1] = 0;
	for (ll n = 2; n <= r; n++)
	{
		ll x = p[n];
		F[n] = mod(F[n / x] + (x - 1) * n / 2);
	}
	ll ans = 0;
	ll exp = 1;
	for (ll k = l; k <= r; k++)
	{
		ans = mod(ans + exp * F[k]);
		exp = mod(exp * t);
	}
	cout << ans;
}