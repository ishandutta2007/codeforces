/*input
4 2
0 1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll a = n / m;
	ll c[m];
	fill_n(c, m, 0);
	ll A[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> A[i];
		c[A[i] % m]++;
	}
	set<ll>B;
	for (ll i = 0; i < m; i++)
		if (c[i] < a)
			B.insert(i);
	ll didink[m];
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		if (c[A[i] % m] <= a)
			continue;
		ll g = A[i] % m;
		ll d;
		auto it = B.lower_bound(g);
		if (it != B.end())
		{
			d = *it;
			c[A[i] % m]--;
			c[d]++;
			if (c[d] >= a)
				B.erase(d);
			ans += d - (A[i] % m);
			A[i] += d - (A[i] % m);
		}
		else
		{
			d = *B.begin();
			c[A[i] % m]--;
			c[d]++;
			if (c[d] >= a)
				B.erase(d);
			ans += m - (A[i] % m) + d;
			A[i] += m - (A[i] % m) + d;
		}

	}
	cout << ans << "\n";
	for (ll i = 0; i < n; i++)
		cout << A[i] << " ";
}