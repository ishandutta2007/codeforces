/*input
1
1

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
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int S[n];
	for (int i = 0; i < n; i++)
		cin >> S[i];
	for (int x = 18; x >= 0; x--)
	{
		int maxi = (1 << x) - 1;
		vector<int>V;
		vector<int>W;
		for (int i : S)
		{
			if (i > maxi)
				continue;
			int j = i;
			for (int a : W)
			{
				if ((j ^ a) < j)
					j ^= a;
			}
			if (j != 0)
			{
				W.push_back(j);
				sort(W.begin(), W.end(), greater<int>());
				V.push_back(i);
			}
		}
		if ((int)V.size() == x)
		{
			cout << x << "\n";
			vector<int>A = {0};
			for (int v : V)
			{
				int sz = A.size();
				for (int i = 0; i < sz; i++)
					A.push_back(A[i] ^ v ^ A[sz - 1]);
			}
			for (int v : A)
				cout << v << " ";
			cout << "\n";
			return 0;
		}
	}
}