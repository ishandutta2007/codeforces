/***
4 7 10
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
bool ok(ll x, ll n, ll a, ll b)
{
	a -= x;
	b -= x;
	for (int i = 3; i <= n; i++)
	{
		if (a >= x)
		{
			a -= x;
		}
		else
		{
			b -= x;
		}
	}
	return a >= 0 && b >= 0;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, a, b;
	cin >> n >> a >> b;
	for (int x = 1000; x >= 0; x--)
	{
		if (ok(x, n, a, b))
		{
			cout << x;
			return 0;
		}
	}
}