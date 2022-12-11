#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n;
int a[maxn];
bool dp[maxn][6];
int pre[maxn][6];
void print(int t,int x)
{
	if(!t)return;
	print(t-1,pre[t][x]);
	printf("%d ",x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int j=1;j<=5;++j)dp[1][j]=1,pre[1][j]=0;
	for(int i=2;i<=n;++i)
	{
		if(a[i-1]<a[i])
		{
			for(int j=1;j<=5;++j)
			{
				for(int k=1;k<j;++k)if(dp[i-1][k])dp[i][j]=1,pre[i][j]=k;
			}
		}
		else if(a[i-1]>a[i])
		{
			for(int j=1;j<=5;++j)
			{
				for(int k=j+1;k<=5;++k)if(dp[i-1][k])dp[i][j]=1,pre[i][j]=k;
			}
		}
		else
		{
			for(int j=1;j<=5;++j)
			{
				for(int k=1;k<=5;++k)if(k!=j)
				{
					if(dp[i-1][k])dp[i][j]=1,pre[i][j]=k;
				}
			}
		}
	}
	bool yes=0;
	for(int j=1;j<=5;++j)if(dp[n][j])yes=1;
	if(!yes)
	{
		puts("-1");
		return 0;
	}
	for(int j=1;j<=5;++j)if(dp[n][j])
	{
		print(n,j);
		break;
	}
	return 0;
}