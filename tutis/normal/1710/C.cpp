/*input
11011111101010010

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
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
const int root = power(3, (mod - 1) / (1 << 23));
const int root_1 = power(root, -1);
const int root_pw = 1 << 23;

void fft(vector<int> & a, bool invert) {
	int n = a.size();

	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1)
			j ^= bit;
		j ^= bit;

		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? root_1 : root;
		for (int i = len; i < root_pw; i <<= 1)
			wlen = (int)(1LL * wlen * wlen % mod);

		for (int i = 0; i < n; i += len) {
			int w = 1;
			for (int j = 0; j < len / 2; j++) {
				int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % mod);
				a[i + j] = u + v < mod ? u + v : u + v - mod;
				a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
				w = (int)(1LL * w * wlen % mod);
			}
		}
	}

	if (invert) {
		int n_1 = power(n, -1);
		for (int & x : a)
			x = (int)(1LL * x * n_1 % mod);
	}
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
	vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size())
		n <<= 1;
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++)
		fa[i] = 1LL * fa[i] * fb[i] % mod;
	fft(fa, true);
	return fa;
}
vector<int> square(vector<int> const& a) {
	vector<int> fa(a.begin(), a.end());
	int n = 1;
	while (n < a.size() + a.size())
		n <<= 1;
	fa.resize(n);

	fft(fa, false);
	for (int i = 0; i < n; i++)
		fa[i] = 1LL * fa[i] * fa[i] % mod;
	fft(fa, true);
	return fa;
}
vector<int> f(int n, int k)
{
	if (n == 1)
	{
		vector<int> a(2 * k + 1);
		for (int i = 0; i <= 2 * k; i++)
			a[i] = k + 1 - abs(k - i);
		return a;
	}
	vector<int>a = f(n - 1, k);
	vector<int> b = a;
	for (int i = (int)(a.size()) - 2; i >= 0; i--)
	{
		a[i] += a[i + 1];
		if (a[i] >= mod)
			a[i] -= mod;
	}
	vector<int>ret(k + 1, 0);
	for (int i = 0; i <= k; i++)
	{
		ret[i] = (ret[i] + a[i] + 1LL * (k - i) * b[i]) % mod;
	}
	return square(ret);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	ll n = 0;
	ll p = 1;
	for (char c : s)
	{
		if (c == '1')
		{
			n += p;
			if (n >= mod)
				n -= mod;
		}
		p *= 2;
		if (p >= mod)
			p -= mod;
	}
	s.push_back('0');
	reverse(s.begin(), s.end());
	ll ret = ((((n + 1) * (n + 1)) % mod) * (n + 1)) % mod;
	ll cnt = 0;

	ll dp[s.size()][2][2][2][2];
	for (int i = 0; i < s.size(); i++)
	{
		for (int a : {0, 1})
		{
			for (int b : {0, 1})
			{
				for (int c : {0, 1})
				{
					for (int d : {0, 1})
					{
						dp[i][a][b][c][d] = 0;
					}
				}
			}
		}
	}
	dp[0][0][0][0][0] = 1;
	for (int i = 1; i < s.size(); i++)
	{
		int si = s[i] - '0';
		for (int a : {0, 1})
		{
			for (int b : {0, 1})
			{
				for (int c : {0, 1})
				{
					for (int x : {0, 1})
					{
						for (int y : {0, 1})
						{
							for (int z : {0, 1})
							{
								for (int t : {0, 1})
								{
									int x_ = x;
									int y_ = y;
									int z_ = z;
									int t_ = t;
									if (a < si)
										x_ = 1;
									if (b < si)
										y_ = 1;
									if (c < si)
										z_ = 1;
									if ((a ^ b) + (b ^ c) < (c ^ a))
										t_ = 1;
									if (x == 0 && a > si)
										continue;
									if (y == 0 && b > si)
										continue;
									if (z == 0 && c > si)
										continue;
									if (t == 0 && ((a ^ b) + (b ^ c) > (c ^ a)))
										continue;
									dp[i][x_][y_][z_][t_] += dp[i - 1][x][y][z][t];
									if (dp[i][x_][y_][z_][t_] >= mod)
										dp[i][x_][y_][z_][t_] -= mod;
								}
							}
						}
					}
				}
			}
		}
	}

	for (int x : {0, 1})
	{
		for (int y : {0, 1})
		{
			for (int z : {0, 1})
			{
				for (int t : {0, 1})
				{
					cnt += dp[(int)s.size() - 1][x][y][z][t];
				}
			}
		}
	}
	cnt %= mod;
	ret -= cnt * 3;
	ret %= mod;
	ret += 3 * ((n * (n + 1)) % mod);
	ret %= mod;
	ret += 2 * (n + 1);
	ret %= mod;
	if (ret < 0)
		ret += mod;
	cout << ret << "\n";
}