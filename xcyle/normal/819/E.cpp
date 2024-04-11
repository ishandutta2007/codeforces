#include <iostream>
#include <cstdio>
#define maxn 305
using namespace std;
int n, t, k, cnt[maxn * maxn], a[maxn * maxn][4];
void work(int l, int r)
{
	if(r - l + 1 == 3)
	{
		cnt[++k] = 3;
		a[k][1] = l, a[k][2] = l + 1, a[k][3] = l + 2;
		cnt[++k] = 3;
		a[k][1] = l, a[k][2] = l + 1, a[k][3] = l + 2;
		return;
	}
	if(r - l + 1 == 4)
	{
		cnt[++k] = 4;
		a[k][1] = l, a[k][2] = l + 1, a[k][3] = l + 2, a[k][4] = l + 3;
		cnt[++k] = 4;
		a[k][1] = l, a[k][2] = l + 1, a[k][3] = l + 3, a[k][4] = l + 2;
		cnt[++k] = 4;
		a[k][1] = l, a[k][2] = l + 3, a[k][3] = l + 1, a[k][4] = l + 2;
		return;
	}
	if(3 * t > l)
	{
		work(l + 3, r);
		if((r - l + 1) % 2 == 0)
		{
			cnt[++k] = 3;
			a[k][1] = l, a[k][2] = l + 1, a[k][3] = l + 2;
			for (int i = l; i <= l + 2; i++)
			{
				for (int j = l + 3; j < r; j += 2)
				{
					cnt[++k] = 4;
					a[k][1] = i;
					a[k][2] = j;
					a[k][3] = i == l + 2 ? l : i + 1;
					a[k][4] = j == r ? l + 3 : j + 1;
				}
			}
			cnt[++k] = 3;
			a[k][1] = l, a[k][2] = l + 1, a[k][3] = r;
			cnt[++k] = 3;
			a[k][1] = l, a[k][2] = l + 2, a[k][3] = r;
			cnt[++k] = 3;
			a[k][1] = l + 1, a[k][2] = l + 2, a[k][3] = r;
		}
		else
		{
			work(l, l + 2);
			for (int i = l; i <= l + 2; i++)
			{
				for (int j = l + 3; j <= r; j += 2)
				{
					cnt[++k] = 4;
					a[k][1] = i;
					a[k][2] = j;
					a[k][3] = i == l + 2 ? l : i + 1;
					a[k][4] = j == r ? l + 3 : j + 1;
				}
			}
		}
	}
	else
	{
		work(l, r - 4);
		work(r - 3, r);
		for (int i = l; i <= r - 4; i++)
		{
			for (int j = r - 3; j <= r; j += 2)
			{
				cnt[++k] = 4;
				a[k][1] = i;
				a[k][2] = j;
				a[k][3] = i == r - 4 ? l : i + 1;
				a[k][4] = j == r ? r - 3 : j + 1;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n / 3; i++)
	{
		if((n - i * 3) % 4 == 0)
		{
			t = i;
			work(1, n);
			break;
		}
	}
	if(n == 5)
	{
		printf("6\n3 5 4 2\n3 3 1 5\n4 4 5 2 3\n4 4 3 2 1\n3 4 2 1\n3 3 1 5");
		return 0;
	}
	printf("%d\n", k);
	for (int i = 1; i <= k; i++)
	{
		printf("%d ", cnt[i]);
		for (int j = 1; j <= cnt[i]; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}