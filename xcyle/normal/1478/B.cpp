#include <iostream>
#include <cstdio>
#define maxn 105
using namespace std;
int t, q, d, a;
int f[maxn];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &q, &d);
		f[0] = 1;
		for (int i = 1; i <= 100; i++)
		{
			f[i] = 0;
			for (int j = 1; j <= i; j++)
			{
				if(j % 10 == d || (j / 10) == d) f[i] |= f[i - j];
			}
		}
		for (int i = 1; i <= q; i++)
		{
			scanf("%d", &a);
			if(a > 100) printf("YES\n");
			else
			{
				if(f[a]) printf("Yes\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}