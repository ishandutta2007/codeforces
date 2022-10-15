/*input
5
5
4 0 3 2 1
1
0
4
0 1 2 3
6
1 2 4 0 5 3
8
1 3 7 2 5 0 6 4

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
ll F[100005];
ll C(int n, int k)
{
	ll a = F[n];
	ll b = F[n - k] * F[k];
	return (a * power(b, mod - 2)) % mod;
}
int main()
{
	F[0] = 1;
	for (int i = 1; i < 100005; i++)
		F[i] = (F[i - 1] * i) % mod;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll ret = 1;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int p[n + 1];
		for (int i = 0; i < n; i++)
			p[a[i]] = i;
		p[n] = -1;
		int l = n + 1;
		int r = -1;
		int k = 0;
		int sz1 = 0;
		for (int i = 0; i < n; i++)
		{
			l = min(l, p[i]);
			r = max(r, p[i]);
			if (p[i + 1] < l || p[i + 1] > r)
			{
				int sz = r - l + 1;
				int delt = sz - sz1;
				int cnt = i + 1 - k;
				ret *= C(delt - 1 + sz1 - k, cnt - 1);
				ret %= mod;
				ret *= F[cnt - 1];
				ret %= mod;
				sz1 = sz;
				k = i + 1;
			}
		}
		cout << ret << "\n";
	}
}