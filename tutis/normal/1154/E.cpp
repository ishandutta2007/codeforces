/*input
5 1
2 4 5 3 1

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
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
};
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	set<pair<int, int>, greater<pair<int, int>>>A;
	for (int i = 0; i < n; i++)
		A.insert({a[i], i});
	set<int>B;
	for (int i = 0; i < n; i++)
		B.insert(i);
	string ans(n, '0');
	char c = '1';
	while (!B.empty())
	{
		int i = A.begin()->second;
		for (int t = 0; t <= k; t++)
		{
			auto it = B.lower_bound(i);
			if (it != B.end())
			{
				ans[*it] = c;
				A.erase({a[*it], *it});
				B.erase(*it);
			}
		}
		for (int t = 1; t <= k; t++)
		{
			auto it = B.lower_bound(i);
			if (it != B.begin())
			{
				it--;
				ans[*it] = c;
				A.erase({a[*it], *it});
				B.erase(*it);
			}
		}
		c ^= '1';
		c ^= '2';
	}
	cout << ans << "\n";
	return 0;
}