#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const int oo=100000000;
int pt[120];
int dp[2][5000],fl,te,n,m;
void PT(int x)
{
	printf("Pt : %d ",dp[fl][x]);
	for(int i=0;i<m;i++)printf("%d ",x/pt[i]%3);puts("");
}
int i,j,k,le,up,st,ts,ans;
int main()
{
	pt[0]=1;
	for(i=1;i<=10;i++)pt[i]=pt[i-1]*3;
	while(~scanf("%d%d",&n,&m))
	{
		if(n<m)swap(n,m);
		fl=0;
		for(i=0;i<pt[m];i++)dp[fl][i]=oo;
		k=0;
		for(i=0;i<m;i++)k+=pt[i];
		dp[fl][k]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				te=fl^1;
				for(k=0;k<pt[m];k++)
				{
					dp[te][k]=oo;
				}
				for(k=0;k<pt[m];k++)
				{
					if(dp[fl][k]==oo)continue;
			//		printf("%d %d %d ",i,j,k);PT(k);
					int tt=dp[fl][k];
					if(j!=0)le=k/pt[j-1]%3;
					else le=1;
					up=k/pt[j]%3;
			//		printf("%d %d\n",le,up);
					st=k-up*pt[j];
					if(up==0)
					{
						ts=st+2*pt[j];
						if(j!=0&&le==0)ts+=pt[j-1];
						dp[te][ts]=min(dp[te][ts],tt+1);
					}
					else
					{
						ts=st+2*pt[j];
						if(j!=0&&le==0)ts+=pt[j-1];
						dp[te][ts]=min(dp[te][ts],tt+1);
						if(le==2||up==2)ts=st+pt[j];
						else ts=st;
						dp[te][ts]=min(dp[te][ts],tt);
					}
				}
				fl=te;
			}
		}
		ans=oo;
		for(i=1;i<pt[m];i++)
		{
			bool can=true;
			for(j=0;j<m;j++)
			{
				if(i/pt[j]%3==0)
				{can=false;break;}
			}
			if(can)
			{
				ans=min(ans,dp[fl][i]);
		//		PT(i);
			}
		}
		printf("%d\n",n*m-ans);
	}
}


/**
0 need
1 be cover
2 have 
**/