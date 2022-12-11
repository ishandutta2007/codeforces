#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+5;
const int max_p=1e3+5;
const int max_k=50+5;
bool a[max_n],b[max_n];
int dp[2][max_p][max_k][max_k];
inline void check_max(int &x,int y)
{
	x=max(x,y);
}
int main()
{
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	int r;
	scanf("%d",&r);
	for(int i=1;i<=r;++i)
	{
		int x;
		scanf("%d",&x);
		a[x]=true;
	}
	int s;
	scanf("%d",&s);
	for(int i=1;i<=s;++i)
	{
		int x;
		scanf("%d",&x);
		b[x]=true;
	}
	if(p>=2*((n+k-1)/k))
	{
		int ans=0;
		for(int i=1;i<=n;++i)
			ans+=a[i]|b[i];
		printf("%d\n",ans);
		return 0;
	}
	for(int j=0;j<=p;++j)
		for(int l=0;l<k;++l)
			for(int r=0;r<k;++r)
				dp[0][j][l][r]=-1e9;// -inf 
	dp[0][p][0][0]=0;
	for(int i=1;i<=n;++i)
	{
		int y=i&1,x=y^1;// x  y  
		for(int j=0;j<=p;++j)
			for(int l=0;l<k;++l)
				for(int r=0;r<k;++r)
					dp[y][j][l][r]=-1e9;// -inf 
		for(int j=0;j<=p;++j)
			for(int l=0;l<k;++l)
				for(int r=0;r<k;++r)
				{
					if(dp[x][j][l][r]>=0)
					{
						check_max(dp[y][j][max(l-1,0)][max(r-1,0)],dp[x][j][l][r]+((l>0&&a[i])||(r>0&&b[i])));
						if(j>0)
						{
							if(a[i])
								check_max(dp[y][j-1][k-1][max(r-1,0)],dp[x][j][l][r]+1);
							if(b[i])
								check_max(dp[y][j-1][max(l-1,0)][k-1],dp[x][j][l][r]+1);
						}
					}
				}
	}
	int x=n&1,ans=0;
	for(int j=0;j<=p;++j)
		for(int l=0;l<k;++l)
			for(int r=0;r<k;++r)
				ans=max(ans,dp[x][j][l][r]);
	printf("%d\n",ans);
	return 0;
}
/*
10 5 4
3 1 5 9
3 2 6 10
*/