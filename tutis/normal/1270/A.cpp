/*input
2
2 1 1
2
1
5 2 3
2 3
1 4 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		bool yes = false;
		while (k1--)
		{
			int x;
			cin >> x;
			if (x == n)
			{
				yes = true;
			}
		}
		while (k2--)
		{
			int x;
			cin >> x;
		}
		if (yes)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}