/*input
4 2
6 3 8 1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	deque<ll>p;
	ll MAX_P = 2000000000000000000;
	ld MAX_Pd = 3e18;
	ll ans = 0;
	ll viens[n + 1];
	viens[0] = 0;
	ll suma[n];
	suma[0] = a[0];
	for (ll i = 1; i < n; i++)
		suma[i] = suma[i - 1] + a[i];
	for (ll i = 0; i < n; i++)
	{
		if (a[i] != 1)
		{
			viens[i + 1] = i + 1;
		}
		else
		{
			viens[i + 1] = viens[i];
		}
	}
	for (ll r = 0; r < n; r++)
	{
		if (a[r] != 1)
		{
			p.push_front(r);
			while (p.size() > 64)
				p.pop_back();
			ll sand = 1;
			ld sandd = 1;
			for (ll l : p)
			{
				sand *= a[l];
				sandd *= ld(a[l]);
				if (sandd >= MAX_Pd)
					break;
				if (sand >= MAX_P)
					break;
				ll l_ = viens[l];
				if (sand % k != 0)
					continue;
				ll s = sand / k;
				ll maziaus = suma[r];
				if (l - 1 >= 0)
					maziaus -= suma[l - 1];
				ll didziaus = suma[r];
				if (l_ - 1 >= 0)
					didziaus -= suma[l_ - 1];
				if (maziaus <= s && s <= didziaus)
					ans++;
			}
		}
		else
		{
			if (k == 1)
				ans++;
			ll sand = 1;
			ld sandd = 1;
			for (ll l : p)
			{
				sand *= a[l];
				sandd *= ld(a[l]);
				if (sandd >= MAX_Pd)
					break;
				if (sand >= MAX_P)
					break;
				ll l_ = viens[l];
				if (sand % k != 0)
					continue;
				ll s = sand / k;
				ll maziaus = suma[r];
				if (l - 1 >= 0)
					maziaus -= suma[l - 1];
				ll didziaus = suma[r];
				if (l_ - 1 >= 0)
					didziaus -= suma[l_ - 1];
				if (maziaus <= s && s <= didziaus)
					ans++;
			}
		}
	}
	cout << ans << "\n";
}