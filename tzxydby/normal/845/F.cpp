#include<bits/stdc++.h>
using namespace std;
const int N=255,mod=1e9+7;
char mp[N][N],a[N][N];
int dp[2][2][2][1<<16][2];
inline void add(int &a,int b){a=a+b;if(a>=mod)a-=mod;}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			a[i][j]=mp[i][j];
	if(n<m)
	{
		swap(n,m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j]=mp[j][i];
	}
	dp[0][0][0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		int pi=i&1;
		for(int j=0;j<m;j++)
		{
			int pj=j&1;
			for(int k=0;k<=1;k++)
				for(int mask=0;mask<(1<<m);mask++)
					for(int can=0;can<=1;can++)
						dp[pi][pj^1][k][mask][can]=0;
			for(int k=0;k<=1;k++)
			{
				for(int mask=0;mask<(1<<m);mask++)
				{
					for(int can=0;can<=1;can++)
					{
						if(a[i][j]=='x')
						{
							add(dp[pi][pj^1][0][(mask|(1<<j))^(1<<j)][can],dp[pi][pj][k][mask][can]);
						}
						else
						{
							add(dp[pi][pj^1][1][mask|(1<<j)][can],dp[pi][pj][k][mask][can]);
							if((mask&(1<<j))||k==1)
								add(dp[pi][pj^1][k][mask][can],dp[pi][pj][k][mask][can]);
							else if(can==0)
								add(dp[pi][pj^1][k][mask][1],dp[pi][pj][k][mask][0]);
						}
					}
				}
			} 
		}
		for(int j=0;j<=1;j++)	
			for(int k=0;k<=1;k++)
				for(int mask=0;mask<(1<<m);mask++)
					for(int can=0;can<=1;can++)
						dp[pi^1][j][k][mask][can]=0;
		for(int k=0;k<=1;k++)
			for(int mask=0;mask<(1<<m);mask++)
				for(int can=0;can<=1;can++)
					add(dp[pi^1][0][0][mask][can],dp[pi][m&1][k][mask][can]);
	}
	int ans=0;
	for(int k=0;k<=1;k++)
		for(int mask=0;mask<(1<<m);mask++)
			for(int can=0;can<=1;can++)
				add(ans,dp[(n+1)&1][m&1][k][mask][can]);
	printf("%d\n",ans);
	return 0;
}