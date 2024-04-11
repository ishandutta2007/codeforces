/*input
lol

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll K[26];
ll B[26][26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	ll ans = 0;
	for (char c : s)
	{
		int i = c - 'a';
		for (int j = 0; j < 26; j++)
		{
			B[j][i] += K[j];
		}
		K[i]++;
	}
	for (int a = 0; a < 26; a++)
	{
		ans = max(ans, K[a]);
		for (int b = 0; b < 26; b++)
		{
			ans = max(ans, B[a][b]);
		}
	}
	cout << ans << "\n";
}