#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int x[5020];
int y[5020];
vector<int> a[5020];
int d[5020];
queue<int> q;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x[i] >> y[i];
		a[x[i]].push_back(y[i]);
		d[y[i]]++;
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
		int x = q.front();
		c++;
		q.pop();
		for (int i: a[x])
		{
			if (--d[i] == 0)
			{
				q.push(i);
			}
		}
	}
	if (c == n)
	{
		cout << 1 << endl;
		for (int i = 0; i < m; i++)
		{
			cout << 1 << ' ';
		}
	}
	else
	{
		cout << 2 << endl;
		for (int i = 0; i < m; i++)
		{
			if (x[i] < y[i])
			{
				cout << 1 << ' ';
			}
			else
			{
				cout << 2 << ' ';
			}
		}
	}
	return 0;
}