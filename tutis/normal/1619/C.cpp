/*input
6
17236 1106911
1 5
108 112
12345 1023412
1 11
1 20

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
		string a, s;
		cin >> a >> s;
		reverse(a.begin(), a.end());
		reverse(s.begin(), s.end());
		int n = (int)a.size();
		map<string, string>M[n + 1];
		M[0][""] = "";
		for (int i = 1; i <= n; i++)
		{
			int k = a[i - 1] - '0';
			for (auto ss : M[i - 1])
			{
				string b = ss.second;
				for (int c = 0; c <= 9; c++)
				{
					b.push_back((char)('0' + c));
					string xx = to_string(k + c);
					reverse(xx.begin(), xx.end());
					string s_ = ss.first + xx;
					bool ok = true;
					if (s_.size() > s.size())
						ok = false;
					if (ok)
						for (int i = (int)s_.size() - 1; i >= 0 && i >= (int)s_.size() - 3; i--)
						{
							ok &= s_[i] == s[i];
						}
					if (ok)
						M[i][s_] = b;
					b.pop_back();
				}
			}
		}
		if (M[n].size() > 0)
		{
			pair<string, string> x = *M[n].begin();
			while (x.first.size() < s.size())
			{
				x.second.push_back(s[x.first.size()]);
				x.first.push_back(s[x.first.size()]);
			}
			reverse(x.second.begin(), x.second.end());
			reverse(x.first.begin(), x.first.end());
			while (x.second[0] == '0')
				x.second.erase(x.second.begin());
			cout << x.second << endl;
		}
		else
			cout << "-1\n";
	}
}