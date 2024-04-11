/*input
10 1 4
6 3 10
1714636915 243110879 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
ll mbk = 1;
ll G[2000000];
ll ans(ll a, ll c)
{
	fill_n(G, 2000000, 2e18);
	queue<ll>Q;
	ll x = a / mbk;
	a -= x * mbk;
	c -= x * mbk;
	G[c - a] = 0;
	for (ll b = c; b > a; b--)
	{
		if (b <= a)
			continue;
		{
			ll b_ = b - 1;
			if (b_ >= a && G[b_ - a] > G[b - a] + 1)
			{
				G[b_ - a] = G[b - a] + 1;
			}
		}
		for (ll x = 2; x <= k; x++)
		{
			ll b_ = b - b % x;
			if (b_ >= a && G[b_ - a] > G[b - a] + 1)
			{
				G[b_ - a] = G[b - a] + 1;
			}
		}
	}
	return G[0];
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll a, b;
	while (cin >> b >> a >> k)
	{
		mbk = 360360;
		ll c = (b / mbk - a / mbk);
		b -= c * mbk;
		if (b < a)
		{
			b += mbk;
			c--;
		}
		cout << c * ans(0, mbk) + ans(a, b) << "\n";
	}
}