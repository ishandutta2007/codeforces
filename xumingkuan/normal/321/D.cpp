#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n, x, a[40][40], s[40], ans = -1010101010;
bool b[40];
int main()
{
	scanf("%d", &n);
	x = (n + 1) >> 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < (1 << x); i++)
	{
		for(int k = 1; k <= n; k++)
			b[k] = (k > x ? (((i >> (k - x - 1)) & 1) ^ ((~i >> (x - 1)) & 1)) : ((i >> (k - 1)) & 1));
		int sum = 0;
		for(int j = 1; j < x; j++)
		{
			for(int k = 1; k <= n; k++)
				s[k] = (b[k] ? a[j + x][k] : -a[j + x][k]) + a[j][k];
			int tmp1 = s[x];
			for(int k = 1; k < x; k++)
				tmp1 = tmp1 + abs(s[k] + s[k + x]);
			int tmp2 = -s[x];
			for(int k = 1; k < x; k++)
				tmp2 = tmp2 + abs(s[k] - s[k + x]);
			sum += max(tmp1, tmp2);
		}
		for(int k = 1; k <= n; k++)
			sum = sum + (b[k] ? a[x][k] : -a[x][k]);
		if(sum > ans)
			ans = sum;
	}
	printf("%d\n", ans);
	return 0;
}