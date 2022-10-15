/*input
3
1 1 1
1 2
1 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[202020];
vector<ll>adj[202020];
ll dp[202020][2];
void dfs(ll i, ll p)
{
	vector<ll>cc;
	for (ll j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
		cc.push_back(j);
	}
	if (cc.empty())
	{
		dp[i][1] = c[i];
		dp[i][0] = 0;
		return;
	}
	dp[i][0] = dp[i][1] = 1e18;
	ll visi = 0;
	for (ll j : cc)
	{
		visi += dp[j][1];
	}
	dp[i][1] = min(dp[i][1], visi);
	for (ll j : cc)
	{
		dp[i][1] = min(dp[i][1], visi - dp[j][1] + dp[j][0] + c[i]);
		dp[i][0] = min(dp[i][0], visi - dp[j][1] + dp[j][0]);
	}
	dp[i][0] = min(dp[i][0], dp[i][1]);
}
vector<ll>ans;
bool buvau[202020][2];
void opt(ll i, ll p, ll k)
{
	if (buvau[i][k])
		return;
	buvau[i][k] = true;
	if (k == 0 && dp[i][1] == dp[i][0])
		opt(i, p, 1);
	vector<ll>cc;
	for (ll j : adj[i])
	{
		if (j == p)
			continue;
		cc.push_back(j);
	}
	if (cc.empty())
	{
		if (k == 1)
		{
			ans.push_back(i);
		}
		return;
	}
	ll visi = 0;
	for (ll j : cc)
	{
		visi += dp[j][1];
	}
	if (k == 1)
	{
		if (dp[i][1] == visi)
		{
			for (ll j : cc)
			{
				opt(j, i, 1);
			}
		}
		int kiek = 0;
		for (ll j : cc)
		{
			if (dp[i][k] == visi - dp[j][1] + dp[j][0] + c[i])
			{
				kiek++;
				ans.push_back(i);
				opt(j, i, 0);
				if (kiek < 4)
					for (ll v : cc)
					{
						if (v != j)
							opt(v, i, 1);
					}
			}
		}
	}
	else
	{
		int kiek = 0;
		for (ll j : cc)
		{
			if (dp[i][k] == visi - dp[j][1] + dp[j][0])
			{
				kiek++;
				opt(j, i, 0);
				if (kiek < 4)
					for (ll v : cc)
					{
						if (v != j)
							opt(v, i, 1);
					}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> c[i];
	for (ll i = 1; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	opt(1, 1, 1);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << dp[1][1] << " " << ans.size() << "\n";
	for (ll i : ans)
		cout << i << " ";
}