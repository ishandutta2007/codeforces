#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[205][205],b[205][205],res1[205],res2[205];
bool full(int x)
{
	for(int i=1;i<=m;i++)
	  if(b[x][i]==0)return 0;
	return 1;
}
bool empty(int x)
{
	for(int i=1;i<=m;i++)
	  if(b[x][i])return 0;
	return 1;
}
void solve()
{
	memset(res1,0,sizeof(res1));
	memset(res2,0,sizeof(res2));
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    b[i][j]=a[i][j];
	for(int j=1;j<=m;j++)
	{
		if(b[n][j]==0)
		{
			res2[j]=1;
			for(int i=1;i<=n;i++)
			  b[i][j]^=1;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(full(i));
		else if(empty(i))
		{
			res1[i]=1;
			for(int j=1;j<=m;j++)
			  b[i][j]^=1;
		}
		else
		{
			printf("NO\n");
			return;
		}
	}
	if(b[1][1])
	{
		res1[1]=1;
		for(int j=1;j<=m;j++)
		  b[1][j]^=1;
	}
	for(int i=2;i<=m;i++)
	{
		if(b[1][i]<b[1][i-1])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)printf("%d",res1[i]);
	printf("\n");
	for(int i=1;i<=m;i++)printf("%d",res2[i]);
	printf("\n");
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	if(n==1)
	{
		printf("YES\n");
		printf("0\n");
		for(int i=1;i<=m;i++)
		  printf("%d",a[1][i]);
		printf("\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    b[i][j]=a[i][j];
	memset(res1,0,sizeof(res1));
	memset(res2,0,sizeof(res2));
	for(int i=1;i<=m;i++)
	{
		if(b[1][i])
		{
			res2[i]=1;
			for(int j=1;j<=n;j++)
			  b[j][i]^=1;
		}
	}
	int x=n;
	for(int i=2;i<=n;i++)
	{
		if(full(i))
		{
			res1[i]=1;
			for(int j=1;j<=m;j++)b[i][j]^=1;
		}
		else if(empty(i));
		else
		{
			if(b[i][1]==1)
			{
				res1[i]=1;
				b[i][1]=0;
				for(int j=2;j<=m;j++)b[i][j]^=1;
			}
			for(int j=2;j<=m;j++)
			{
				if(b[i][j]<b[i][j-1])
				{
					x=-1;
					break;
				}
			}
			if(x==-1)break;
			x=i;
			break;
		}
	}
	if(x==-1)
	{
		solve();
		return 0;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(full(i));
		else if(empty(i))
		{
			res1[i]=1;
			for(int j=1;j<=m;j++)b[i][j]^=1;
		}
		else
		{
			x=-1;
			break;
		}
	}
	if(x!=-1)
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%d",res1[i]);
		printf("\n");
		for(int j=1;j<=m;j++)printf("%d",res2[j]);
		printf("\n");
		return 0;
	}
	solve();
	return 0;
}