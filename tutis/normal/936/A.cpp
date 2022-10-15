/***
4 2 20
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ceil(ll a, ll b)
{
	return (a - 1) / b + 1;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll k, d, T;
	cin >> k >> d >> T;
	ll t = ceil(k, d);
	ll i = t * d - k;
	ld kepa = k + (d * t - k) / 2.0;
	ll kartu = floor(ld(T) / kepa);
	ld ans = kartu * (d * t);
	ld liko = T - kartu * kepa;
	if (liko <= k)
	{
		cout << fixed << setprecision(30) << ans + liko << "\n";
	}
	else
	{
		ans += k;
		liko -= k;
		cout << fixed << setprecision(30) << ans + liko * 2 << "\n";
	}
}