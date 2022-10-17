#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int n, m, x, y, z;
int b[100020];
void dfs(int x, int y, int c)
{
	if (b[x])
	{
		c++;
	}
	else
	{
		c = 0;
	}
	if (c > m)
	{
		return;
	}
	int t = 0;
	for (int i: a[x])
	{
		if (i != y)
		{
			t++;
			dfs(i, x, c);
		}
	}
	if (t == 0)
	{
		z++;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0, 0);
	cout << z << endl;
	return 0;
}