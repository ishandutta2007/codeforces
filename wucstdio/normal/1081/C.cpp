#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll n,m,k,f[2005][2005];
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	f[1][0]=m;
	for(int i=2;i<=n;i++)
	  for(int j=0;j<=k;j++)
	    f[i][j]=(f[i-1][j]+(j>0?f[i-1][j-1]*(m-1):0))%MOD;
	printf("%I64d\n",f[n][k]);
	return 0;
}