#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 2005;
int n, now, x[Maxn], y[Maxn];
string str;
bool vis[Maxn];
long long cross(int a, int b, int c)
{
	return (x[a] - x[b]) * (long long) (y[b] - y[c]) - (x[b] - x[c]) * (long long) (y[a] - y[b]);
}
int main()
{
	x[now] = 1e9 + 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		if (make_pair(x[i], y[i]) < make_pair(x[now], y[now])) now = i;
	}
	cin >> str;
	printf("%d ", now), vis[now] = true;
	for (int i = 0; i < n - 2; i++)
	{
		int pos = 0;
		for (int j = 1; j <= n; j++)
		{
			if (vis[j]) continue;
			if (!pos) pos = j;
			if (str[i] == 'L' && cross(now, pos, j) < 0) pos = j;
			if (str[i] == 'R' && cross(now, pos, j) > 0) pos = j;
		}
		printf("%d ", now = pos), vis[now] = true;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) printf("%d ", i);
	return 0;
}