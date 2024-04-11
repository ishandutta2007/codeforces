/*input
6
5
zx
ab
cc
zx
ba
2
ab
bad
4
co
def
orc
es
3
a
b
c
3
ab
cd
cba
2
ab
ab

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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		bool ok = false;
		for (string t : s)
		{
			bool ger = true;
			for (int i = 0; i < t.size(); i++)
			{
				if (t[i] != t[(int)t.size() - 1 - i])
					ger = false;
			}
			if (ger)
				ok = true;
		}
		set<string>S2, S3, S23;
		if (ok == false)
			for (int i = n - 1; i >= 0; i--)
			{
				assert(s[i].size() >= 2);
				assert(s[i].size() <= 3);
				string t = s[i];
				if (t.size() == 2)
				{
					S2.insert(t);
				}
				else
				{
					S3.insert(t);
					t.erase(t.begin());
					S23.insert(t);
				}
				t = s[i];
				if (t.size() == 2)
				{
					reverse(t.begin(), t.end());
					if (S2.count(t))
						ok = true;
					if (S23.count(t))
						ok = true;
				}
				else
				{
					reverse(t.begin(), t.end());
					if (S3.count(t))
						ok = true;
					t.erase(t.begin());
					if (S2.count(t))
						ok = true;
				}
			}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}