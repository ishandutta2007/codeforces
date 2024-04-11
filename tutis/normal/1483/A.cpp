/*input
2
4 6
1 1
2 1 2
3 1 2 3
4 1 2 3 4
2 2 3
1 3
2 2
1 1
1 1

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
using ld = double;
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int mx = (m + 1) / 2;
		vector<int>f[m];
		for (int i = 0; i < m; i++)
		{
			int k;
			cin >> k;
			f[i] = vector<int>(k);
			for (int &v : f[i])
				cin >> v;
		}
		int p[m];
		iota(p, p + m, 0);
		shuffle(p, p + m, rng);
		stable_sort(p, p + m, [&](int x, int y) {return f[x].size() < f[y].size();});
		vector<int>cnt(n + 1, 0);
		vector<int>ans(m);
		bool ok = true;
		for (int i : p)
		{
			int mn = f[i][0];
			for (int v : f[i])
				if (cnt[v] <= cnt[mn])
					mn = v;
			cnt[mn]++;
			if (cnt[mn] > mx)
				ok = false;
			ans[i] = mn;
		}
		if (ok)
		{
			cout << "YES\n";
			for (int i : ans)
				cout << i << " ";
			cout << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}