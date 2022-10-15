/*input
2
2 5
-6 4
7 -2
-1 -3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll x[n], y[n];
	for (ll i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	ll a[n], b[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	vector<pair<ll, ll>>YY;
	for (ll i = 0; i < n; i++)
		YY.push_back({a[i], b[i]});
	sort(YY.begin(), YY.end());
	for (ll c = 0; c < n; c++)
	{
		ll X = x[0] + a[c];
		ll Y = y[0] + b[c];
		vector<pair<ll, ll>>XX;
		for (ll i = 0; i < n; i++)
			XX.push_back({X - x[i], Y - y[i]});
		sort(XX.begin(), XX.end());
		if (XX == YY)
		{
			cout << X << " " << Y << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}