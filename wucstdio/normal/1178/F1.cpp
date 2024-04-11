#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m,c[505],minp[505][505];
ll f[505][505];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		minp[i][i]=i;
		f[i][i]=f[i][i-1]=1;
		for(int j=i+1;j<=n;j++)
		{
			if(c[minp[i][j-1]]>c[j])minp[i][j]=j;
			else minp[i][j]=minp[i][j-1];
		}
	}
	f[n+1][n]=1;
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			int p=minp[l][r];
			ll num1=0,num2=0;
			for(int i=l;i<=p;i++)num1=(num1+f[l][i-1]*f[i][p-1])%MOD;
			for(int i=p;i<=r;i++)num2=(num2+f[p+1][i]*f[i+1][r])%MOD;
			f[l][r]=num1*num2%MOD;
		}
	}
	printf("%I64d\n",f[1][n]);
	return 0;
}