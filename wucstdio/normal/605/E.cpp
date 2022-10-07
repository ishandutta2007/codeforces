#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
double p[1005][1005],f[1005],prod[1005],sum[1005];
bool flag[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		scanf("%lf",&p[i][j]);
		p[i][j]/=100;
	}
	for(int i=0;i<=n;i++)f[i]=1e18,prod[i]=1;
	f[n]=0;
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=1;j<=n;j++)
		{
			if(flag[j])continue;
			if(f[j]<f[now])now=j;
		}
		flag[now]=1;
		for(int j=1;j<=n;j++)
		{
			if(flag[j])continue;
			sum[j]+=prod[j]*p[j][now]*f[now];
			prod[j]*=1-p[j][now];
			f[j]=(sum[j]+1)/(1-prod[j]);
		}
	}
	printf("%.12lf\n",f[1]);
	return 0;
}