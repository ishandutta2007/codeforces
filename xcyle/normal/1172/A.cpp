#include <iostream>
#include <cstdio>
#define maxn 200005
using namespace std;
int n, a[maxn], b[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]); 
	}
	int pos = 0, p = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		if(b[i] == 1) p = i;
		if(b[i] != 0) pos = max(pos, i - b[i] + 1);
	}
	int flag = 1;
	if(!p)
	{
		flag = 0;
		p = 1;
	}
	for (int i = p; i <= n; i++)
	{
		if(b[i] != i - p + 1) flag = 0;
	}
	int ans = pos + n;
	if(flag)
	{
		pos = 0;
		for (int i = 1; i < p; i++)
		{
			if(b[i] != 0) pos = max(pos, i - (b[i] - b[n]) + 1);
		}
		if(!pos) ans = p - 1;
	}
	printf("%d", ans);
	return 0;
}