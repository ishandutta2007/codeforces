/*input
5
1 4 1 4 9

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
	int a[n];
	for (int &i : a)
		cin >> i;
	map<int, int>M;
	for (int i : a)
		M[i] = 0;
	int s = 0;
	for (auto&i : M)
		i.second = s++;
	for (int &i : a)
		i = M[i];
	int lo = 0;
	int hi = n - 1;
	while (lo < hi)
	{
		int x = (lo + hi) / 2;
		bool ok = false;
		for (int l = 0; l + x - 1 < n; l++)
		{
			int r = l + x - 1;
			bool ger = true;
			vector<bool>X(n, false);
			for (int i = 0; i < n; i++)
			{
				if (l <= i && i <= r)
					continue;
				if (X[a[i]])
				{
					ger = false;
					break;
				}
				X[a[i]] = true;
			}
			ok |= ger;
		}
		if (ok)
			hi = x;
		else
			lo = x + 1;
	}
	cout << lo << "\n";
}