#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[1005][1005];
int dp[65536][17];
int fy[17][17],tmax[17][17];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int k,h,w;
int ans[1005],cnt;
void findzy(int x,int y)
{
	ans[++cnt]=y;
	if(x==(1<<(y-1)))return;
	for(int i=1;i<=k;i++)
	{
		if((x&(1<<(i-1)))==0||i==y)continue;
		if(dp[x^(1<<(y-1))][i]+fy[i][y]==dp[x][y])
		{
			findzy(x^(1<<(y-1)),i);
		}
	}
}
int pl[1005];
signed main()
{
	//freopen("sample.in","r",stdin);
	int q;
	q=read();
	for(int sth=1;sth<=q;sth++)
	{
		h=read();
		w=read();
		k=read();
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				a[i][j]=read();
			}
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(i==j)continue;
				fy[i][j]=0;
				tmax[i][j]=0;
				for(int sth=1;sth<=w-2;sth++)
				{
					int now1=a[i*h/k][sth]+a[i*h/k][sth+1]+a[i*h/k][sth+2];
					int now2=a[(j-1)*h/k+1][sth]+a[(j-1)*h/k+1][sth+1]+a[(j-1)*h/k+1][sth+2];
				//	printf("%lld %lld\n",now1,now2);
					fy[i][j]=fy[i][j]+jdz((now1-now2)*(now1-now2)*(now1-now2)); 
					//tmax[i][j]=max(tmax[i][j],jdz(a[i*h/k][sth]-a[(j-1)*h/k+1][sth]));
				}
				//fy[i][j]+=150*tmax[i][j];
				//printf("%lld %lld %lld\n",i,j,fy[i][j]);
			}
		}
		for(int i=0;i<(1<<k);i++)for(int j=1;j<=k;j++)dp[i][j]=1121131433448687LL;
		for(int i=1;i<=k;i++)dp[(1<<(i-1))][i]=0;
		for(int i=1;i<(1<<k);i++)
		{
			for(int sth=1;sth<=k;sth++)
			{
				if((i&(1<<(sth-1)))==0)continue;
				for(int j=1;j<=k;j++)
				{
					if(i&(1<<(j-1)))continue;
					dp[i|(1<<(j-1))][j]=min(dp[i|(1<<(j-1))][j],dp[i][sth]+fy[sth][j]);
				}
			}
		}
		int minn=1121131433448687LL,mpos=0;
		for(int i=1;i<=k;i++)
		{
			if(dp[(1<<k)-1][i]<minn)
			{
				minn=dp[(1<<k)-1][i];
				mpos=i;
			}
		}
		cnt=0;
		findzy((1<<k)-1,mpos);
		for(int i=cnt;i>=1;i--)pl[ans[i]]=cnt+1-i;
		for(int i=1;i<=cnt;i++)printf("%lld ",pl[i]); 
		printf("\n");
	//	if(sth==3)return 0;
	}
	return 0;
}