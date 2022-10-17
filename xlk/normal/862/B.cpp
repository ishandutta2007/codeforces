#include <bits/stdc++.h>
using namespace std;
int n, x, y, c[2];
vector<int> a[100020];
void dfs(int x, int y, int d)
{
	c[d]++;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x, d ^ 1);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0, 0);
	cout << (long long)c[0] * c[1] - n + 1 << endl;
	return 0;
}