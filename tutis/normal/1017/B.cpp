/*input
5
01011
11001
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	map<pair<ll, ll>, ll>X;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll c = a[i] - '0';
		ll d = b[i] - '0';
		for (pair<pair<ll, ll>, ll>x : X)
		{
			pair<ll, ll>OR1 = {c | d, x.first.first | x.first.second};
			pair<ll, ll>OR2 = {x.first.first | d, c | x.first.second};
			if (OR1 != OR2)
				ans += x.second;
		}
		X[ {c, d}]++;
	}
	cout << ans << "\n";
}