#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, z;
map<int, int> g[100020];
int G(int x, int y)
{
	auto it = g[x].lower_bound(y);
	return it == g[x].begin() ? 0 : (--it)->second;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		int t = G(a, c) + 1;
		if (t > G(b, c + 1))
		{
			g[b][c] = t;
			for (auto it = g[b].upper_bound(c); it != g[b].end() && it->second <= t;)
			{
				g[b].erase(it++);
			}
		}
		z = max(z, t);
	}
	cout << z << endl;
	return 0;
}