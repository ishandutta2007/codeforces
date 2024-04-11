/*input
4
1
100
50 1
49 1
100
8
100 200 100 200 100 200 100 100
10 2
15 3
107
3
1000000000 1000000000 1000000000
50 1
50 1
3000000000
5
200 100 100 100 100
69 5
31 2
90

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		ll p[n + 1];
		for (ll i = 1; i <= n; i++)
		{
			cin >> p[i];
			p[i] /= 100;
		}
		sort(p + 1, p + n + 1, greater<ll>());
		ll x, a;
		cin >> x >> a;
		ll y, b;
		cin >> y >> b;
		ll k;
		cin >> k;
		ll q[n + 1];
		fill_n(q, n + 1, 0ll);
		for (ll i = 0; i <= n; i += a)
			q[i] += x;
		for (ll i = 0; i <= n; i += b)
			q[i] += y;
		auto f = [&](ll k)
		{
			assert(1 <= k && k <= n);
			vector<ll>aa;
			vector<ll>bb;
			for (ll i = 1; i <= k; i++)
			{
				aa.push_back(q[i]);
				bb.push_back(p[i]);
			}
			sort(aa.begin(), aa.end(), greater<ll>());
			ll r = 0;
			for (ll i = 0; i < aa.size(); i++)
				r += aa[i] * bb[i];
			return r;
		};
		if (f(n) < k)
		{
			cout << "-1\n";
			continue;
		}
		ll lo = 1;
		ll hi = n;
		while (lo < hi)
		{
			ll m = (lo + hi) / 2;
			if (f(m) >= k)
				hi = m;
			else
				lo = m + 1;
		}
		cout << lo << "\n";
	}
}