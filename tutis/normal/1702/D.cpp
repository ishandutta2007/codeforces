/*input
5
abca
2
abca
6
codeforces
1
codeforces
10
codeforces
100

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
		ll mx;
		cin >> mx;
		vector<int>p[27];
		ll sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			sum += s[i] - 'a' + 1;
			p[s[i] - 'a' + 1].push_back(i);
		}
		for (int i = 26; i >= 1; i--)
		{
			while (p[i].size() > 0 && sum > mx)
			{
				sum -= i;
				p[i].pop_back();
			}
		}
		set<int>S;
		for (int i = 1; i <= 26; i++)
			for (int j : p[i])
				S.insert(j);
		for (int i : S)
			cout << s[i];
		cout << "\n";
	}
}