/*input
4
2
1
1 5
2 9
3
1 1
4 5
2 4
6 10
4
1 2 1
6 9
5 6
4 5
2 4
5
1 2 3 4
5 5
4 4
3 3
2 2
1 1


*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int p[n + 1];
		for (int i = 2; i <= n; i++)
			cin >> p[i];
		p[1] = 0;
		ll l[n + 1], r[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> l[i] >> r[i];
		ll sum[n + 1];
		for (int i = 1; i <= n; i++)
			sum[i] = 0;
		int ans = 0;
		for (int i = n; i >= 1; i--)
		{
			if (l[i] - sum[i] > 0)
			{
				sum[i] = r[i];
				ans++;
			}
			sum[i] = min(sum[i], r[i]);
			sum[p[i]] += sum[i];
		}
		cout << ans << "\n";
	}
}