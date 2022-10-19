#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
bool vis[N];
vector<int>dp[5][N];
int k,l,a[6][6];
int dfs(int now)
{
	int i,j,x=0,sum=0;
	for(i=0;i<now;i++)
		x=x*10+a[now][i];
	if(i==l-1)
		return dp[1][x].size();
	for(i=0;i<dp[l-now][x].size();i++)
	{
		int tem=dp[l-now][x][i];
		for(j=l-1;j>=now;j--)
		{
			a[j][now]=a[now][j]=tem%10;
			tem/=10;
		}
		sum+=dfs(now+1);
	}
	return sum;
}
int main()
{
	int i,j,n;
	int m=sqrt(100000.5);
	for(i=2;i<=m;i++)
		if(!vis[i])
			for(j=i*i;j<=100000;j+=i)
				vis[j]=1;
	for(i=2;i<100000;i++)
	{
		if(!vis[i])
		{
			int tem=i;
			tem/=10;
			for(j=1;j<=4;j++)
			{
				dp[j][tem].push_back(i);
				tem/=10;
			}
		}
	}
	scanf("%d",&n);
	char str[7];
	for(j=1;j<=n;j++)
	{
		scanf("%s",str);
		l=strlen(str);
		for(i=0;str[i]!='\0';i++)
			a[0][i]=a[i][0]=str[i]-'0';
		printf("%d\n",dfs(1));
	}
	return 0; 
}