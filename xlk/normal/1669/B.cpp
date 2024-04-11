#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		map<int, int> g;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			g[x]++;
		}
		int z = -1;
		for (auto i: g)
		{
			if (i.second >= 3)
			{
				z = i.first;
			}
		}
		cout << z << endl;
	}
	return 0;
}