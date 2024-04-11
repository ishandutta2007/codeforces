/*input
5
10 30 5 6 24
10 41 7 8 24
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[101], b[101];
pair<ll, ll>mem[101][20202];
pair<ll, ll> dp(ll i, ll dV)
{
	pair<ll, ll>ret = {1e9, 1e9};
	if (i == -1)
	{
		if (dV == 0)
			return {0, 0};
		else
			return ret;
	}
	if (mem[i][dV + 10000].first != 0)
		return mem[i][dV + 10000];
	for (ll c = 0; c <= b[i]; c++)
	{
		pair<ll, ll>x = dp(i - 1, dV - c + a[i]);
		x.second += abs(c - a[i]);
		if (c > 0)
			x.first++;
		ret = min(ret, x);
	}
	return mem[i][dV + 10000] = ret;
}
int main()
{
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	pair<ll, ll>ans = dp(n - 1, 0);
	cout << ans.first << " " << ans.second / 2 << "\n";
	return 0;
}