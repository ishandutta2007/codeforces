#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int oo=1000000001;
int dp[1200][1200],out[1200][5],pre[1200][1200],a[1200];
int i,j,last,n,mi;
int main()
{
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		if(n==1){printf("%d\n%d\n",a[0],1);continue;}
		if(n==2){printf("%d\n%d %d\n",max(a[0],a[1]),1,2);continue;}
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		dp[i][j]=oo;
		dp[1][0]=max(a[1],a[2]);
		dp[1][1]=max(a[0],a[2]);
		dp[1][2]=max(a[0],a[1]);
		for(i=1;2*i+2<n;i++)
		{
			for(j=0;j<=2*i;j++)
			{
			//	printf("%d %d %d\n",i,j,dp[i][j]);
				if(dp[i+1][j]-max(a[2*i+2],a[2*i+1])>dp[i][j])
				{
					dp[i+1][j]=dp[i][j]+max(a[2*i+2],a[2*i+1]);
					pre[i+1][j]=j;
				}
				if(dp[i+1][2*i+2]-max(a[j],a[2*i+1])>dp[i][j])
				{
					dp[i+1][2*i+2]=dp[i][j]+max(a[j],a[2*i+1]);
					pre[i+1][2*i+2]=j;
				}
				if(dp[i+1][2*i+1]-max(a[j],a[2*i+2])>dp[i][j])
				{
					dp[i+1][2*i+1]=dp[i][j]+max(a[j],a[2*i+2]);
					pre[i+1][2*i+1]=j;
				}
			}
		}
		if(n%2==1)
		{
			mi=oo;
			for(i=0;i<n;i++)
			{
				if(mi>dp[n/2][i]+a[i])
				{
					mi=dp[n/2][i]+a[i];
					last=i;
				}
			}
			printf("%d\n",mi);
			out[n/2][0]=last;
			for(i=n/2;i>0;i--)
			{
				int te=pre[i][last];
			//	printf("%d %d %d\n",i,last,te);
				if(last==2*i-1)
				{
					out[i-1][0]=te;
					out[i-1][1]=2*i;
					last=te;
				}
				else if(last==2*i)
				{
					out[i-1][0]=te;
					out[i-1][1]=2*i-1;
					last=te;
				}
				else
				{
					out[i-1][0]=2*i-1;
					out[i-1][1]=2*i;
					last=te;					
				}
			}
			for(i=0;i<n/2;i++)
			printf("%d %d\n",out[i][0]+1,out[i][1]+1);
			printf("%d\n",out[n/2][0]+1);
		}
		else
		{
			mi=oo;
			for(i=0;i<n;i++)
			{
				if(mi>dp[n/2-1][i]+max(a[i],a[n-1]))
				{
					mi=dp[n/2-1][i]+max(a[i],a[n-1]);
					last=i;
				}
			}
			printf("%d\n",mi);
			out[n/2-1][0]=last;out[n/2-1][1]=n-1;
			for(i=n/2-1;i>0;i--)
			{
				int te=pre[i][last];
			//	printf("%d %d %d\n",i,last,te);
				if(last==2*i-1)
				{
					out[i-1][0]=te;
					out[i-1][1]=2*i;
					last=te;
				}
				else if(last==2*i)
				{
					out[i-1][0]=te;
					out[i-1][1]=2*i-1;
					last=te;
				}
				else
				{
					out[i-1][0]=2*i-1;
					out[i-1][1]=2*i;
					last=te;					
				}
			}
			for(i=0;i<n/2;i++)
			printf("%d %d\n",out[i][0]+1,out[i][1]+1);
		}
	}
}