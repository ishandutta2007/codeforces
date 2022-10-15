/*input
6 7 2
1 2 3 4 5 6

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, p, k;
	cin >> n >> p >> k;
	map<ll, ll>M;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		a = ((a * a) % p) * ((a * a) % p) - k * a;
		a %= p;
		if (a < 0)
			a += p;
		if (M.count(a))
		{
			ans += M[a];
			M[a]++;
		}
		else
		{
			M[a] = 1;
		}
	}
	cout << ans << "\n";
}