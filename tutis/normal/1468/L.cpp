/*input
5 3
2 4 6 3 9
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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
using u64 = uint64_t;
using u128 = __uint128_t;
//using u128 = u64;

u64 binpower(u64 base, u64 e, u64 mod) {
	u64 result = 1;
	base %= mod;
	while (e) {
		if (e & 1)
			result = (u128)result * base % mod;
		base = (u128)base * base % mod;
		e >>= 1;
	}
	return result;
}

bool check_composite(u64 n, u64 a, u64 d, ll s) {
	u64 x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (ll r = 1; r < s; r++) {
		x = (u128)x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
	if (n < 2)
		return false;

	ll r = 0;
	u64 d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		r++;
	}

	for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (check_composite(n, a, d, r))
			return false;
	}
	return true;
}
bool prime(ll x)
{
	return MillerRabin(x);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	map<ll, ll>P;
	map<ll, vector<ll>>Pv;
	vector<ll>X;
	while (n--)
	{
		ll x;
		cin >> x;
		ll p = -1;
		for (ll k = 59; k >= 1; k--)
		{
			ll c = powl(x, ld(1) / k);
			for (ll a = max(2ll, c - 50); a <= c + 50; a++)
			{
				if (a >= 2 && a <= x && prime(a))
				{
					ll t = 0;
					ll x_ = x;
					while (x_ % a == 0)
					{
						x_ /= a;
						t++;
					}
					if (t == k && x_ == 1)
						p = a;
				}
			}
		}
		if (p == -1)
			X.push_back(x);
		else
		{
			Pv[p].push_back(x);
			P[p]++;
		}
	}
	vector<ll>XX;
	for (ll x : X)
	{
		ll xx = x;
		set<ll>A;
		bool gerai = true;
		for (auto c : P)
		{
			ll p = c.first;
			while (xx % p == 0)
			{
				xx /= p;
				A.insert(p);
				if (P[p] < 2)
					gerai = false;
			}
		}
		if (xx == 1 && gerai)
		{
			XX.push_back(x);
			if (k % 2 == 1)
			{
				ll k_ = k - 1;
				vector<ll>ans = {x};
				for (ll c : A)
				{
					k_ -= 2;
					ans.push_back(Pv[c][0]);
					ans.push_back(Pv[c][1]);
				}
				for (auto pp : P)
				{
					if (k_ > 0 && A.count(pp.first) == 0 && pp.second >= 2)
					{
						k_ -= 2;
						ans.push_back(Pv[pp.first][0]);
						ans.push_back(Pv[pp.first][1]);
					}
				}
				if (k_ == 0)
				{
					for (ll i : ans)
						cout << i << " ";
					cout << "\n";
					return 0;
				}
			}
		}
	}
	vector<ll>ans;
	for (auto pp : P)
		if (pp.second == 1)
			Pv.erase(pp.first);
	set<ll>ok;
	for (auto &c : Pv)
	{
		if (k >= 2 && c.second.size() >= 3)
		{
			ok.insert(c.first);
			assert(c.second.size() >= 2);
			ans.push_back(c.second.back());
			c.second.pop_back();
			ans.push_back(c.second.back());
			c.second.pop_back();
			k -= 2;
		}
	}
	for (auto &c : Pv)
	{
		if (k >= 2 && c.second.size() >= 2 && ok.count(c.first) == 0)
		{
			ok.insert(c.first);
			assert(c.second.size() >= 2);
			ans.push_back(c.second.back());
			c.second.pop_back();
			ans.push_back(c.second.back());
			c.second.pop_back();
			k -= 2;
		}
	}
	bool blogai = false;
	for (auto &c : Pv)
	{
		while (k >= 1 && !c.second.empty() && ok.count(c.first))
		{
			ans.push_back(c.second.back());
			c.second.pop_back();
			k--;
		}
		if (c.second.size() > 0)
			blogai = true;
	}
	if (!blogai)
		for (ll x : XX)
		{
			if (k >= 1)
			{
				k--;
				ans.push_back(x);
			}
		}
	if (k == 0)
	{
		for (ll i : ans)
			cout << i << " ";
		cout << "\n";
	}
	else
		cout << "0\n";
}