#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int p = 1, now = n, flag = 1;
		while(p <= n)
		{
			if(!flag) break;
			for (int i = p; i <= p + now - a[p]; i++)
			{
				if(a[i] != a[p] + i - p) flag = 0;
			}
			int tmp = p;
			p = p + now - a[p] + 1;
			now = a[tmp] - 1;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}