/*input
2
4
6 8 4 2
1
0
6
12 3 20 5 80 1
1
1

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
int PP[1000001];
ull W[1000001];
int main()
{
	for (int i = 2; i < 1000001; i++)
	{
		if (PP[i] == 0)
		{
			for (int j = i; j < 1000001; j += i)
				PP[j] = i;
			W[i] = rng();
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<ull, vector<int>>A;
		set<ull>check;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			ull H = 0;
			while (v != 1)
			{
				int w = PP[v];
				int c = 0;
				while (v % w == 0)
				{
					H ^= W[w];
					v /= w;
					c++;
				}
			}
			A[H].push_back(1);
			check.insert(H);
		}
		int ans[n + 1];
		ans[0] = 1;
		ull mx = 0;
		for (int t = 1; t <= n; t++)
		{
			bool ok = false;
			mx = t;
			set<ull>check_;
			map<ull, vector<int>>A_;
			ans[t] = ans[t - 1];
			for (ull i : check)
			{
				if (A[i].size() >= 2)
				{
					ok = true;
					int suma = 0;
					ull newH = 0;
					for (int ss : A[i])
					{
						newH ^= i;
						suma += ss;
					}
					ans[t] = max(ans[t], suma);
					A_[newH].push_back(suma);
					check_.insert(newH);
				}
				else
				{
					if (i == 0)
					{
						A_[i] = A[i];
						check_.insert(i);
					}
				}
			}
			if (!ok)
				break;
			A = A_;
			check = check_;
		}
		int q;
		cin >> q;
		while (q--)
		{
			ull w;
			cin >> w;
			w++;
			w = min(w, mx);
			cout << ans[w] << "\n";
		}
	}

}