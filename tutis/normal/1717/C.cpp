/*input
5
3
1 2 5
1 2 5
2
2 2
1 3
4
3 4 1 2
6 4 2 5
3
2 4 1
4 5 3
5
1 2 3 4 5
6 5 6 7 6

*/
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
		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		bool ch = true;
		for (int i = 0; i < n; i++)
			if (a[i] > b[i])
				ch = false;
		while (ch) {
			ch = false;
			for (int i = n - 1; i >= 0; i--)
			{
				int i1 = i + 1;
				if (i1 == n)
					i1 = 0;
				if (min(a[i1] + 1, b[i]) > a[i])
				{
					a[i] = min(a[i1] + 1, b[i]);
					ch = true;
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++)
			if (a[i] != b[i])
				ok = false;
		if (!ok)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}