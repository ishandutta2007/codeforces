/*input
10 4
5 4 1 5 4 3 7 1 2 5
4 6
2 1
10 8
3 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll r[n + 1];
	ll KIEK[n + 1];
	map<ll, vector<ll>>X;
	set<ll>REIKS;
	for (ll i = 1; i <= n; i++)
	{
		cin >> r[i];
		KIEK[i] = 0;
		X[r[i]].push_back(i);
		REIKS.insert(r[i]);
	}
	ll suma = 0;
	for (ll w : REIKS)
	{
		for (ll i : X[w])
		{
			KIEK[i] = suma;
		}
		suma += X[w].size();
	}

	while (k--)
	{
		ll x, y;
		cin >> x >> y;
		KIEK[x] -= (r[x] > r[y]);
		KIEK[y] -= (r[y] > r[x]);
	}
	for (ll i = 1; i <= n; i++)
		cout << KIEK[i] << " ";



}