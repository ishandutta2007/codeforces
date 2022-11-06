#include<stdio.h>
double p[21], ans[21], P[(1<<20)+10];
int n, sel[21], k, z;
void endcomb(int c)
{
	double sp = 0, pp = 0;
	int i, bit=0;
	if (c > k || c == 0) return;
	for (i = 1; i <= n; i++)
	{
		if (sel[i] == 1)
		{
			sp += p[i];
			bit |= 1 << (i - 1);
		}
	}
	//
	for (i = 1; i <= n; i++)
	{
		if (sel[i] == 1)
		{
			pp += p[i] / (1 - sp + p[i]) * P[bit - (1<<(i-1))];
		}
	}

	P[bit] = pp;

	if (k == c)
	for (i = 1; i <= n; i++)
	{
		if (sel[i] == 0) ans[i] -= pp;
	}

}
void comb(int x, int c)
{
	if (x == n + 1)
	{
		endcomb(c);
		return;
	}
	comb(x + 1, c);
	if(p[x] != 0)
	{
		sel[x] = 1;
		comb(x + 1, c + 1);
		sel[x] = 0;
	}
}
int main()
{
	int i;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", p + i);
		ans[i] = 1;
	}
	P[0] = 1;
	comb(1, 0);
	for (i = 1; i <= n; i++) if (p[i] == 0) ans[i] = 0;
	for (i = 1; i <= n; i++)printf("%.30f ", ans[i]);
	return 0;
}