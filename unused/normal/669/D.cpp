#include <stdio.h>

int pos[1000005];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);

	int evenmove = 0, oddmove = 0;
	for (int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int tt;
			scanf("%d", &tt);
			evenmove = ((evenmove + tt) + n) % n;
			oddmove = ((oddmove + tt) + n) % n;
		}
		else
		{
			if (evenmove % 2 == 0)
				evenmove = (evenmove + n - 1) % n;
			else
				evenmove = (evenmove + 1) % n;

			if (oddmove % 2 == 0)
				oddmove = (oddmove + 1) % n;
			else
				oddmove = (oddmove + n - 1) % n;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			int t = (i + evenmove) % n;
			if (t == 0) t = n;
			pos[t] = i;
		}
		else
		{
			int t = (i + oddmove) % n;
			if (t == 0) t = n;
			pos[t] = i;
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", pos[i]);
	printf("\n");
}