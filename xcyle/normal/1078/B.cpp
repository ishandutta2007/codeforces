#include <iostream>
#include <cstdio>
#define maxn 105
using namespace std;
int n, a, t[maxn];
int f[maxn * maxn][maxn];
int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		t[a]++;
	}
	f[0][0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		for (int j = maxn * maxn - 1; j >= i; j--)
		{
			for (int cnt = 0; cnt <= n; cnt++)
			{
				for (register int k = 1; k <= t[i]; k++)
				{
					if(cnt - k < 0 || j - k * i < 0) break;
					f[j][cnt] += f[j - k * i][cnt - k];
				}
			}
		}
	}
	int ans = 1, cnt = 0, x = 0;
	for (int i = 1; i < maxn; i++)
	{
		if(!cnt) x = t[i];
		if(t[i]) cnt++;
		for (int j = 1; j <= t[i]; j++)
		{
			if(f[j * i][j] == 1) ans = max(ans, j);
		}
	}
	if(cnt == 2 && x == ans || n - x == ans) ans = n;
	printf("%d", ans);
	return 0;
}