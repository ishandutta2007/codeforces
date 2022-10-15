/*input
6
lollipops
stringology
abracadabra
codeforces
test
f

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int ans = 1;
		set<char>S;
		for (char c : s)
		{
			if (S.count(c) != 0)
				continue;
			if (S.size() <= 2)
				S.insert(c);
			else
			{
				S = {c};
				ans++;
			}
		}
		cout << ans << "\n";
	}
}