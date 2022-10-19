#include<bits/stdc++.h>
using namespace std;
int dp[(1<<20)],ar[20][20];
string s[20];
int main()
{
	int n,m,i,x,j;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>ar[i][j];
	memset(dp,17,sizeof(dp));
	dp[0]=0;
	int l;
	for(i=0;i<(1<<n)-1;i++)
	{
		for(x=0;x<n;x++)
		{
			if(!((i>>x)&1)) 
			{
				l=x;
				break;
			}
		}
		for(j=0;j<m;j++)
		{
			int cur=i+(1<<l);
			dp[cur]=min(dp[cur],dp[i]+ar[l][j]);
			int nex=cur,sum=0,maxi=0;
			for(x=0;x<n;x++)
				if(s[l][j]==s[x][j])
					nex|=1<<x,sum+=ar[x][j],maxi=max(maxi,ar[x][j]);
			dp[nex]=min(dp[nex],dp[i]+sum-maxi);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}