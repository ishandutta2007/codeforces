/***
4 6
1 2 2
1 3 3
1 4 8
2 3 4
2 4 5
3 4 3
0
1 3
2 3 4
0
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>T[100009];
set<pair<ll, ll>>adj[100009];
#define INF (5000000000ll)
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	while (m--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].insert(make_pair(c, b));
		adj[b].insert(make_pair(c, a));
	}
	for (ll i = 1; i <= n; i++)
	{
		ll k;
		cin >> k;
		while (k--)
		{
			ll a;
			cin >> a;
			T[i].insert(a);
		}
	}
	ll D[n + 1];
	fill_n(D, n + 1, INF);
	D[1] = 0;
	priority_queue<pair<ll, ll>, std::vector<pair<ll, ll>>, std::greater<pair<ll, ll>>>X;
	X.push(make_pair(0, 1));
	while (!X.empty())
	{
		ll w = X.top().first;
		ll i = X.top().second;
		while (T[i].count(w))
			w++;
		X.pop();
		for (pair<ll, ll>a : adj[i])
		{
			ll t = w + a.first;
			ll j = a.second;
			if (D[j] > t)
			{
				D[j] = t;
				X.push(make_pair(t, j));
			}
		}
	}
	if (D[n] == INF)
		D[n] = -1;
	cout << D[n];
}