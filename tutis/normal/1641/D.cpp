/*input
4 2
1 2 5
4 3 1
2 3 2
4 5 3

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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll>a[n];
	ll w[n];
	cc_hash_table<ll, ll>R;
	ll RR[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int val;
			cin >> val;
			a[i].push_back(val);
			R.insert({val, rng()});
		}
		for (int j = 0; j < m; j++)
			RR[i][j] = R[a[i][j]];
		cin >> w[i];
	}
	ll lo = 0;
	ll hi = 2e9 + 200;
	int p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](int a, int b) {return w[a] < w[b];});
	cc_hash_table<ll, vector<int>>X;
	cc_hash_table<ll, vector<int>>::point_iterator id[n][1 << m];
	for (int i : p)
	{
		for (int msk = 0; msk < (1 << m); msk++)
		{
			ll h = 0;
			for (int j = 0; j < m; j++)
				if ((msk & (1 << j)) != 0)
					h ^= RR[i][j];
			auto it = X.insert(make_pair(h, vector<int>())).first;
			it->second.push_back(w[i]);
			id[i][msk] = it;
		}
	}
	int best = 2e9 + 100;
	bool ok = false;
	for (int i : p)
	{
		vector<vector<int>*>S[2];
		int cnt = 0;
		for (int msk = 0; msk < (1 << m); msk++)
		{
			auto it = id[i][msk];
			if (__builtin_popcount(msk) % 2 == 0)
				cnt += it->second.size();
			else
				cnt -= it->second.size();
			S[__builtin_popcount(msk) % 2].push_back(&it->second);
		}
		bool ok = true;
		while (ok) {
			ok = false;
			int hi = best - 1 - w[i];
			for (int t : {0, 1})
				for (vector<int>* a : S[t])
				{
					vector<int>&v = *a;
					while (!v.empty() && v.back() > hi)
					{
						if (t == 0)
							cnt--;
						else
							cnt++;
						v.pop_back();
					}
				}
			if (cnt > 0)
			{
				best = (*S[0][0]).back() + w[i];
				ok = true;
			}
		}
	}
	if (best > 2000000000)
		best = -1;
	cout << best << "\n";
}