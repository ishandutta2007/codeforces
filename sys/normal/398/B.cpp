#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
double f[Maxn][Maxn];
bool vis1[Maxn], vis2[Maxn];
int n, m, cnt1, cnt2;
int main()
{
	scanf("%d%d", &n, &m);
	cnt1 = cnt2 = n;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (!vis1[x]) vis1[x] = true, cnt1--;
		if (!vis2[y]) vis2[y] = true, cnt2--;
	}
	for (int i = 1; i <= cnt1; i++)
		f[i][0] = f[i - 1][0] + n / (double) i;
	for (int i = 1; i <= cnt2; i++)
		f[0][i] = f[0][i - 1] + n / (double) i;
	for (int i = 1; i <= cnt1; i++)
		for (int j = 1; j <= cnt2; j++)
			f[i][j] = (n * n + f[i - 1][j - 1] * i * j + f[i - 1][j] * i * (n - j) + f[i][j - 1] * (n - i) * j) / (n * n - (n - i) * (n - j));
	printf("%.10lf", f[cnt1][cnt2]);
	return 0;
}