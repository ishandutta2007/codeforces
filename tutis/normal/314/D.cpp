/*input
4
1 0
0 1
2 1
1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	pair<ll, ll>a[n];
	for (auto &i : a)
	{
		cin >> i.first >> i.second;
		i.first *= 2;
		i.second *= 2;
	}
	if (n <= 2)
	{
		cout << "0\n";
		return 0;
	}
	ll lo = 0;
	ll hi = 5e12;
	vector<pair<ll, ll>>idet;
	set<ll>tikX;
	for (ll i = 0; i < n; i++)
	{
		ll d = a[i].second - a[i].first;
		idet.emplace_back(d, i);
		tikX.insert(d);
		tikX.insert(d + 1);
		tikX.insert(d - 1);
	}
	sort(idet.begin(), idet.end());
	ll MX[n];
	ll MN[n];
	for (ll i = n - 1; i >= 0; i--)
	{
		ll j = idet[i].second;
		MX[i] = MN[i] = a[j].second + a[j].first;
		if (i != n - 1)
		{
			MX[i] = max(MX[i], MX[i + 1]);
			MN[i] = min(MN[i], MN[i + 1]);
		}
	}
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;
		bool ok = false;
		ll i = 0;
		ll j = 0;
		ll mn = 1e18;
		ll mx = -mn;
		for (ll x : tikX)
		{
			while (i < n && idet[i].first - mid * 2 <= x)
				i++;
			while (j < n && idet[j].first < x)
			{
				ll id = idet[j].second;
				mx = max(mx, a[id].second + a[id].first);
				mn = min(mn, a[id].second + a[id].first);
				j++;
			}
			ll mxx = mx;
			ll mnn = mn;
			if (i < n)
			{
				mxx = max(mxx, MX[i]);
				mnn = min(mnn, MN[i]);
			}
			if (mxx - mnn <= mid * 2)
			{
				ok = true;
				break;
			}
		}
		{
			ll A = 1e18;
			ll B = -A;
			for (int i = 0; i < n; i++)
			{
				A = min(A, a[i].first + a[i].second);
				B = max(B, a[i].first + a[i].second);
			}
			if (B - A <= 2 * mid)
				ok = true;
		}
		{
			ll A = 1e18;
			ll B = -A;
			for (int i = 0; i < n; i++)
			{
				A = min(A, a[i].first - a[i].second);
				B = max(B, a[i].first - a[i].second);
			}
			if (B - A <= 2 * mid)
				ok = true;
		}
		if (ok)
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << fixed << setprecision(15) << ld(lo) * 0.5 << "\n";
}