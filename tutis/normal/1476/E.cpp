/*input
2 2 2
a_
_b
ab 1
ab 2

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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	map<string, int>M;
	for (int i = 0; i < n; i++)
		M[s[i]] = i;
	vector<int>adj[n];
	vector<int>cnt(n, 0);
	for (int i = 0; i < m; i++)
	{
		string t;
		int pos;
		cin >> t >> pos;
		pos--;
		bool ok = false;
		for (int msk = 0; msk < (1 << k); msk++)
		{
			string p = t;
			for (int c = 0; c < k; c++)
				if ((msk & (1 << c)) == 0)
					p[c] = '_';
			if (M.count(p))
			{
				int id = M[p];
				if (id != pos)
				{
					adj[pos].push_back(id);
					cnt[id]++;
				}
				else
					ok = true;
			}
		}
		if (!ok)
		{
			cout << "NO\n";
			return 0;
		}
	}
	vector<int>L;
	vector<int>ans;
	for (int i = 0; i < n; i++)
		if (cnt[i] == 0)
			L.push_back(i);
	while (!L.empty())
	{
		int a = L.back();
		L.pop_back();
		ans.push_back(a);
		for (int b : adj[a])
		{
			cnt[b]--;
			if (cnt[b] == 0)
				L.push_back(b);
		}
	}
	if (ans.size() == n)
	{
		cout << "YES\n";
		for (int i : ans)
			cout << i + 1 << " ";
	}
	else
	{
		cout << "NO\n";
	}
}