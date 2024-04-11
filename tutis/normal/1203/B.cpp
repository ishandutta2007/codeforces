/*input
5
1
1 1 10 10
2
10 5 2 10 1 1 2 5
2
10 5 1 10 5 1 1 1
2
1 1 1 1 1 1 1 1
1
10000 10000 10000 10000
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		int a[4 * n];
		for (int &i : a)
			cin >> i;
		bool ok = false;
		for (int t = 0; t < 4 * n; t++)
		{
			int S = a[0] * a[t];
			vector<int>K(10101, 0);
			for (int t = 0; t < 4 * n; t++)
				K[a[t]]++;
			bool k = true;
			for (int j = 0; j < 4 * n; j++)
			{
				if (K[a[j]] == 0)
					continue;
				K[a[j]] -= 2;
				if (S % a[j] != 0 || S / a[j] >= K.size())
				{
					k = false;
					break;
				}
				K[S / a[j]] -= 2;
				if (K[S / a[j]] < 0 || K[a[j]] < 0)
					k = false;
			}
			ok |= k;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}