/*input
4
5 10
2 4 2 4 2
3 50
12 2 3
2 40
6 35
2 5
1 5

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
		int n, m;
		cin >> n >> m;
		int M[m + 1];
		for (int i = 1; i <= m; i++)
			M[i] = 0;
		M[1] = 1;
		vector<bool>C(m + 1, false);
		vector<int>C1(m + 1, 0);
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans = m + 1;
		bool ones = true;
		for (int i : a)
		{
			if (i != a[0])
				ones = false;
		}
		if (ones)
			ans = 0;
		for (int i : a)
		{
			if (C[i] == false)
				C1[M[i]]++;
			C[i] = true;
		}
		int mn = 0;
		for (int mx = 2; mx <= m; mx++)
		{
			if (C[mx])
				C1[M[mx]]--;
			M[mx] = mx;
			if (C[mx])
				C1[M[mx]]++;
			for (int k = 2; k * mx <= m; k++)
			{
				if (M[k] > M[k * mx])
				{
					if (C[k * mx])
						C1[M[k * mx]]--;
					M[k * mx] = M[k];
					if (C[k * mx])
						C1[M[k * mx]]++;
				}
			}
			while (C1[mn] == 0)
				mn++;
			if (mn != 0)
				ans = min(ans, mx - mn);
		}
		cout << ans << "\n";
	}
}