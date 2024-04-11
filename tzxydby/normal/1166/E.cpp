#include<bits/stdc++.h>
using namespace std;
int a[60][10005];
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		int s;
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
		{
			int x;
			scanf("%d",&x);
			a[i][x]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			int flag=0;
			for(int k=1;k<=n;k++)
				if(a[i][k]&&a[j][k])
					flag=1;
			if(!flag)
			{
				puts("impossible");
				return 0;
			}
		}
	}
	puts("possible");
	return 0;
}