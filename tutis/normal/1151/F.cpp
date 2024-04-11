/*input
6 4
1 0 0 1 1 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll k0, k1, n;
ll V[103];
ll W[103];
ll A[103][103];
ll B[103][103];
const ll modulo = 1000000007;
void dauginam()
{
	for (ll i = 0; i <= n; i++)
		W[i] = 0;
	for (ll i = 0; i <= n; i++)
		for (ll j = 0; j <= n; j++)
		{
			W[j] += V[i] * A[i][j];
			W[j] %= modulo;
		}
	for (ll i = 0; i <= n; i++)
		V[i] = W[i];
}
ll power(ll a, ll b)
{
	a %= modulo;
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % modulo;
	ll c = power(a, b / 2);
	return (c * c) % modulo;
}
ll inv(ll x)
{
	return power(x, modulo - 2);
}
void skaiciuojam()
{
	for (ll k01 = 0; k01 <= k0 && k01 <= k1; k01++)
	{
		ll a = k0 - k01;
		ll b = k01;
		ll c = k01;
		ll d = k1 - k01;
		ll viso = n * (n - 1) / 2;
		viso -= a * d;
		viso -= b * c;
		A[k01][k01] += viso;
		A[k01][k01 + 1] += a * d;
		if (k01 > 0)
			A[k01][k01 - 1] += b * c;
	}
	ll Q = inv(n * (n - 1) / 2);
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			A[i][j] %= modulo;
			A[i][j] *= Q;
			A[i][j] %= modulo;
		}
	}
}
void kvadratu()
{
	for (ll i = 0; i <= 50; i++)
		for (ll j = 0; j <= 50; j++)
			B[i][j] = 0;
	for (ll i = 0; i <= 50; i++)
		for (ll j = 0; j <= 50; j++)
			for (ll k = 0; k <= 50; k++)
			{
				B[i][j] += A[i][k] * A[k][j];
				B[i][j] %= modulo;
			}
	for (ll i = 0; i <= 50; i++)
		for (ll j = 0; j <= 50; j++)
			A[i][j] = B[i][j];
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll b[n];
	for (ll i = 0; i < n; i++)
		b[i] = a[i];
	sort(b, b + n);
	k0 = 0;
	k1 = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] == 0)
			k0++;
		else
			k1++;
	}
	ll k01 = 0;
	for (ll i = 0; i < n; i++)
		if (a[i] == 0 && b[i] == 1)
			k01++;
	V[k01]++;
	ll c = 1;
	skaiciuojam();
	while (k > 0)
	{
		if ((c & k) > 0)
		{
			k -= c;
			dauginam();
		}
		c *= 2;
		kvadratu();
	}
	cout << V[0] << "\n";
}