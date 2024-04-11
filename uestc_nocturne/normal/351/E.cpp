/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=2010;
const int oo=1000000000;
vector<int> cnt[100100];
int vis[V];
int l[V],r[V];
int dp[V][V],n,a[V];
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=100000;i++)cnt[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<0)a[i]=-a[i];
			cnt[a[i]].push_back(i);
		}
		memset(vis,0,sizeof(vis));
		int ret=0;
		for(int i=100000;i>=0;i--)
		{
			int sz=cnt[i].size();
			if(sz==0)continue;
			for(int j=0;j<sz;j++)
			vis[cnt[i][j]]=1;
			for(int j=0;j<sz;j++)
			{
				l[j]=r[j]=0;
				for(int k=0;k<=cnt[i][j];k++)
				if(vis[k]==0)l[j]++;
				for(int k=cnt[i][j]+1;k<n;k++)
				if(vis[k]==0)r[j]++;
			}
			for(int j=0;j<=sz;j++)
			for(int k=0;k<=j;k++)
			dp[j][k]=oo;
			dp[0][0]=0;
			for(int j=0;j<sz;j++)
			for(int k=0;k<=j;k++)
			{
				dp[j+1][k+1]=min(dp[j+1][k+1],dp[j][k]+r[j]);
				dp[j+1][k]=min(dp[j+1][k],dp[j][k]+l[j]+k);
			}
			int tmp=oo;
			for(int j=0;j<=sz;j++)tmp=min(tmp,dp[sz][j]);
			ret+=tmp;
		}
		cout<<ret<<endl;
	}
	return 0;
}