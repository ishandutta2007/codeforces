#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 305
using namespace std;
int vis[maxn], T, n, x;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		int tmp = 0, mx = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if(x < 0) tmp = 1;
			else
			{
				vis[x] = 1;
				mx = max(mx, x);
			}
		}
			if(tmp) printf("NO\n");
			else
			{
				printf("YES\n");
                if(vis[0])
				{
                	printf("%d\n", mx + 1);
                	for (int j = 0; j <= mx; j++) printf("%d ", j);
                    printf("\n");
                }
				else
				{
                	printf("%d\n", mx);
                	for (int j = 1; j <= mx; j++) printf("%d ", j);
                	printf("\n");
                }
			}
	}
    return 0;
}