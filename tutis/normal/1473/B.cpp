/*input
3
baba
ba
aa
aaa
aba
ab

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
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		string s;
		string ans = "-1";
		for (int l = 1; l <= a.size() * b.size(); l++)
		{
			s.push_back(a[(l - 1) % a.size()]);
			if (a[(l - 1) % a.size()] != b[(l - 1) % b.size()])
				break;
			if (s.size() % a.size() == 0 && s.size() % b.size() == 0)
			{
				ans = s;
				break;
			}
		}
		cout << ans << "\n";
	}
}