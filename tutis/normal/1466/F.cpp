/*input
3 5
2 1 2
1 3
1 4

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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
int pa[505050];
bool gali[505050];
int sz[505050];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m; i++)
	{
		pa[i] = i;
		gali[i] = false;
		sz[i] = 1;
	}
	gali[0] = true;
	vector<int>ans;
	function<pair<int, bool>(int)>root = [&](int i)->pair<int, bool>
	{
		while (i != pa[i])
		{
			int j = pa[i];
			if (pa[j] == j)
				return {j, false};
			else
			{
				j = pa[j];
				if (pa[j] != j)
					pa[i] = pa[j];
				i = j;
			}
		}
		return {i, true};
	};
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		int x;
		cin >> x;
		int y = 0;
		if (k == 2)
			cin >> y;
		pair<int, bool>a = root(x);
		pair<int, bool>b = root(y);
		if (sz[a.first] > sz[b.first])
			swap(a, b);
		if (a.first != b.first)
		{
			if (gali[a.first] && gali[b.first])
				continue;
			gali[b.first] |= gali[a.first];
			pa[a.first] = b.first;
			sz[b.first] += sz[a.first];
			ans.push_back(i);
		}
	}

	ll s = 1;
	for (int i : ans)
	{
		s *= 2;
		if (s >= mod)
			s -= mod;
	}
	cout << s << " " << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
}