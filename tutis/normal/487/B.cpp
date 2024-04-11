/*input
7 2 2
1 3 1 2 4 1 2
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, s, l;
	cin >> n >> s >> l;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int dp[n + 1];
	dp[n] = 0;
	deque<int>mx;
	deque<int>mn;
	int j = n - 1;
	deque<int>D;
	for (int i = n - 1; i >= 0; i--)
	{
		if (i + l - 1 <= j)
		{
			while (!D.empty() && dp[D.back()] >= dp[i + l])
				D.pop_back();
			D.push_back(i + l);
		}
		while (!mx.empty() && a[mx.back()] <= a[i])
			mx.pop_back();
		while (!mn.empty() && a[mn.back()] >= a[i])
			mn.pop_back();
		mx.push_back(i);
		mn.push_back(i);
		while (a[mx.front()] - a[mn.front()] > s)
		{
			if (j >= i + l - 1)
			{
				if (!D.empty() && D.front() == j + 1)
					D.pop_front();
			}
			if (mx.front() == j)
				mx.pop_front();
			if (mn.front() == j)
				mn.pop_front();
			j--;
		}
		dp[i] = n + 1;
		if (!D.empty())
			dp[i] = dp[D.front()] + 1;
	}
	if (dp[0] > n)
		dp[0] = -1;
	cout << dp[0] << "\n";
}