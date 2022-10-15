/*input
4
3 6
1 5
5 5
3 4
2 3
1 3
5 2
2 5
1 6
10 6
6 12
4 5
1 6
12 5
5 5
9 7
8 3

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
struct rain
{
	int x, p, i;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		rain A[n];
		for (int i = 0; i < n; i++)
		{
			cin >> A[i].x >> A[i].p;
			A[i].i = i;
		}
		sort(A, A + n, [&](rain a, rain b) {return a.x < b.x;});
		string ans(n, '0');
		vector<ll> s(n + 1, 0);
		vector<ll> k(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			int x1 = A[i].x - A[i].p;
			int x2 = A[i].x + A[i].p;
			int lo = 0;
			int hi = n - 1;
			while (lo < hi)
			{
				int m = (lo + hi) / 2;
				if (A[m].x >= x1)
					hi = m;
				else
					lo = m + 1;
			}
			int i1 = lo;
			lo = 0;
			hi = n - 1;
			while (lo < hi)
			{
				int m = (lo + hi + 1) / 2;
				if (A[m].x <= x2)
					lo = m;
				else
					hi = m - 1;
			}
			int i2 = lo;
			s[i1] += A[i].p - A[i].x;
			k[i1]++;

			s[i] -= A[i].p - A[i].x;
			k[i]--;

			s[i] += A[i].p + A[i].x;
			k[i]--;

			s[i2 + 1] -= A[i].p + A[i].x;
			k[i2 + 1]++;
		}
		for (int i = 1; i <= n; i++)
		{
			s[i] += s[i - 1];
			k[i] += k[i - 1];
		}
		ll v1 = -1e18;
		ll v2 = -1e18;
		for (int i = 0; i < n; i++)
		{
			ll sum = s[i] + k[i] * A[i].x;
			if (sum > m)
			{
				ll del = sum - m;
				v1 = max(v1, A[i].x + del);
				v2 = max(v2, -A[i].x + del);
			}
		}
		for (int i = 0; i < n; i++)
		{
			ll x1 = A[i].x + A[i].p;
			ll x2 = -A[i].x + A[i].p;
			if (x1 >= v1 && x2 >= v2)
				ans[A[i].i] = '1';
		}
		cout << ans << "\n";
	}
}