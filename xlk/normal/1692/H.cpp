#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		map<int, vector<int> > g;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			g[a[i]].push_back(i);
		}
		int z = 0, za = 0, zl = 0, zr = 0;
		for (auto i : g)
		{
			int s = 0, k = 0, l = 0;
			for (int j : i.second)
			{
				s -= j - k - 1;
				if (s <= 0)
				{
					s = 0;
					l = j;
				}
				s++;
				if (z < s)
				{
					z = s;
					za = i.first;
					zl = l;
					zr = j;
				}
				k = j;
			}
		}
		cout << za << " " << zl << " " << zr << endl;
	}
	return 0;
}