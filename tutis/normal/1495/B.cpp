/*input
7
1 2 4 6 5 3 7

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
	int n;
	cin >> n;
	int p[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int L[n], R[n];
	for (int i = 0; i < n; i++)
	{
		L[i] = R[i] = 1;
	}
	for (int i = 1; i < n; i++)
		if (p[i - 1] < p[i])
			L[i] = L[i - 1] + 1;
	for (int i = n - 2; i >= 0; i--)
		if (p[i + 1] < p[i])
			R[i] = R[i + 1] + 1;
	int ans = 0;
	int L_[n], R_[n];
	for (int i = 0; i < n; i++)
	{
		L_[i] = R_[i] = 1;
	}
	for (int i = 1; i < n; i++)
		if (p[i - 1] > p[i])
			L_[i] = L_[i - 1] + 1;
	for (int i = n - 2; i >= 0; i--)
		if (p[i + 1] > p[i])
			R_[i] = R_[i + 1] + 1;
	int mx = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int v : {L_[i], R_[i]})
		{
			if (v == mx)
				cnt++;
			else if (v > mx)
			{
				mx = v;
				cnt = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (L[i] == R[i] && (L[i] % 2 == 1))
		{
			if (L[i] == 1)
				continue;
			if (L[i] < mx)
				continue;
			if (cnt <= 2)
				ans++;
		}
	}
	cout << ans << "\n";
}