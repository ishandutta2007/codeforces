/*input
5
5
5 9 2 10 15
6
1 2 4 2 4 2
2
1 2
1
1
1
2

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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
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
		set<int>S;
		set<int>I;
		for (int i = 0; i < n; i++)
		{
			I.insert((i + 1) % n);
			if (__gcd(a[i], a[(i + 1) % n]) == 1)
				S.insert((i + 1) % n);
		}
		int i = 0;
		vector<int>ans;
		while (!S.empty())
		{
			auto it = S.upper_bound(i);
			if (it == S.end())
				it = S.begin();
			int v = *it;
			ans.push_back(v);
			S.erase(v);
			I.erase(v);
			it = I.upper_bound(v);
			if (it == I.end())
				it = I.begin();
			i = *it;
			if (!I.empty())
			{
				it = I.lower_bound(i);
				if (it == I.begin())
					it = I.end();
				it--;
				int j = *it;
				if (__gcd(a[j], a[i]) == 1)
					S.insert(i);
				else if (S.count(i))
					S.erase(i);
			}
		}
		cout << ans.size() << " ";
		for (int i : ans)
			cout << i + 1 << " ";
		cout << "\n";
	}
}