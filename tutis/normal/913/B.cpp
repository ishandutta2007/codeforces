/***
8
1
1
1
1
3
3
3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool spruce = true;
vector<ll>adj[200000];
bool dfs(ll i)
{
	ll kiek = 0;
	ll kiekS = 0;
	for (ll j : adj[i])
	{
		kiekS += dfs(j);
		kiek++;
	}
	if (kiek != 0)
	{
		if (kiekS < 3)
			spruce = false;
	}
	return kiek == 0;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 2; i <= n; i++)
	{
		ll p;
		cin >> p;
		adj[p].push_back(i);
	}
	dfs(1);
	cout << (spruce ? "Yes\n" : "No\n");
}