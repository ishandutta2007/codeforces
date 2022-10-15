/*input
3
2 1 3
3 3 6
99995 9998900031 9998900031

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
void get(ll n, ll l, ll r)
{
	vector<pair<ll, ll>>A;
	A.push_back({1, n - 2});
	A.push_back({n, 0});
	for (int x = 2; x < n; x++)
	{
		A.push_back({x, n - x - 1});
		A.push_back({n, 0});
	}
	A.push_back({1, 0});
	ll id = 1;
	for (pair<int, int>i : A)
	{
		if (l == id)
		{
			cout << i.first << " ";
			l++;
			if (l > r)
				return;
		}
		id++;
		int x = i.first;
		if (l > id + i.second * 2 + 2)
		{
			id += i.second * 2;
		}
		else
			while (i.second > 0)
			{
				i.second--;
				x++;
				if (l == id)
				{
					cout << x << " ";
					l++;
					if (l > r)
						return;
				}
				id++;
				if (l == id)
				{
					cout << i.first << " ";
					l++;
					if (l > r)
						return;
				}
				if (l > r)
					return;
				id++;
			}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		ll n, l, r;
		cin >> n >> l >> r;
		get(n, l, r);
		cout << "\n";
	}
	return 0;
}