/*input
4 3 2 4
1 2 1
2 3 1
3 4 2
? 1 4
? 4 1
+ 3 1 2
? 4 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pa[101010];
set<int>adj[101010];
map<int, int>v[101010];
int root(int x)
{
	if (pa[x] == x)
		return x;
	return pa[x] = root(pa[x]);
}
void merge(int a, int b)
{
	a = root(a);
	b = root(b);
	if (a == b)
		return;
	if (adj[a].size() > adj[b].size())
		swap(a, b);
	for (int i : adj[a])
		adj[b].insert(i);
	adj[a].clear();
	pa[a] = b;
}
void add(int x, int y, int z)
{
	adj[root(x)].insert(y);
	adj[root(y)].insert(x);
	if (v[x].count(z))
		merge(y, v[x][z]);
	if (v[y].count(z))
		merge(x, v[y][z]);
	v[x][z] = y;
	v[y][z] = x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, c, q;
	cin >> n >> m >> c >> q;
	for (int i = 1; i <= n; i++)
	{
		adj[i].insert(i);
		pa[i] = i;
	}
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	while (q--)
	{
		char cc;
		int x, y;
		cin >> cc >> x >> y;
		if (cc == '?')
		{
			if (adj[root(x)].count(y))
			{
				cout << "Yes\n";
			}
			else
				cout << "No\n";
		}
		else
		{
			int z;
			cin >> z;
			add(x, y, z);
		}
	}
}