/*input
5
1 1 1 2 2

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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++)
		v.push_back({a[i], i});
	sort(v.begin(), v.end());
	vector<pair<int, int>>ans;
	for (auto i : v)
	{
		int j = i.second;
		for (int k = n - 1; k > j; k--)
			if (a[k] < a[j])
				ans.push_back({j, k});
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first + 1 << " " << i.second + 1 << "\n";

	return 0;
}