/***
3
1 2 3
3 2 1
1 1
1 1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<ll, ll>>adj[100009];
ll a[100009];
ll b[100009];
#define negINF (LLONG_MIN/2)
ll perteklius(ll i)
{
	ll dabar = b[i] - a[i];
	for (pair<ll, ll> j : adj[i])
	{
		ll k = j.first;
		ll c = perteklius(j.second);
		if (c >= 0)
			dabar += perteklius(j.second);
		else
		{
			if (perteklius(j.second) <= (negINF - dabar) / k)
				dabar = negINF;
			else
				dabar += perteklius(j.second) * k;
		}
	}
	return dabar;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 1; i < n; i++)
	{
		ll x, k;
		cin >> x >> k;
		x--;
		adj[x].push_back(make_pair(k, i));
	}
	if (perteklius(0) >= 0)
		cout << "YES";
	else
		cout << "NO";
}