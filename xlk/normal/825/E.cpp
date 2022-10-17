#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[200020];
int d[200020];
int p[200020];
priority_queue<int> q;
int main()
{
	cin >> n >> m;
	int c = n;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[y].push_back(x);
		d[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size() > 0)
	{
		int x = q.top();
		p[x] = c--;
		q.pop();
		for (int i: a[x])
		{
			if (--d[i] == 0)
			{
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << p[i] << ' ';
	}
	return 0;
}