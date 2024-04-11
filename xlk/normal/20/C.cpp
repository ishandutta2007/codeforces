#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<pair<int, int> > a[100020];
long long d[100020];
int p[100020];
set<pair<int, int> > q;
void print(int x)
{
	if (x != 1)
	{
		print(p[x]);
	}
	cout << x << ' ';		
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	q.insert(make_pair(d[1], 1));
	while (q.size() > 0)
	{
		int u = q.begin()->second;
		q.erase(q.begin());
		for (pair<int, int> e: a[u])
		{
			if (d[e.first] > d[u] + e.second)
			{
				q.erase(make_pair(d[e.first], e.first));
				d[e.first] = d[u] + e.second;
				p[e.first] = u;
				q.insert(make_pair(d[e.first], e.first));
			}
		}
	}
	if (d[n] > 1e18)
	{
		cout << -1 << endl;
	}
	else
	{
		print(n);
	}
	return 0;
}