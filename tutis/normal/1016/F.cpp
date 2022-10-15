/*input
3 4
1 2 5
2 3 10
2
4
8
16
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<pair<ll, ll>>adj[n + 1];
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		ll w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	pair<ll, ll>D[n + 1];
	fill_n(D, n + 1, make_pair(3e16, -1));
	D[1] = {0, 0};
	queue<ll>Q;
	Q.push(1);
	while (!Q.empty())
	{
		ll a = Q.front();
		Q.pop();
		for (pair<ll, ll>b : adj[a])
		{
			if (D[b.first].first > D[a].first + b.second)
			{
				D[b.first] = {D[a].first + b.second, a};
				Q.push(b.first);
			}
		}
	}
	function<pair<ll, ll>(ll, ll, ll)>dfs = [&](ll i, ll p1, ll p2)->pair<ll, ll>
	{
		pair<ll, ll>ret = {0, 1};
		for (pair<ll, ll>j : adj[i])
		{
			if (j.first == p1 || j.first == p2)
				continue;
			pair<ll, ll>a = dfs(j.first, i, i);
			ret.first = max(ret.first, a.first + j.second);
			ret.second += a.second;
		}
		return ret;
	};
	ll x = n;
	vector<ll>C;
	while (x != 0)
	{
		C.push_back(x);
		x = D[x].second;
	}
	reverse(C.begin(), C.end());
	ll m = C.size();
	vector<ll>A(m);
	for (ll i = 0; i < C.size(); i++)
		A[i] = D[C[i]].first;
	vector<ll>B(m);
	bool optimalu = false;
	for (ll i = 0; i < C.size(); i++)
	{
		ll a = C[i];
		ll b = C[i];
		if (i != 0)
			a = C[i - 1];
		if (i != C.size() - 1)
			b = C[i + 1];
		B[i] = dfs(C[i], a, b).first;
		if (dfs(C[i], a, b).second >= 3)
			optimalu = true;
	}
	ll a = 0;
	ll b = m - 1;
	for (ll i = 1; i < m; i++)
	{
		if (B[i] != 0 || B[i - 1] != 0)
		{
			if (
			    min(B[a] + B[b], (A[b] - A[a])) - (A[b] - A[a])
			    <=
			    min(B[i - 1] + B[i], (A[i] - A[i - 1])) - (A[i] - A[i - 1])
			)
			{
				a = i - 1;
				b = i;
			}
		}
	}
	pair<ll, ll>G[2][2];
	for (ll i = 0; i < m; i++)
	{
		if (i - 2 >= 0)
		{
			for (ll c : { -1, 1})
				for (ll d : { -1, 1})
					G[(c + 1) / 2][(d + 1) / 2] = min(G[(c + 1) / 2][(d + 1) / 2],
				{B[i - 2] * c + A[i - 2] * d, i - 2});
			for (ll c : {0, 1})
			{
				for (ll d : {0, 1})
				{
					ll j = G[c][d].second;
					if (
					    min(B[a] + B[b], (A[b] - A[a])) - (A[b] - A[a])
					    <=
					    min(B[j] + B[i], (A[i] - A[j])) - (A[i] - A[j])
					)
					{
						a = j;
						b = i;
					}
				}
			}
		}
	}
	while (q--)
	{
		ll x;
		cin >> x;
		if (optimalu)
		{
			cout << A.back() << "\n";
			continue;
		}
		ll ans = A.back() + min(x + B[a] + B[b], A[b] - A[a]) - A[b] + A[a];
		cout << ans << "\n";
	}
}/**/