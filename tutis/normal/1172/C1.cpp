/*input
3 3
0 1 1
4 3 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 998244353;
ll power(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % modulo;
	ll x = power(a, b / 2);
	return (x * x) % modulo;
}
ll divv(ll a, ll b)
{
	return (a * power(b, modulo - 2)) % modulo;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll w[n + 1];
	w[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	ll Ws[2] = {0ll, 0ll};
	for (int i = 1; i <= n; i++)
		Ws[a[i]] += w[i];
	for (int i = 1; i <= n; i++)
	{
		map<pair<ll, pair<ll, ll>>, ll>P;
		P[ {w[i], {Ws[0], Ws[1]}}] = 1;
		for (int t = 0; t < m; t++)
		{
			map<pair<ll, pair<ll, ll>>, ll>P_;
			for (auto c : P)
			{
				ll wi = c.first.first;
				ll w0 = c.first.second.first;
				ll w1 = c.first.second.second;
				ll p = c.second;
				p %= modulo;
				if (p == 0)
					continue;
				if (a[i] == 0)
				{
					ll p1 = (p * divv(wi, w0 + w1)) % modulo;
					ll p2 = (p * divv(w0 - wi, w0 + w1)) % modulo;
					ll p3 = (p * divv(w1, w0 + w1)) % modulo;
					P_[ {wi - 1, {w0 - 1, w1}}] += p1;
					P_[ {wi, {w0 - 1, w1}}] += p2;
					P_[ {wi, {w0, w1 + 1}}] += p3;
				}
				else
				{
					ll p1 = (p * divv(wi, w0 + w1)) % modulo;
					ll p2 = (p * divv(w1 - wi, w0 + w1)) % modulo;
					ll p3 = (p * divv(w0, w0 + w1)) % modulo;
					P_[ {wi + 1, {w0, w1 + 1}}] += p1;
					P_[ {wi, {w0, w1 + 1}}] += p2;
					P_[ {wi, {w0 - 1, w1}}] += p3;
				}
			}
			P = P_;
		}
		ll ans = 0;
		for (auto i : P)
		{
			ans += ((i.first.first % modulo) * (i.second % modulo)) % modulo;
			ans %= modulo;
		}
		cout << ans << "\n";
	}
	return 0;
}