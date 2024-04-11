/*input
3
4
2 16 4 18
6
1 2 3 4 5 6
5
11 19 1 1 3
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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
		ll a[n + 1];
		ll sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		ll avg = sum / n;
		if (avg * n != sum)
		{
			cout << "-1\n";
			continue;
		}
		vector<pair<pair<int, int>, int>>ans;
		for (int i = 2; i <= n; i++)
		{
			int x = i - (a[i] % i);
			if (x == i)
				x = 0;
			a[1] -= x;
			a[i] += x;
			ans.push_back({{1, i}, x});
			ans.push_back({{i, 1}, a[i] / i});
			a[1] += a[i];
			a[i] = 0;
		}
		for (int i = 2; i <= n; i++)
		{
			ans.push_back({{1, i}, avg});
		}
		cout << ans.size() << "\n";
		for (auto g : ans)
			cout << g.first.first << " " << g.first.second << " " << g.second << "\n";
	}
	return 0;
}