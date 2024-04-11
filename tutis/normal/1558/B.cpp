/*input
787788 100000007

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
//const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> DP(4000001, 0);
	vector<int> A(4000001, 0);
	DP[1] = 1;
	int suma = 1;
	for (int k = 2; k < 4000001; k++)
	{
		int a = 1;
		int mn = a * k;
		int mx = (a + 1) * k;
		A[mn] += DP[a];
		if (A[mn] >= m)
			A[mn] -= m;
		if (mx < 4000001)
		{
			A[mx] -= DP[a];
			if (A[mx] < 0)
				A[mx] += m;
		}
	}
	int suma1 = 0;
	for (int a = 2; a < 4000001; a++)
	{
		suma1 += A[a];
		if (suma1 >= m)
			suma1 -= m;
		DP[a] = suma + suma1;
		if (DP[a] >= m)
			DP[a] -= m;
		suma += DP[a];
		if (suma >= m)
			suma -= m;
		for (int k = 2; a * k < 4000001; k++)
		{
			int mn = a * k;
			int mx = (a + 1) * k;
			A[mn] += DP[a];
			if (A[mn] >= m)
				A[mn] -= m;
			if (mx < 4000001)
			{
				A[mx] -= DP[a];
				if (A[mx] < 0)
					A[mx] += m;
			}
		}
	}
	cout << DP[n] << "\n";
}