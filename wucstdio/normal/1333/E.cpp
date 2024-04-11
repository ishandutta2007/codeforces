#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int ans1[3][3]={{1,3,6},{9,2,7},{5,4,8}};
const int ans2[4][4]={{4,3,2,1},{7,8,10,13},{6,16,9,14},{5,12,11,15}};
int ans[505][505];
int main()
{
	int n;
	scanf("%d",&n);
	if(n<=2)
	{
		printf("-1\n");
		return 0;
	}
	if(n&1)
	{
		int cnt=0;
		for(int i=1;i<=n-3;i++)
		{
			if(i&1)for(int j=1;j<=n;j++)ans[i][j]=++cnt;
			else for(int j=n;j>=1;j--)ans[i][j]=++cnt;
		}
		for(int i=1;i<=n-3;i++)
		{
			if(i&1)for(int j=n-2;j<=n;j++)ans[j][i]=++cnt;
			else for(int j=n;j>=n-2;j--)ans[j][i]=++cnt;
		}
		for(int i=n-2;i<=n;i++)
		  for(int j=n-2;j<=n;j++)
		    ans[i][j]=ans1[i-(n-2)][j-(n-2)]+cnt;
	}
	else
	{
		int cnt=0;
		for(int i=1;i<=n-4;i++)
		{
			if(i&1)for(int j=1;j<=n;j++)ans[i][j]=++cnt;
			else for(int j=n;j>=1;j--)ans[i][j]=++cnt;
		}
		for(int i=1;i<=n-4;i++)
		{
			if(i&1)for(int j=n-3;j<=n;j++)ans[j][i]=++cnt;
			else for(int j=n;j>=n-3;j--)ans[j][i]=++cnt;
		}
		for(int i=n-3;i<=n;i++)
		  for(int j=n-3;j<=n;j++)
		    ans[i][j]=ans2[i-(n-3)][j-(n-3)]+cnt;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		  printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}