/***
3 4 11
1 2 3 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k, M;
	cin >> n >> k >> M;
	ll t[k];
	for (ll i = 0; i < k; i++)
		cin >> t[i];
	sort(t, t + k);
	ll task = 0;
	for (ll i = 0; i < k; i++)
		task += t[i];
	ll ats = 0;
	for (ll solved = 0; solved <= n; solved++)
	{
		ll ans = 0;
		ll m = M;
		ll z = 0;
		while (task <= m && z < solved)
		{
			m -= task;
			z++;
			ans += k + 1;
		}
		if (z == solved)
		{
			multiset<ll>X;
			for (ll i = 0; i < n - solved; i++)
				for (ll j = 0; j < k; j++)
					X.insert(t[j]);
			while (!X.empty() && (*X.begin()) <= m)
			{
				m -= (*X.begin());
				X.erase(X.begin());
				ans++;
			}
			ats = max(ats, ans);
		}
	}
	cout << ats;
}