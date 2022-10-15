/***
3
1 1 2
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
ll F[1000009];
ll S[1000009];
ll n;
ll slow(ll A[])
{
	sort(A + 1, A + n + 1);
	ll ans = 0;
	map<ll, ll>X;
	while (next_permutation(A + 1, A + n + 1))
	{
		int f = 0;
		int M = 1;
		for (int i = 2; i <= n; i++)
		{
			if (A[M] < A[i])
			{
				X[A[M]]++;
				f += A[M], M = i;
			}
		}
		ans += f;
	}
	//for (pair<ll, ll>a : X)
	//	cout << a.first << " " << a.second << endl;
	return ans;
}
ll calc(ll n, ll i)
{
	return mod(n * mod(F[n - 1] * inv(n - i + 1)));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	F[0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		F[i] = mod(F[i - 1] * i);
	}
	ll A[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	sort(A + 1, A + n + 1);
	ll ans = 0;
	ll pask = 0;
	for (int i = 1; i <= n; i++)
	{
		if (A[i] == A[n])
			continue;
		if (i != 1 && A[i] == A[i - 1])
			ans = mod(ans + pask);
		else
		{
			//cout << calc(n, i) << " " << A[i] << endl;
			pask = mod(A[i] * calc(n, i));
			ans = mod(ans + pask);
		}
	}
	//cout << slow(A) << endl;
	cout << ans << endl;
}