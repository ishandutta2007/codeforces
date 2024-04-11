/*input
3 2
1 2 10
2 3 5
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll P[n + 1];
	fill_n(P, n + 1, 0);
	while (m--)
	{
		ll u, v, d;
		cin >> u >> v >> d;
		P[u] -= d;
		P[v] += d;
	}
	vector<ll>Mi;
	vector<ll>Pl;
	for (ll i = 1; i <= n; i++)
	{
		if (P[i] < 0)
			Mi.push_back(i);
		if (P[i] > 0)
			Pl.push_back(i);
	}
	vector<pair<pair<ll, ll>, ll>>ans;
	while (!Mi.empty() && !Pl.empty())
	{
		ll i = Mi.back();
		ll j = Pl.back();
		ll z = min(-P[i], P[j]);
		ans.push_back({{i, j}, z});
		P[i] += z;
		P[j] -= z;
		if (P[i] == 0)
			Mi.pop_back();
		if (P[j] == 0)
			Pl.pop_back();
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
}