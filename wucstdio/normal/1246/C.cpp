#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m,num1[2005][2005],num2[2005][2005],now1[2005],now2[2005];
char s[2005][2005];
ll f[2005][2005][2],sum[2005][2005][2];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=n;i>=1;i--)
	for(int j=m;j>=1;j--)
	{
		if(s[i][j]=='R')
		{
			num1[i][j]=num1[i][j+1]+1;
			num2[i][j]=num2[i+1][j]+1;
		}
		else
		{
			num1[i][j]=num1[i][j+1];
			num2[i][j]=num2[i+1][j];
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		  printf("%d ",num1[i][j]);
//		printf("\n");
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		  printf("%d ",num2[i][j]);
//		printf("\n");
//	}
	if(n==1&&m==1)
	{
		printf("1\n");
		return 0;
	}
	f[1][1][0]=f[1][1][1]=1;
	sum[1][1][0]=sum[1][1][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i!=1)
		{
			while(num2[now2[j]+1][j]>n-i)now2[j]++;
			if(now2[j]<i)f[i][j][1]+=sum[i-1][j][0]-sum[max(0,now2[j]-1)][j][0];
//			for(int k=1;k<i;k++)
//			{
//				if(num2[k+1][j]<=n-i)
//				  f[i][j][1]+=f[k][j][0];
//			}
		}
		if(j!=1)
		{
			while(num1[i][now1[i]+1]>m-j)now1[i]++;
			if(now1[i]<j)f[i][j][0]+=sum[i][j-1][1]-sum[i][max(0,now1[i]-1)][1];
//			for(int k=1;k<j;k++)
//			{
//				if(num1[i][k+1]<=m-j)
//				  f[i][j][0]+=f[i][k][1];
//			}
		}
		f[i][j][0]%=MOD;
		f[i][j][1]%=MOD;
		sum[i][j][0]=(sum[i-1][j][0]+f[i][j][0])%MOD;
		sum[i][j][1]=(sum[i][j-1][1]+f[i][j][1])%MOD;
//		printf("%lld %lld\n",f[i][j][0],f[i][j][1]);
	}
	printf("%lld\n",(f[n][m][0]+f[n][m][1]+MOD+MOD)%MOD);
	return 0;
}