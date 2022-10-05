#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, x[Maxn], y[Maxn];
vector <int> Ve[3];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	A:for (int i = 1; i <= n; i++)
		Ve[(x[i] + y[i]) & 1].push_back(i);
	if (!(Ve[0].size() % n))
	{
		for (int i = 1; i <= n; i++)
		{
			int tmpx = x[i], tmpy = y[i];
			x[i] = (tmpx + tmpy) >> 1;
			y[i] = (tmpx - tmpy) >> 1;
		}
		Ve[0].clear();
		Ve[1].clear();
		goto A;
	}
	printf("%d\n", Ve[0].size());
	for (vector <int> :: iterator it = Ve[0].begin(); it != Ve[0].end(); it++)
		printf("%d ", *it);
	return 0;
}