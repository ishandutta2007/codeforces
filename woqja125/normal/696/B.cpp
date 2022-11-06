#include<stdio.h>

int p[100001];
int N[100001];
int e[100001];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) scanf("%d", p + i);
	for (i = n; i >= 2; i--)
	{
		N[i]++;
		N[p[i]] += N[i];
	}
	N[1]++;
	printf("1.0 ");
	e[1] = 2;
	for (i = 2; i <= n; i++)
	{
		e[i] = e[p[i]] + 1 + N[p[i]] - N[i];
		printf("%d.%d ", e[i] / 2, e[i] % 2 ? 5 : 0);
	}
	return 0;
}