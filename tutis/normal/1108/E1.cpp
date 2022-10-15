/*input
5 4
2 -2 3 1 2
1 3
4 5
2 5
1 3
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l[m], r[m];
	for (int i = 0; i < m; i++)
		cin >> l[i] >> r[i];
	vector<bool>idomu(n + 2, false);
	for (int i = 0; i < m; i++)
	{
		idomu[l[i]] = true;
		idomu[l[i] - 1] = true;
		idomu[r[i]] = true;
		idomu[r[i] + 1] = true;
	}
	idomu[n] = true;
	idomu[1] = true;
	int k = 1;
	for (int d = 1; d <= n; d++)
	{
		if (idomu[d])
		{
			if (k <= d - 1)
			{
				int i = max_element(a + k, a + d) - a;
				idomu[i] = true;
				i = min_element(a + k, a + d) - a;
				idomu[i] = true;
			}
			k = d + 1;
		}
	}
	vector<int>ID;
	for (int i = 1; i <= n; i++)
		if (idomu[i])
			ID.push_back(i);
	pair<int, vector<int>>ans = { -1, { -1}};
	for (int i : ID)
	{
		for (int j : ID)
		{
			vector<int>c;
			for (int k = 0; k < m; k++)
			{
				if (l[k] <= j && j <= r[k])
				{
					if (i > r[k] || i < l[k])
					{
						c.push_back(k);
					}
				}
			}
			ans = max(ans, {a[i] - a[j] + (int)c.size(), c});
		}
	}
	cout << ans.first << " " << ans.second.size() << "\n";
	for (int i : ans.second)
		cout << i + 1 << "\n";
}