#include<bits/stdc++.h>
using namespace std;
int n,m,p;
const int max_n=2e4+5;
const int max_m=2e4+5;
int x[max_n],y[max_m];
inline int f(int a,int b)
{
	int res=x[a]+y[b];
	return res-(res>=p?p:0);
}
const int max_r=4e4+5;
int ans_x[max_r],ans_y[max_r],dp[2][max_m],f1[2][max_m],f2[2][max_m];
const int inf=2e9;
void solve(int sx,int sy,int fx,int fy)
{
//	fprintf(stderr,"solve: sx=%d sy=%d fx=%d fy=%d\n",sx,sy,fx,fy);
	int l=sx+sy,r=fx+fy;
	if(l==r)
	{
		assert(sx==fx&&sy==fy);
//		fprintf(stderr,"solve: sx=%d sy=%d fx=%d fy=%d -> points: %d\n",sx,sy,fx,fy,f(sx,sy));
		ans_x[l]=sx,ans_y[l]=sy;
		return;
	}
	int mid=(l+r)>>1,x=0,y=1;
	for(int i=sy;i<=fy;++i)
		dp[y][i]=-inf;
	dp[y][sy]=f(sx,sy);
	f1[y][sy]=l==mid?sy:0;
	f2[y][sy]=l==mid+1?sy:0;
	for(int i=l+1;i<=r;++i)
	{
		swap(x,y);
		for(int j=sy;j<=fy;++j)
			dp[y][j]=-inf;
		for(int j=sy;j<=fy;++j)
		{
			int v=dp[x][j];
			if(v!=-inf)
			{
				if(i-j<=fx)
				{
					int v1=f(i-j,j);
					if(dp[y][j]<v+v1)
					{
						dp[y][j]=v+v1;
						f1[y][j]=i==mid?j:f1[x][j];
						f2[y][j]=i==mid+1?j:f2[x][j];
					}
				}
				if(j+1<=fy)
				{
					int v2=f(i-1-j,j+1);
					if(dp[y][j+1]<v+v2)
					{
						dp[y][j+1]=v+v2;
						f1[y][j+1]=i==mid?j+1:f1[x][j];
						f2[y][j+1]=i==mid+1?j+1:f2[x][j];
					}
				}
			}
		}
	}
//	fprintf(stderr,"solve: sx=%d sy=%d fx=%d fy=%d -> points: %d\n",sx,sy,fx,fy,dp[y][fy]);
//	fprintf(stderr,"sub1: sx=%d sy=%d fx=%d fy=%d\n",sx,sy,mid-f1[y][fy],f1[y][fy]);
//	fprintf(stderr,"sub2: sx=%d sy=%d fx=%d fy=%d\n",mid+1-f2[y][fy],f2[y][fy],fx,fy);
	int F1=f1[y][fy],F2=f2[y][fy];
	solve(sx,sy,mid-F1,F1);
	solve(mid+1-F2,F2,fx,fy);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<=n-1;++i)
	{
		scanf("%d",x+i);
		x[i]%=p;
	}
	for(int i=0;i<=m-1;++i)
	{
		scanf("%d",y+i);
		y[i]%=p;
	}
	solve(0,0,n-1,m-1);
	int ans=0;
	assert(ans_x[0]==0&&ans_y[0]==0);
	assert(ans_x[n+m-2]==n-1&&ans_y[n+m-2]==m-1);
	for(int i=0;i<=n+m-2;++i)
	{
		assert(ans_x[i]+ans_y[i]==i);
		assert(i==0||ans_x[i]==ans_x[i-1]||ans_y[i]==ans_y[i-1]);
		ans+=f(ans_x[i],ans_y[i]);
//		fprintf(stderr,"i=%d x=%d y=%d\n",i,ans_x[i],ans_y[i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n+m-2;++i)
	{
		if(ans_x[i]>ans_x[i-1])
			putchar('C');
		else
			putchar('S');
	}
	putchar('\n');
	return 0;
}