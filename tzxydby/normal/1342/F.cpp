#include<bits/stdc++.h>
using namespace std;
const int N=16,inf=1000000000;
struct nd{int i,j,s;}p[N][N][1<<N];
int n,a[N],dp[N][N][1<<N],w[1<<N],id[N];
vector<int>ans;
void chmin(int &a,int b){if(a>b)a=b;}
void sol()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),id[i]=i+1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int s=0;s<(1<<n);s++)
				dp[i][j][s]=inf;
	for(int s=0;s<(1<<n);s++)
	{
		w[s]=0;
		for(int i=0;i<n;i++)
			if(s>>i&1)
				w[s]+=a[i];
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int s=0;s<(1<<n);s++)
			{
				if(dp[i][j][s]==inf)
					continue;
				nd u={i,j,s};
				int b=(s^((1<<n)-1));
				for(int t=b;t;t=(t-1)&b)
				{
					if(w[t]>dp[i][j][s]&&(t>>j))
					{
						int nj=j+1+__builtin_ctz(t>>j),ns=s|t;
						if(dp[i+1][nj][ns]>w[t])
						{
							dp[i+1][nj][ns]=w[t];
							p[i+1][nj][ns]=u;
						}
					}
				}
			}
		}
	}
	int ai=-1,aj=-1,as=-1;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[i][j][(1<<n)-1]!=inf)
			{
				ai=i;
				aj=j;
				as=(1<<n)-1;
				break;
			}
		}
		if(ai!=-1)
			break;
	}
	printf("%d\n",n-ai);
	while(ai)
	{
		nd x=p[ai][aj][as];
		int s=x.s^as;
		for(int i=0;i<n;i++)
		{
			if((s>>i&1)&&i!=aj-1)
			{
				printf("%d %d\n",id[i],id[aj-1]);
				for(int j=i+1;j<n;j++)
					id[j]--;
			}
		}
		ai=x.i,aj=x.j,as=x.s;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}