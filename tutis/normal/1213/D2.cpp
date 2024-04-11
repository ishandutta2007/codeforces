/*input
5 3
1 2 3 4 5

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll ans = n * 60;
	map<ll, vector<ll>>M;
	while (n--)
	{
		ll a;
		cin >> a;
		ll e = 0;
		while (a != 0)
		{
			M[a].push_back(e);
			e++;
			a /= 2;
		}
		M[a].push_back(e);
	}
	for (auto x : M)
	{
		if (x.second.size() >= k)
		{
			sort(x.second.begin(), x.second.end());
			ll gal = 0;
			for (int i = 0; i < k; i++)
			{
				gal += x.second[i];
			}
			ans = min(ans, gal);
		}
	}
	cout << ans << "\n";
}