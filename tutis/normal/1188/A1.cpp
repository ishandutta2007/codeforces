/*input
6
1 2
1 3
1 4
2 5
2 6

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>d(n + 1, 0);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u]++;
		d[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 2)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}