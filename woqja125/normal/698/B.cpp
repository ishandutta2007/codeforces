#include<stdio.h>
int p[200001];
int v[200001];
int main()
{
	int n, r = 0, i, c = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", p + i);
	}
	for (i = 1; i <= n; i++)
	{
		if (p[i] == i)
		{
			if (r == 0) r = i;
			else
			{
				c++; p[i] = r;
			}
		}
	}
	v[r] = 2;
	for (i = 1; i <= n; i++)
	{
		int x = i;
		if (v[x] != 0) continue;
		v[x] = 1;
		while (v[p[x]] == 0)
		{
			x = p[x];
			v[x] = 1;
		}
		if (r == 0)
		{
			r = x;
			v[r] = 2;
			p[r] = r;
			c++;
		}
		else if(v[p[x]] == 1)
		{
			p[x] = r; c++;
		}

		x = i;
		v[x] = 2;
		while (v[p[x]] == 1)
		{
			x = p[x];
			v[x] = 2;
		}
	}
	printf("%d\n", c);
	for (i = 1; i <= n; i++)printf("%d ", p[i]);
	return 0;
}