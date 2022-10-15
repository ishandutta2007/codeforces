/*input
5
7
1 2 3 2 1 3 3
1
1
6
1 1 1 2 2 2
8
1 1 2 2 3 3 1 1
12
1 5 2 3 3 3 4 4 4 4 3 3

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
		int a[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		bitset<5005> dp[n + 2];

		for (int i = 1; i <= n + 1; i++)
			dp[i][i - 1] = true;

		map<int, vector<int>>p;
		for (int i = 1; i <= n; i++)
			p[a[i]].push_back(i);

		for (int i = n; i >= 1; i--)
		{
			int cnt = 0;
			for (int k = i + 1; k <= n; k++)
			{
				if (a[i] != a[k] && dp[i + 1][k - 1])
				{
					dp[i] |= dp[k + 1];
					cnt++;
					if (cnt > 5)
						break;
				}
			}
		}


		int ret = 0;
		for (auto it : p)
		{
			vector<int>v = it.second;
			int D[v.size()];
			for (int i = 0; i < v.size(); i++)
				D[i] = -1e7;
			for (int i = 0; i < v.size(); i++)
			{
				if (dp[1][v[i] - 1])
					D[i] = 1;
				for (int j = 0; j < i; j++)
				{
					if (dp[v[j] + 1][v[i] - 1])
						D[i] = max(D[i], D[j] + 1);
				}
				if (dp[v[i] + 1][n])
					ret = max(ret, D[i]);
			}
		}
		cout << ret << "\n";
	}
}