#include <bits/stdc++.h>
using namespace std;
int n, x, z, zi;
int f[200020];
int p[200020];
map<int, int> g;
vector<int> q;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		p[i] = g[x - 1];
		g[x] = i;
		f[i] = f[p[i]] + 1;
		if (z < f[i])
		{
			z = f[i];
			zi = i;
		}
	}
	while (zi)
	{
		q.push_back(zi);
		zi = p[zi];
	}
	printf("%d\n", z);
	for (int i = q.size() - 1; i >= 0; i--)
	{
		printf("%d ", q[i]);
	}
	return 0;
}