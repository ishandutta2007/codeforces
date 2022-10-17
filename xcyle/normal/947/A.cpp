#include <iostream>
#include <cstdio>
#define maxn 1000005
using namespace std;
int x2;
int vis[maxn], mx[maxn];
int main()
{
	for (int i = 2; i < maxn; i++)
	{
		for (int j = 2 * i; j < maxn; j += i) 
		{
			vis[j] = 1;
			if(vis[i] == 0) mx[j] = i;
		}
	}
	scanf("%d", &x2);
	int ans = 10000000;
	for (int i = 2; i <= x2; i++)
	{
		if(x2 % i == 0 && !vis[i])
		{
			for (int j = x2; j > x2 - i; j--)
			{
				ans = min(ans, j - mx[j] + 1);
			}
		}
	}
	printf("%d", ans);
	return 0;
}