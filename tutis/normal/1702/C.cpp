/*input
3

6 3
3 7 1 5 1 4
3 5
1 7
3 10

3 3
1 2 1
2 1
1 2
4 5

7 5
2 1 1 1 2 4 4
1 3
1 4
2 1
4 1
1 2
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
		getline(cin, s);
		getline(cin, s);
		int n, k;
		cin >> n >> k;
		map<int, int>A, B;
		int v[n];
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			B[v[i]] = i;
		}
		int l = -1;
		int iki = -1;
		for (int i = 0; i < n; i++)
		{
			if (A.count(v[i]) == 0)
			{
				A[v[i]] = i;
				continue;
				if (i <= iki)
				{
					A[v[i]] = l;
					iki = max(iki, B[v[i]]);
				}
				else
				{
					A[v[i]] = i;
					l = i;
					iki = B[v[i]];
				}
			}
		}
		while (k--)
		{
			int a, b;
			cin >> a >> b;
			if (A.count(a) && B.count(b) && A[a] < B[b])
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}