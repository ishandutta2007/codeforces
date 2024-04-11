#include<bits/stdc++.h>
using namespace std;
int n,m;
bool dp[505][1050];
int pre[505][1050];
int a[505][505];
void print(int x,int s)
{
	if(!x)return;
	int k=pre[x][s];
	print(x-1,s^a[x][k]);
	printf("%d ",k);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
	}
	dp[0][0]=1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=1023;++j)if(dp[i][j])
		{
			for(int k=1;k<=m;++k)
			{
				dp[i+1][j^a[i+1][k]]=1;
				pre[i+1][j^a[i+1][k]]=k;
			}
		}
	}
	bool yes=0;
	for(int j=1;j<=1023;++j)if(dp[n][j])yes=1;
	if(!yes)
	{
		puts("NIE");
		return 0;
	}
	puts("TAK");
	int id=0;
	for(int j=1;j<=1023;++j)if(dp[n][j])id=j;
	print(n,id);
}