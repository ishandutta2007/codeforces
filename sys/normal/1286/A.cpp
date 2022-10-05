#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, a[Maxn], cnt[4], f[Maxn][55][55][3];
int main()
{
//	freopen("A.in", "r", stdin);
	memset(f, 0x3f, sizeof(f));
	scanf("%d", &n);
	cnt[0] = n >> 1, cnt[1] = n - (n >> 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f[0][0][0][0] = f[0][0][0][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i])
			for (int j = !(a[i] & 1); j <= cnt[0]; j++)
				for (int k = (a[i] & 1); k <= cnt[1]; k++)
					for (int q = 0; q <= 1; q++)
							f[i][j][k][a[i] & 1] = min(f[i][j][k][a[i] & 1], f[i - 1][j - !(a[i] & 1)][k - (a[i] & 1)][q] + (q != (a[i] & 1)));
		else 
			for (int j = 0; j <= cnt[0]; j++)
				for (int k = 0; k <= cnt[1]; k++)
					for (int q = 0; q <= 1; q++)
						for (int p = 0; p <= 1; p++)
							f[i][j][k][p] = min(f[i][j][k][p], f[i - 1][j - !p][k - p][q] + (q != p));
	}
	printf("%d", min(f[n][cnt[0]][cnt[1]][0], f[n][cnt[0]][cnt[1]][1]));
	return 0;
}