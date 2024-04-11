#include <cstdio>
#include <memory.h>

int n, m, f[110], l, r;

int main()
{
	scanf("%d%d", &n, &m);
	memset(f, 0, sizeof(f));
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		l--; r--;
		for (int i = l; i <= r; i++)
			f[i]++;
	}
	for (int i = 0; i < n; i++)
		if (f[i] != 1)
		{
			printf("%d %d", i + 1, f[i]);
			return 0;
		}
	puts("OK");
}