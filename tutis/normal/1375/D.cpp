/*input
5
3
2 2 3
3
2 1 0
7
0 7 3 1 3 7 7
9
2 0 1 1 2 4 4 2 0
9
8 4 7 6 1 2 3 0 5

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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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
		int a[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		a[0] = -1;
		vector<int>ans;
		while (true)
		{
			vector<int>x(n + 1, 0);
			for (int i = 1; i <= n; i++)
				x[a[i]]++;
			int c = 0;
			while (x[c] != 0)
				c++;
			if (c == n)
			{
				int v = -1;
				for (int i = 1; i <= n; i++)
					if (a[i] != i - 1)
						v = i - 1;
				if (v == -1)
					break;
				int id = 1;
				for (int i = 1; i <= n; i++)
					if (a[i] == v)
						id = i;
				ans.push_back(id);
				a[id] = c;
				continue;
			}
			else
			{
				ans.push_back(c + 1);
				a[c + 1] = c;
				continue;
			}
		}
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}



	return 0;
}