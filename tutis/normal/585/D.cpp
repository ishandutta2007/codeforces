/*input
7
0 8 9
5 9 -2
6 -8 -7
9 4 5
-4 -9 9
-4 5 2
-6 8 -7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void isvesk(ll msk, ll n)
{
	vector<string>ret;
	for (int i = 0; i < n; i++)
	{
		int k = msk % 3;
		if (msk % 3 == 0)
			ret.push_back("MW\n");
		if (msk % 3 == 1)
			ret.push_back("LW\n");
		if (msk % 3 == 2)
			ret.push_back("LM\n");
		msk /= 3;
	}
	reverse(ret.begin(), ret.end());
	for (string a : ret)
		cout << a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	ll b[n];
	ll c[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];
	map<pair<ll, ll>, pair<ll, ll>>X;
	ll x = 1;
	ll y = 1;
	for (int i = n / 2 - 1; i >= 0; i--)
		x *= 3;
	for (int i = n - 1; i >= n / 2; i--)
		y *= 3;
	for (ll msk = 0; msk < x; msk++)
	{
		ll suma = 0;
		ll sumb = 0;
		ll sumc = 0;
		ll Y = msk;
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			if (Y % 3 == 0)
			{
				sumb += b[i];
				sumc += c[i];
			}
			if (Y % 3 == 1)
			{
				suma += a[i];
				sumc += c[i];
			}
			if (Y % 3 == 2)
			{
				suma += a[i];
				sumb += b[i];
			}
			Y /= 3;
		}
		if (X.count({sumb - suma, sumc - suma}) == 0)
		{
			X[ {sumb - suma, sumc - suma}] = {suma, msk};
		}
		else
		{
			X[ {sumb - suma, sumc - suma}] = max(X[ {sumb - suma, sumc - suma}], {suma, msk});
		}
	}
	bool ok = false;
	pair<ll, pair<ll, ll>>ans = { -1e10, { -1e10, -1e10}};
	for (ll msk = 0; msk < y; msk++)
	{
		ll suma = 0;
		ll sumb = 0;
		ll sumc = 0;
		ll Y = msk;
		for (int i = n - 1; i >= n / 2; i--)
		{
			if (Y % 3 == 0)
			{
				sumb += b[i];
				sumc += c[i];
			}
			if (Y % 3 == 1)
			{
				suma += a[i];
				sumc += c[i];
			}
			if (Y % 3 == 2)
			{
				suma += a[i];
				sumb += b[i];
			}
			Y /= 3;
		}
		if (X.count({ -sumb + suma, -sumc + suma}))
		{
			ok = true;
			pair<ll, ll>xxx = X[ { -sumb + suma, -sumc + suma}];
			ans = max(ans, {suma + xxx.first, {xxx.second, msk}});
		}
	}
	if (ok)
	{
		isvesk(ans.second.first, n / 2);
		isvesk(ans.second.second, n - n / 2);
	}
	else
		cout << "Impossible\n";
}