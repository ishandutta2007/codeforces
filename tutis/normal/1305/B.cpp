/*input
(()((

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,aes,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
using Map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1000000000 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	vector<vector<int>>ans;
	while (true)
	{
		vector<int>x;
		int l = 0;
		int r = (int)s.size() - 1;
		while (l < r)
		{
			if (s[l] == ')')
				l++;
			else if (s[r] == '(')
				r--;
			else {
				x.push_back(l);
				x.push_back(r);
				l++;
				r--;
			}
		}
		if (x.empty())
			break;
		sort(x.begin(), x.end());
		ans.push_back(x);
		reverse(x.begin(), x.end());
		for (int i : x)
			s.erase(s.begin() + i);
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
	{
		cout << i.size() << "\n";
		for (int j : i)
			cout << j + 1 << " ";
		cout << "\n";
	}
}