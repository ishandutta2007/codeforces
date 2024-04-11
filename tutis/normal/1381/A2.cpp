/*input
5
2
01
10
5
01011
11100
2
01
01
10
0110011011
1000110100
1
0
1
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
		string a, b;
		cin >> n >> a >> b;
		vector<int>ans;
		int v = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] - '0' != v)
			{
				if (i != 0)
					ans.push_back(i);
				v = 1 - v;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (b[i] - '0' != v)
			{
				ans.push_back(i + 1);
				v = 1 - v;
			}
		}
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}