#include <cstdio>
#include <memory.h>

#define A 32000
#define B 40

int a, b, n, cb;
char g[A][B];
long long f;

void go(int a, int b)
{
	if (a == A-1 && b == 1)
	{
		g[a][b] = !((n - a) & 1);
		return;
	}
	cb = b; f = 1;
	while (cb-- && f < n)
		f *= a;
	if (f >= n)
	{
		g[a][b] = true;
		return;
	}
	if (g[a + 1][b] == 3)
		go(a + 1, b);
	if (!g[a + 1][b])
	{
		g[a][b] = true;
		return;
	}
	if (g[a][b + 1] == 3)
		go(a, b + 1);
	g[a][b] = !g[a][b + 1];
}


int main()
{
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 1; i < A; i++)
		for (int j = 1; j < B; j++)
			g[i][j] = 3;
	if (a == 1)
	{
		if (1<<b >= n)
		{
			puts("Missing");
			return 0;
		}
	}
	go(a, b);
	if (!g[a][b])
		puts("Stas");
	else puts("Masha");
}