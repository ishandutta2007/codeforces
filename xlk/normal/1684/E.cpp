#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		map<int, int> c;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			c[x]++;
		}
		int l = m;
		for (int i = 0; i <= n; i++)
		{
			if (c.find(i) == c.end())
			{
				if (l == 0)
				{
					break;
				}
				l--;
			}
			else
			{
				c.erase(i);
			}
		}
		vector<int> b;
		for (auto i : c)
		{
			b.push_back(i.second);
		}
		sort(b.begin(), b.end());
		int i;
		for (i = 0; i < b.size(); i++)
		{
			if (m < b[i])
			{
				break;
			}
			m -= b[i];
		}
		cout << b.size() - i << endl;
	}
	return 0;
}