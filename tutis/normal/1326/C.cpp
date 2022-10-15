/*input
7 3
2 7 3 1 5 4 6

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
const ll mod = 998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(p.begin(), p.end(), greater<pair<int, int>>());
	while ((int)p.size() > k)
		p.pop_back();
	vector<int>a;
	for (auto i : p)
		a.push_back(i.second);
	sort(a.begin(), a.end());
	ll suma = 0;
	ll ans = 1;
	for (pair<int,int> i : p)
		suma += i.first;
	for (int t = 1; t < a.size(); t++)
	{
		ans *= (a[t] - a[t - 1]);
		ans %= mod;
	}
	cout << suma << " " << ans << "\n";
	return 0;
}