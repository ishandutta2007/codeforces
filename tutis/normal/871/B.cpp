/***
3
0
0
3
2
3
2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll X[5000][5000];
ll n;
ll XOR(ll i, ll j)
{
	if (X[i][j] != -1)
		return X[i][j];
	cout << "? " << i << " " << j << "\n" << flush;
	cin >> X[i][j];
	return X[i][j];
}
bool good(ll p[], ll id, ll a)
{
	// p[0]=a;
	// b[id]=a
	ll b[n];
	for (ll i = 0; i < n; i++)
	{
		if (p[i] >= n)
			return false;
		b[p[i]] = i;
	}
	for (ll j = 0; j < n; j++)
	{
		if (XOR(0, j) != (p[0]^b[j]))
			return false;
	}
	for (ll i = 0; i < n; i++)
	{
		if (XOR(i, id) != (p[i]^b[id]))
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	ll id = 0;
	for (int i = 0; i < 5000; i++)
		for (int j = 0; j < 5000; j++)
			X[i][j] = -1;
	for (ll j = 0; j < n; j++)
	{
		if (XOR(0, j) == 0)
		{
			id = j;
		}
	}
	ll ans = 0;
	ll p[n];
	ll c[n];
	for (ll a = 0; a < n; a++)
	{
		// p[0]=a;
		// b[id]=a
		for (ll i = 0; i < n; i++)
		{
			ll x = XOR(i, id);
			p[i] = x ^ a;
		}
		if (good(p, id, a))
		{
			ans++;
			for (ll i = 0; i < n; i++)
				c[i] = p[i];
		}
	}
	cout << "!\n" << ans << "\n" << flush;
	for (ll i = 0; i < n; i++)
		cout << c[i] << " " << flush;
	return 0;
}