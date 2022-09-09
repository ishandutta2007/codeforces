#include <stdio.h>
const int N=1050;
const int L=11;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int sum[N][N],dp[N][N];
short rmq[N][N][L][L],logs[N];
int Get(int x1, int x2, int y1, int y2)
{
	int k=logs[x2-x1+1];
	int l=logs[y2-y1+1];
	return max(max(rmq[x1][y1][k][l],rmq[x2-(1<<k)+1][y1][k][l]),max(rmq[x1][y2-(1<<l)+1][k][l],rmq[x2-(1<<k)+1][y2-(1<<l)+1][k][l]));
}
int main()
{
	int n,m,t,i,j,k,l,x1,y1,x2,y2;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&sum[i][j]),sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		int top=min(n-i+1,m-j+1),bot=0,mid;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(sum[i+mid-1][j+mid-1]-sum[i+mid-1][j-1]-sum[i-1][j+mid-1]+sum[i-1][j-1]==mid*mid) dp[i][j]=mid,bot=mid+1;
			else top=mid-1;
		}
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) rmq[i][j][0][0]=dp[i][j];
	for(k=0;k<L;k++)
	{
		for(l=0;l<L;l++)
		{
			if(!k && !l) continue;
			for(i=1;i<=n-(1<<k)+1;i++) for(j=1;j<=m-(1<<l)+1;j++)
			{
				if(k==0) rmq[i][j][k][l]=max(rmq[i][j][k][l-1],rmq[i][j+(1<<l-1)][k][l-1]);
				else rmq[i][j][k][l]=max(rmq[i][j][k-1][l],rmq[i+(1<<k-1)][j][k-1][l]);
			}
		}
	}
	for(i=2;i<=max(n,m);i++) logs[i]=logs[i>>1]+1;
	scanf("%i",&t);
	while(t--)
	{
		//printf("%i\n",t);
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		int h=x2-x1+1,w=y2-y1+1;
		int top=min(h,w),bot=1,mid,ans=0;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(x1,x2-mid+1,y1,y2-mid+1)>=mid) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		printf("%i\n",ans);
	}
	return 0;
}