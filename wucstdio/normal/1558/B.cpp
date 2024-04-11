#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll f[4000005],s[4000005],MOD;
int main()
{
	scanf("%d%lld",&n,&MOD);
	s[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i+1]=(f[i+1]+f[i])%MOD;
		f[i]=(f[i]+s[i-1])%MOD;
		s[0]=0;
		for(int k=2;i*k<=n;k++)
		{
			f[i*k]+=f[i];
			if(f[i*k]>=MOD)f[i*k]-=MOD;
			if(i*k+k<=n)
			{
				f[i*k+k]-=f[i];
				if(f[i*k+k]<0)f[i*k+k]+=MOD;
			}
		}
		s[i]=(s[i-1]+f[i])%MOD;
	}
	printf("%lld\n",(f[n]%MOD+MOD)%MOD);
	return 0;
}