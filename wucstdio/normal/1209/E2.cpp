#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,a[15][15],b[15][2005],sa[2005];
int f[15][1<<12],sum[15][15][1<<12],maxx[15][1<<12];
bool cmp(int x,int y)
{
	int max1=0,max2=0;
	for(int i=1;i<=n;i++)max1=max(max1,b[i][x]);
	for(int i=1;i<=n;i++)max2=max(max2,b[i][y]);
	return max1>max2;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(b,0,sizeof(b));
		memset(sa,0,sizeof(sa));
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(maxx,0,sizeof(maxx));
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
		for(int i=1;i<=m;i++)sa[i]=i;
		sort(sa+1,sa+m+1,cmp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[j][sa[i]];
//				printf("%d ",a[i][j]);
			}
//			printf("\n");
		}
		for(int i=0;i<15;i++)
		  for(int j=0;j<(1<<12);j++)
		    f[i][j]=-10000000;
		f[0][0]=0;
		for(int i=1;i<=n;i++)
		for(int s=0;s<(1<<n);s++)
		for(int st=1;st<=n;st++)
		{
		      for(int j=1;j<=n;j++)
		        if((1<<(j-1))&s)
		          sum[i][st][s]+=a[i][(st+j-2)%n+1];
			maxx[i][s]=max(maxx[i][s],sum[i][st][s]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int s=0;s<(1<<n);s++)
			{
//				printf("%d,",f[i-1][s]);
				if(f[i-1][s]<0)continue;
				f[i][s]=max(f[i][s],f[i-1][s]);
				int t=((1<<n)-1)^s;
				for(int ss=t;ss;ss=(ss-1)&t)f[i][ss|s]=max(f[i][ss|s],f[i-1][s]+maxx[i][ss]);
			}
//			printf("\n");
		}
		printf("%d\n",f[n][(1<<n)-1]);
	}
	return 0;
}