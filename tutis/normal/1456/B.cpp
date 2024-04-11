/*input
5
1 2 4 6 20

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, less<T>, null_type, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i + 1 < n; i++)
	{
		if ((a[i]^a[i + 1]) < a[i - 1])
		{
			cout << "1\n";
			return 0;
		}
		if ((a[i]^a[i - 1]) > a[i + 1])
		{
			cout << "1\n";
			return 0;
		}
	}
	int ret = n + 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int xi = 0;
			for (int i1 = i; i1 >= 0; i1--)
			{
				xi ^= a[i1];
				int xj = 0;
				for (int j1 = j; j1 < n; j1++)
				{
					xj ^= a[j1];
					if (xj < xi)
					{
						ret = min(ret, j1 - i1 - 1);
					}
				}
			}
		}
	}
	if (ret > n)
		ret = -1;
	cout << ret << "\n";
}