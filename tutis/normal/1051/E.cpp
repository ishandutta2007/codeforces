/*input
8698272232067125804692796793285996652907461532074057999849092982935510140661249431760679611642931478
6
68270
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 998244353ll;
ll PWR[1000009];
int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a, l, r;
	cin >> a >> l >> r;
	ll DP[a.size() + 1];
	ll DPSUM[a.size() + 1];
	fill_n(DPSUM, a.size() + 1, 0);
	fill_n(DP, a.size() + 1, 0);
	DPSUM[a.size()] = 1;
	DP[a.size()] = 1;
	ll w = rand() + 1054;
	PWR[0] = 1;
	for (ll t = 1; t < 1000009; t++)
		PWR[t] = (PWR[t - 1] * w) % modulo;
	ll HA[a.size()];
	ll HL[l.size()];
	ll HR[r.size()];
	HA[0] = (((ll)(a[0] - '0' + 1)) * PWR[0]) % modulo;
	HL[0] = (((ll)(l[0] - '0' + 1)) * PWR[0]) % modulo;
	HR[0] = (((ll)(r[0] - '0' + 1)) * PWR[0]) % modulo;
	for (ll t = 1; t < a.size(); t++)
	{
		HA[t] = HA[t - 1] + ((ll)(a[t] - '0' + 1)) * PWR[t];
		HA[t] %= modulo;
	}
	for (ll t = 1; t < l.size(); t++)
	{
		HL[t] = HL[t - 1] + ((ll)(l[t] - '0' + 1)) * PWR[t];
		HL[t] %= modulo;
	}
	for (ll t = 1; t < r.size(); t++)
	{
		HR[t] = HR[t - 1] + ((ll)(r[t] - '0' + 1)) * PWR[t];
		HR[t] %= modulo;
	}
	auto HASHA = [&](ll l, ll r)->ll
	{
		ll ret = HA[r];
		if (l - 1 >= 0)
			ret -= HA[l - 1];
		ret %= modulo;
		ret += modulo;
		ret %= modulo;
		ret *= PWR[1000004 - r];
		ret %= modulo;
		return ret;
	};
	for (int t = 0; t < l.size(); t++)
		HL[t] = (HL[t] * PWR[1000004 - t]) % modulo;
	for (int t = 0; t < r.size(); t++)
		HR[t] = (HR[t] * PWR[1000004 - t]) % modulo;
	for (ll i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] == '0')
		{
			if (l == "0")
			{
				DP[i] = DP[i + 1];
				DPSUM[i] = DPSUM[i + 1] + DP[i];
				DPSUM[i] % modulo;
				continue;
			}
			DP[i] = 0;
			DPSUM[i] = DPSUM[i + 1] + DP[i];
			continue;
		}
		ll j1 = i + l.size() + 1;
		ll j2 = i + r.size() - 1;
		j2 = min(j2, (ll)(a.size()));
		DP[i] = 0;
		if (j1 <= j2)
		{
			DP[i] += DPSUM[j1];
			if (j2 + 1 <= a.size())
				DP[i] -= DPSUM[j2 + 1];
		}
		bool okl = true;
		bool okr = true;
		if (i + l.size() > a.size())
			okl = false;
		if (i + r.size() > a.size())
			okr = false;
		if (okl)
		{
			ll lo = 0;
			ll hi = l.size() - 1;
			while (lo < hi)
			{
				ll sz = (lo + hi) / 2;
				if (HASHA(i, i + sz) == HL[sz])
					lo = sz + 1;
				else
					hi = sz;
			}
			ll sz = (lo + hi) / 2;
			okl &= (a[i + sz] >= l[sz]);
		}
		if (okr)
		{
			ll lo = 0;
			ll hi = r.size() - 1;
			while (lo < hi)
			{
				ll sz = (lo + hi) / 2;
				if (HASHA(i, i + sz) == HR[sz])
					lo = sz + 1;
				else
					hi = sz;
			}
			ll sz = (lo + hi) / 2;
			if (sz < r.size())
				okr &= (a[i + sz] <= r[sz]);
		}
		if (l.size() == r.size())
		{
			if (okl && okr)
			{
				DP[i] += DP[i + l.size()];
			}
		}
		else
		{
			if (okl)
			{
				DP[i] += DP[i + l.size()];
			}
			if (okr)
			{
				DP[i] += DP[i + r.size()];
			}
		}
		DP[i] %= modulo;
		DP[i] += modulo;
		DP[i] %= modulo;
		DPSUM[i] = DPSUM[i + 1] + DP[i];
		DPSUM[i] %= modulo;
	}
	cout << DP[0] << "\n";
}