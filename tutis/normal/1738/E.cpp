/*input
6
1
1000000000
2
1 1
4
0 0 1 0
5
1 2 3 2 1
5
1 3 5 7 9
3
5 0 5

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(0);
const ll mod = 998244353;
ll power(ll x, ll p)
{
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		p /= 2;
	}
	return r;
}
ll F[100001];
ll C(ll n, ll k)
{
	return (F[n] * power((F[k] * F[n - k]) % mod, mod - 2)) % mod;
}
int main()
{
	F[0] = 1;
	for (int i = 1; i < 100001; i++)
		F[i] = (F[i - 1] * i) % mod;
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		function<ll(int, int)>brut = [&](int l, int r)->ll
		{
			if (l >= r)
				return 1;
			ll ret = 1;
			ll s1 = 0;
			for (int x = l; x <= r; x++)
			{
				s1 += a[x];
				ll s2 = 0;
				for (int y = r; y > x; y--)
				{
					s2 += a[y];
					if (s1 == s2)
						ret += brut(x + 1, y - 1);
				}
			}
			return ret;
		};
		set<pair<int, int>>M1;
		function<pair<ll, pair<ll, ll>>(int, int)>dp = [&](int l, int r)->pair<ll, pair<ll, ll>>
		{
			if (l >= r)
			{
				if (l == r && a[l] == 0)
					return {1, {1, 1}};
				return {1, {0, 0}};
			}
			int cl = 0;
			int cr = 0;
			for (int i = l; i <= r; i++)
				if (a[i] == 0)
					cl++;
				else
					break;
			for (int i = r; i >= l; i--)
				if (a[i] == 0)
					cr++;
				else
					break;
			if (cl == 0 && cr == 0)
			{
				int i1 = l;
				int i2 = r;
				ll s0 = a[l];
				ll s1 = a[r];
				while (i1 < i2)
				{
					if (s0 == s1)
					{
						if (i1 == i2 - 1)
							return {2, {0, 0}};
						pair<ll, pair<ll, ll>>a = dp(i1 + 1, i2 - 1);
						return {(2 * a.first + a.second.first + a.second.second) % mod, {0, 0}};
					}
					else if (s0 < s1)
					{
						i1++;
						s0 += a[i1];
					}
					else
					{
						i2--;
						s1 += a[i2];
					}
				}
				return {1, {0, 0}};
			}
			else
			{
				int n = r - l + 1;
				if (cl == n)
					return {power(2, n - 1), {power(2, n - 1), power(2, n - 1)}};
				ll x = dp(l + cl, r - cr).first;
				ll ret = 0;
				for (int k = 0; k <= min(cl, cr); k++)
				{
					ll s = (C(cl, k) * C(cr, k)) % mod;
					ret += s * x;
					ret %= mod;
				}
				ll s0 = 0;
				ll s1 = 0;
				for (int k = 0; k <= min(cl - 1, cr); k++)
				{
					ll s = (C(cl, k + 1) * C(cr, k)) % mod;
					s0 += s * x;
					s0 %= mod;
				}
				for (int k = 0; k <= min(cl, cr - 1); k++)
				{
					ll s = (C(cl, k) * C(cr, k + 1)) % mod;
					s1 += s * x;
					s1 %= mod;
				}
				return {ret, {s0, s1}};
			}
		};
		//assert(brut(0, n - 1) == dp(0, n - 1).first);
		//cout << brut(0, n - 1) << "\n";
		cout << dp(0, n - 1).first << "\n";
	}
}