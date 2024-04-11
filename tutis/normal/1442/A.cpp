/*input
4
3
1 2 1
5
11 7 9 6 8
5
1 3 1 3 1
4
5 2 1 10

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bool ok = true;
		int v1 = a[0];
		int v0 = 0;
		for (int i = 1; i < n; i++)
		{
			// x <= v1
			// a[i] - v0 >= x
			ll x = min(a[i] - v0, v1);
			if (x > v1)
				ok = false;
			v1 = x;
			v0 = a[i] - x;
			if (a[i] - x < v0)
				ok = false;
			if (v0 < 0 || v1 < 0)
				ok = false;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}