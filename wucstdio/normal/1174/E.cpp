#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,k;
ll f[21],g[21],f2[21],g2[21];
int main()
{
	scanf("%d",&n);
	k=0;
	while((1<<k)<=n)k++;
	k--;
	f2[k]=g2[k-1]=1;
	if((1<<(k-1))*3>n)g2[k-1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			f2[j]%=MOD;
			g2[j]%=MOD;
			f[j]+=f2[j]*(n/(1<<j)-(i-1))%MOD;
			if(j)f[j-1]+=f2[j]*(n/(1<<(j-1))-n/(1<<j))%MOD;
			g[j]+=g2[j]*(n/((1<<j)*3)-(i-1))%MOD;
			if(j)g[j-1]+=g2[j]*(n/((1<<(j-1))*3)-n/((1<<j)*3))%MOD;
			f[j]+=g2[j]*(n/(1<<j)-n/((1<<j)*3))%MOD;
		}
		for(int j=0;j<=k;j++)f2[j]=f[j],g2[j]=g[j],f[j]=g[j]=0;
	}
	printf("%I64d\n",f2[0]%MOD);
	return 0;
}