/*input
5
1 2 3 4 5

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(0);
template<typename T>
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
const ll inf = 1e18 + 50;
char in[1 << 25]; // sizeof in varied in problem
char const*o;

void init_in()
{
	o = in;
	in[ fread(in, 1, sizeof(in) - 4, stdin)] = 0; //set 0 at the end of buffer.
}

ll readInt() {
	unsigned long long u = 0, s = 0;

	//while (*o && *o <= 32)++o; //skip whitespaces...

	//if (*o == '-')s = ~s, ++o; else if (*o == '+')++o; // skip sign

	while (*o >= '0' && *o <= '9')u = (u << 3) + (u << 1) + (*o++ - '0'); // u * 10 = u * 8 + u * 2 :)

	return static_cast<ll>( (u ^ s) + !!s) ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	init_in();
	int n;
	n = (int)readInt();
	//cin >> n;
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
	{
		++o;
		a[i] = readInt();
		//cin >> a[i];
	}
	vector<int>MX = {0}, MN = {0};
	vector<pair<int, int>>A[2][64];
	vector<int>S[2][64];
	auto cnt = [&](ll x)->int
	{
		return __builtin_popcountll(x);
	};
	int ans = 0;
	ll sum = 0;
	auto get1 = [&](int t, int cn, int mx)
	{
		if (A[t][cn].empty())
			return 0;
		if (A[t][cn].back().second <= mx)
			return S[t][cn].back();
		int lo = 0;
		int hi = (int)A[t][cn].size() - 1;
		while (lo < hi)
		{
			int m = (lo + hi) / 2;
			if (A[t][cn][m].second > mx)
				hi = m;
			else
				lo = m + 1;
		}
		int i = lo;
		int ret = 0;
		pair<int, int>v = A[t][cn][i];
		if (v.first <= mx)
			ret += mx - v.first + 1;
		i--;
		if (i >= 0)
			ret += S[t][cn][i];
		return ret;
	};
	auto get = [&](int t, int cn, pair<int, int>lr)
	{
		return get1(t, cn, lr.second) - get1(t, cn, lr.first - 1);
	};
	auto addS = [&](int t, int cn, pair<int, int>lr)
	{
		int v = lr.second - lr.first + 1;
		if (S[t][cn].empty())
			S[t][cn].push_back(v);
		else
			S[t][cn].push_back(v + S[t][cn].back());
	};
	for (int r = 1; r <= n; r++)
	{
		a[0] = inf;
		while (a[MX.back()] <= a[r])
		{
			ans -= get(0, cnt(a[MX.back()]), A[1][cnt(a[MX.back()])].back());
			A[1][cnt(a[MX.back()])].pop_back();
			S[1][cnt(a[MX.back()])].pop_back();
			MX.pop_back();
		}
		a[0] = -inf;
		while (a[MN.back()] >= a[r])
		{
			ans -= get(1, cnt(a[MN.back()]), A[0][cnt(a[MN.back()])].back());
			A[0][cnt(a[MN.back()])].pop_back();
			S[0][cnt(a[MN.back()])].pop_back();
			MN.pop_back();
		}
		A[0][cnt(a[r])].push_back({MN.back() + 1, r});
		addS(0, cnt(a[r]), {MN.back() + 1, r});
		ans += get(0, cnt(a[r]), {MX.back() + 1, r});
		ans += get(1, cnt(a[r]), {MN.back() + 1, r});
		A[1][cnt(a[r])].push_back({MX.back() + 1, r});
		addS(1, cnt(a[r]), {MX.back() + 1, r});
		MX.push_back(r);
		MN.push_back(r);
		sum += ans;
	}
	cout << sum << "\n";
}