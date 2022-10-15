/*input
4
7
4 2 4 1 4 3 4
5
2 1 5 4 3
1
1
4
1 1 1 3
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
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		map<int, int>K;
		for (int i = 0; i < n; i++)
			K[a[i]]++;
		vector<int>V;
		for (auto i : K)
			V.push_back(i.second);
		sort(V.begin(), V.end(), greater<int>());
		int ans = 0;
		for (int x = 1; 2 * x <= n && x <= V[0]; x++)
		{
			if (V[0] > x)
			{
				if ((int)V.size() >= x)
					ans = x;
			}
			else
			{
				if ((int)V.size() - 1 >= x)
					ans = x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}