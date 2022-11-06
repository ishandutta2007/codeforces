#include<stdio.h>
char in[500010];
int n;
int r[500001];
int l[500001];
int main()
{
	int a, b, T, i, j, t=0, max=0;
	scanf("%d%d%d%d%s", &n, &a, &b, &T, in);
	if (in[0] == 'h') T -= 1;
	else T -= 1 + b;
	if (T < 0)
	{
		printf("0"); return 0;
	}
	t = a;
	for (i = 1; i<n; i++)
	{
		if (in[i] == 'h') t += 1;
		else t += 1 + b;
		r[i] = t;
		t += a;
	}
	t = a;
	for (i = n-1; i>0; i--)
	{
		if (in[i] == 'h') t += 1;
		else t += 1 + b;
		l[i] = t;
		t += a;
	}
	j = n-1;
	for (i = n-1; i >= 0; i--)
	{
		if (r[i] > T) continue;
		for (; j>0 && a*i + r[i] + l[j] <= T; j--);
		t = i + n - j;
		if (max < t) max = t;
	}
	i = 0;
	for (j = 1; j<=n; j++)
	{
		if (l[j] > T) continue;
		for (; i<n && a*(n-j) + r[i] + l[j] <= T; i++);
		t = i + n - j;
		if (max < t) max = t;
	}
	if (max > n) max = n;
	printf("%d", max);
	return 0;
}