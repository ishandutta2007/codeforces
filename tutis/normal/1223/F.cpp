/*input
3
5
2 1 1 2 2
6
1 2 1 1 3 2
9
3 1 2 2 1 6 6 3 3
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
map<int, int>M[303030];
mt19937 rng(156);
int main()
{
	ios_base::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		ll a[n + 2];
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (ll i = 0; i <= n + 1; i++)
			M[i].clear();
		a[n] = a[n + 1] = -1;
		ll tus[n + 1];
		fill_n(tus, n + 1, n);
		ll kk = n;
		ll ans = 0;
		ll gyl[n + 2];
		fill_n(gyl, n + 2, 0);
		for (ll i = n - 1; i >= 0; i--)
		{
			if (M[i + 1].count(a[i]))
				tus[i] = M[i + 1][a[i]];
			else
				tus[i] = n;
			if (tus[i] != n)
				gyl[i] = 1 + gyl[tus[i] + 1];
			ans += gyl[i];
			ll j = tus[i];
			if (tus[i] != n)
			{
				swap(M[i], M[tus[i] + 1]);
				M[i][a[tus[i] + 1]] = tus[i] + 1;
			}
			M[i][a[i]] = i;
		}
		cout << ans << "\n";
	}
}