/*input
5
0 1 1 -2 1
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
	int n;
	cin >> n;
	int b[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		int a = mx + b[i];
		cout << a << " ";
		mx = max(mx, a);
	}
	return 0;
}