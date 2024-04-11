/*input
1 2
1 100
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll>K[m];
	for (int i = 0; i < n; i++)
	{
		ll p, c;
		cin >> p >> c;
		p--;
		K[p].push_back(c);
	}
	for (int i = 0; i < m; i++)
		sort(K[i].begin(), K[i].end(), greater<ll>());
	ll ans = 1e17;
	ll kaina = 0;
	ll turim = K[0].size();
	for (int mx = n; mx >= 0; mx--)
	{
		for (int i = 1; i < m; i++)
		{
			while (K[i].size() > mx)
			{
				kaina += K[i].back();
				K[i].pop_back();
				turim++;
			}
		}
		vector<ll>neturim;
		for (int i = 1; i < m; i++)
			for (ll a : K[i])
				neturim.push_back(a);
		sort(neturim.begin(), neturim.end(), greater<ll>());
		ll darkain = 0;
		ll dartur = 0;
		while (neturim.size() >= 1 && turim + dartur <= mx)
		{
			dartur++;
			darkain += neturim.back();
			neturim.pop_back();
		}

		if (turim + dartur > mx)
			ans = min(ans, kaina + darkain);
	}
	cout << ans << "\n";
}