/*input
3
4
1 3 4 2
1 2 2 3
5
2 3 4 5 1
1 2 3 4 5
8
7 4 5 6 1 8 3 2
5 3 6 4 7 5 8 4
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>divs[200200];
int main()
{
	for (int i = 1; i < 200200; i++)
	{
		for (int j = i; j < 200200; j += i)
		{
			divs[j].push_back(i);
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int ans = n;
		int p[n + 1], C[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		for (int i = 1; i <= n; i++)
			cin >> C[i];
		for (int l = 1; l <= n; l++)
		{
			if (p[l] == -1)
				continue;
			vector<int>P = {l};
			while (p[P.back()] != -1)
			{
				int x = P.back();
				P.push_back(p[x]);
				p[x] = -1;
			}
			P.pop_back();
			for (int k : divs[P.size()])
			{
				if (k >= ans)
					continue;
				int val[k];
				fill_n(val, k, -1);
				bool ok[k];
				fill_n(ok, k, true);
				for (int t = 0; t < (int)P.size(); t++)
				{
					int c = C[P[t]];
					int i = t % k;
					if (val[i] == -1)
					{
						val[i] = c;
					}
					else if (val[i] != c)
						ok[i] = false;
				}
				for (int i = 0; i < k; i++)
					if (ok[i])
						ans = k;
			}
		}
		cout << ans << "\n";
	}
}