#include <bits/stdc++.h>
using namespace std;
int a[20];
int b[20];
int t, n, c;
set<int> d, e;
void fac(int n)
{
	d.clear();
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			d.insert(i);
			d.insert(n / i);
		}
	}
	d.erase(1);
	c = 0;
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			a[c] = i;
			while (n % i == 0)
			{
				b[c]++;
				n /= i;
			}
			c++;
		}
	}
	if (n > 1)
	{
		a[c] = n;
		b[c++] = 1;
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		fac(n);
		if (c == 2 && b[0] == 1 && b[1] == 1)
		{
			printf("%d %d %d\n", a[0], n, a[1]);
			printf("1\n");
		}
		else if (c > 2)
		{
			for (int i = 0; i < c; i++)
			{
				d.erase(a[i]);
				d.erase(a[i] * a[(i+1) % c]);
			}
			for (int i = 0; i < c; i++)
			{
				printf("%d ", a[i]);
				e.clear();
				for (int j: d)
				{
					if (j % a[i] == 0)
					{
						printf("%d ", j);
						e.insert(j);
					}
				}
				for (int j: e)
				{
					d.erase(j);
				}
				printf("%d ", a[i] * a[(i+1) % c]);
			}
			printf("\n");
			printf("0\n");
		}
		else
		{
			int p;
			for (p = 0; p < c; p++)
			{
				if (b[p] >= 2)
				{
					break;
				}
			}
			if (c == 1)
			{
				p = 0;
			}
			for (int i: d)
			{
				if (i % a[p] != 0)
				{
					printf("%d ", i * a[p]);
					printf("%d ", i);
					i *= a[p];
					i *= a[p];
					for (int j = 2; j <= b[p]; j++)
					{
						printf("%d ", i);
						i *= a[p];
					}
				}
			}
			for (int i = 1, j = a[p]; i <= b[p]; i++, j *= a[p])
			{
				printf("%d ", j);
			}
			printf("\n");
			printf("0\n");
		}
	}
	return 0;
}