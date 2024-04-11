#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m;
ll f[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	f[0]=f[1]=1;
	for(int i=2;i<=1000000;i++)f[i]=(f[i-1]+f[i-2])%MOD;
	printf("%lld\n",(f[n]+f[m]+MOD-1)*2%MOD);
	return 0;
}