/*input
52 10 7
eTnmeHRmaTetSTsGqigLFYciMFLbwJHCScPRRIvxCFcevZVRmprk
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll f(bool a[], ll n, ll k, ll l)
{
	ll ans = 0;
	ld lo = 0;
	ld hi = l;
	ll kiek[n + 1];
	kiek[0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		kiek[i] = kiek[i - 1];
		if (a[i - 1])
			kiek[i]++;
	}
	ld x1 = 0;
	ld y1 = 0;
	ld z1 = -1e20;
	ld x2 = n;
	ld y2 = kiek[n];
	ld z2 = 1e20;
	while (abs(hi - lo) > 0.5 && abs(z1 - z2) > 1e-5)
	{
		ld c = (lo + hi) / 2;
		pair<ld, ll>dp[n + 1];
		dp[0] = {0, 0};
		for (ll i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1];
			ll j = max(i - l, 0ll);
			pair<ld, ll>a = dp[j];
			a.first -= c;
			a.second++;
			a.first += kiek[i] - kiek[j];
			dp[i] = max(dp[i], a);
		}
		pair<ld, ll>a = dp[n];
		a.first += c * a.second;
		ll x = round(a.first);
		if (a.second == k)
		{
			return x;
		}
		if (a.second < k)
		{
			ans = max(ans, x);
			hi = c;
			x1 = a.second;
			y1 = x;
			z1 = dp[n].first;
		}
		else
		{
			lo = c;
			x2 = a.second;
			y2 = x;
			z2 = dp[n].first;
		}
	}
	return max(ans, (ll)round(y1 + (y2 - y1) * ((k - x1) / (x2 - x1))));
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k, l;
	cin >> n >> k >> l;
	if (k * l >= n)
	{
		cout << "0\n";
		return 0;
	}
	string s;
	cin >> s;
	bool a[n];
	ll kt = 0;
	for (ll i = 0; i < n; i++)
	{
		if (islower(s[i]))
		{
			a[i] = true;
			kt++;
		}
		else
		{
			a[i] = false;
		}
	}
	ll ans = kt - f(a, n, k, l);
	for (ll i = 0; i < n; i++)
		a[i] = !a[i];
	kt = n - kt;
	ans = min(ans, kt - f(a, n, k, l));
	cout << ans << "\n";
}