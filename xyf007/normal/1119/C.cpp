#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,m,line[501],column[501],a[501][501];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			if(x!=a[i][j])
			{
				line[i]++;
				column[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(line[i]&1)
		{
			printf("No");
			return 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(column[i]&1)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}