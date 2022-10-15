/*input
6
1 5
3 3
4 4
9 2
10 1
12 1
4
1 2
2 4
2 5
2 6

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll xx[202020][20];
ll dx[202020][20];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll p[n + 1], l[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> p[i] >> l[i];
	ll iki[n + 1];
	deque<pair<ll, ll>>X;
	for (ll i = n; i >= 1; i--)
	{
		iki[i] = p[i] + l[i];
		auto it = upper_bound(X.begin(), X.end(), make_pair(p[i] + l[i] + 1, -2ll));
		if (it != X.begin())
		{
			it--;
			iki[i] = max(iki[i], it->second);
		}
		while (!X.empty() && X.front().second <= iki[i])
			X.pop_front();
		X.push_front({p[i], iki[i]});
	}
	ll q;
	cin >> q;
	for (ll i = 1; i <= n; i++)
	{
		ll pos = iki[i];
		if (iki[i] < p[n])
		{
			ll j = (lower_bound(p + 1, p + (n + 1), pos)) - (p);
			xx[i][0] = j;
			dx[i][0] = p[j] - pos;
		}
		else
		{
			xx[i][0] = n;
			dx[i][0] = 0;
		}
	}
	for (ll t = 1; t < 20; t++)
	{
		for (ll i = 1; i <= n; i++)
		{
			xx[i][t] = xx[xx[i][t - 1]][t - 1];
			dx[i][t] = dx[i][t - 1] + dx[xx[i][t - 1]][t - 1];
		}
	}
	while (q--)
	{
		ll x, y;
		cin >> x >> y;
		if (iki[x] >= p[y])
		{
			cout << "0\n";
			continue;
		}
		ll ans = 0;
		for (ll t = 19; t >= 0; t--)
		{
			if (iki[xx[x][t]] < p[y])
			{
				ans += dx[x][t];
				x = xx[x][t];
			}
		}
		while (iki[x] < p[y])
		{
			ans += dx[x][0];
			x = xx[x][0];
		}
		cout << ans << "\n";
	}

}