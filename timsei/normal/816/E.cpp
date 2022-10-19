%:pragma GCC optimize(4)
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#define N 5001
#define r(x) scanf("%d",&x)
#define F(i,a,b) for(int i=a;i<=b;i++)
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
int S[N],fa[N],dp[N][N][2];
int ne[N*2],to[N*2],fir[N];
int bill;
int C[N];
int dance[N];
int x,y;
bool vis[N];
int cnt;
void add(int x,int y)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;
}
void dfs(int x,int f)
{
	S[x]=1;
	dp[x][1][1]=C[x]-dance[x];
	dp[x][1][0]=C[x];
	dp[x][0][0]=0;
	forw(i,x)
	{
		if(to[i]!=f)
		{
			fa[to[i]]=x;
			dfs(to[i],x);
			for(int j=S[x];j>=0;j--)
			{
				for(int k=S[to[i]];k>=0;k--)
				{
					dp[x][j+k][0]=min(dp[x][j+k][0],dp[to[i]][k][0]+dp[x][j][0]);
					if(j==0) continue;
					dp[x][j+k][1]=min(dp[x][j+k][1],min(dp[to[i]][k][0],dp[to[i]][k][1])+dp[x][j][1]);
				}
			}
			S[x]+=S[to[i]];
		}
	}
	return;
}
int res=0;
int n;
int main()
{
	r(n);r(bill);
	for(int i=1;i<=n;i++)
	{
		r(x);r(y);C[i]=x;dance[i]=y;
		if(i==1) continue;
		r(x);add(i,x);add(x,i);
	}
	memset(dp,63,sizeof(dp));
	dfs(1,-1);
	int ans=0;
	for(int i=n;i>=0;i--)
	{
		if(dp[1][i][1]<=bill||dp[1][i][0]<=bill)
		{
			ans=i;break;
		}
//		else cout<<dp[1][i][1]<<" "<<dp[1][i][0]<<endl;
	}
	cout<<ans;
}