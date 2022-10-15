/***
1000000000 5000
7 3
6 3
5 3
4 3
3 3
2 3
1 3
0 3
499 3
500 3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (1000000007ll)
ll mod(ll x)
{
	x %= MOD;
	x += MOD;
	x %= MOD;
	return x;
}
ll power(ll a, ll p)
{
	p %= (MOD - 1);
	p += (MOD - 1);
	p %= (MOD - 1);
	a = mod(a);
	ll k = 1;
	ll ret = 1;
	while (k <= p)
	{
		if (k & p)
			ret = (ret * a) % MOD;
		k *= 2;
		a = (a * a) % MOD;
	}
	return ret;
}
ll inv(ll x)
{
	return power(x, MOD - 2);
}
ll F[1000000];
ll iF[1000000];
ll C(ll n, ll k)
{
	return mod(F[n] * mod(iF[k] * iF[n - k]));
}
ll P[1000000];
ll P_[5009][5009];
ll ANS(ll n, ll k)
{
	ll ans = 0;
	for (ll x = 0; x <= n; x++)
	{
		ans = (ans + P_[x][k] * C(n, x)) % MOD;
	}
	if (0 <= k - n && k - n < 10000)
		return mod(ans * P[k - n]);
	return mod(ans * 500000004);
}
ll ans(ll n, ll k)
{
	if (n > k + 1)
	{
		ll y[k + 1];
		for (int i = 0; i <= k; i++)
		{
			y[i] = ANS(i + 1, k);
		}
		ll ans = 0;
		for (ll j = 0; j <= k; j++)
		{
			ll a = y[j];
			ll b = 1;
			for (ll k_ = 0; k_ <= k; k_++)
			{
				if (j == k_)
					continue;
				a = mod(a * (n - (k_ + 1)));
				b = mod(b * ((j + 1) - (k_ + 1)));
			}
			ans = mod(ans + a * inv(b));
		}
		return ans;
	}
	return ANS(n, k);
}
int main()
{
	P[0] = 1;
	F[0] = 1;
	for (int i = 0; i < 5009; i++) {
		P_[i][0] = 1;
		for (int k = 1; k < 5009; k++)
			P_[i][k] = mod(P_[i][k - 1] * i);
	}
	for (int i = 1; i < 10000; i++) {
		F[i] = mod(F[i - 1] * i);
		P[i] = mod(2 * P[i - 1]);
	}
	for (int i = 0; i < 10000; i++)
		iF[i] = inv(F[i]);
	int n, k;
	while (cin >> n >> k)
		cout << mod(power(2, n - k) * ans(n, k)) << endl;
}