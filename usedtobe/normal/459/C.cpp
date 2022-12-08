#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int ans[2333][2333];

int main()
{
	int i,j,k,m,n,d,delta,l,r;
	scanf("%d%d%d",&n,&k,&d);
	delta=1;
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=n;j++)
		{
			ans[i][j]=1;
		}
	}
	for(i=1;i<=d;i++)
	{
		delta*=k;
		if(delta>=n)
		{
			for(j=2;j<=n;j++)
			{
				l=i;
				while(ans[l][j-1]==k)
				{
					l--;
				}
				for(r=1;r<=l;r++)
				{
					ans[r][j]=ans[r][j-1];
				}
				ans[l][j]++;
			}
			for(i=1;i<=d;i++)
			{
				for(j=1;j<=n;j++)
				{
					printf("%d ",ans[i][j]);
				}
				printf("\n");
			}
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}