/*input
4 5
aba
bbac
1 a
3 baca
3 ab
2 bab
4 aba

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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
ll cnt[101010][26];
ll P2[101010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	string s, t;
	cin >> s >> t;
	int S = s.size();
	P2[0] = 1;
	for (int i = 1; i < 101010; i++)
	{
		P2[i] = P2[i - 1] * 2;
		P2[i] %= mod;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			cnt[i][j] = cnt[i - 1][j] * 2;
			if (cnt[i][j] >= mod)
				cnt[i][j] -= mod;
		}
		cnt[i][t[i - 1] - 'a']++;
	}
	function<int(string, int, int)>f = [&](string T, int k, int a)->int
	{
		if (a >= k)
			return 0;
		if (T.size() == 1)
		{
			ll ret = cnt[k][T[0] - 'a'] - cnt[a][T[0] - 'a'] * P2[k - a];
			ret %= mod;
			if (ret < 0)
				ret += mod;
			return ret;
		}
		int ret = 0;
		for (int d = 0; d < 2; d++)
		{
			string T_;
			bool ok = true;
			for (int i = 0; i < T.size(); i++)
			{
				if (i % 2 == d)
				{
					if (T[i] != t[a])
					{
						ok = false;
						break;
					}
				}
				else
				{
					T_.push_back(T[i]);
				}
			}
			if (ok)
			{
				ret += f(T_, k, a + 1);
				if (ret >= mod)
					ret -= mod;
			}
		}
		return ret;
	};
	while (q--)
	{
		int k;
		cin >> k;
		string w;
		cin >> w;
		ll ans = 0;
		for (int d = 0; d <= S; d++)
		{
			int del = d;
			string T;
			bool ok = true;
			for (int i = 0; i < w.size(); i++)
			{
				if (del == S + 1)
					del = 0;
				if (del == S)
				{
					T.push_back(w[i]);
				}
				else
				{
					if (w[i] != s[del])
					{
						ok = false;
						break;
					}
				}
				del++;
			}
			if (ok) {
				if (T.empty())
				{
					ans += P2[k];
					if (ans >= mod)
						ans -= 0;
				}
				else
					ans += f(T, k, 0);
				if (ans >= mod)
					ans -= mod;
			}
		}
		cout << ans << "\n";
	}

}