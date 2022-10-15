/*input
4
4
3 5 4 6
2 1
3 1
4 3
2
21 32
2 1
6
20 13 17 13 13 11
2 1
3 1
4 1
5 1
6 1
4
10 6 6 6
1 2
2 3
4 1

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
int dp[100000][2][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int w[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		vector<ll>S;
		vector<int>d(n + 1, 0);
		for (int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			d[a]++;
			d[b]++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int t = 1; t < d[i]; t++)
				S.push_back(w[i]);
		}
		sort(S.begin(), S.end(), greater<ll>());
		ll sum = 0;
		for (int i = 1; i <= n; i++)
			sum += w[i];
		for (int i = 0; i < n - 1; i++)
		{
			cout << sum << " ";
			if (i < S.size())
				sum += S[i];
		}
		cout << "\n";
	}
}