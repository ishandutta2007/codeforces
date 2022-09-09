#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int mod=1e9+7;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
const int N=1000050;
int I[N],F[N],a[N];
int main()
{
	int i;
	F[0]=1;
	for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	for(i=1;i<N;i++) I[i]=pow(i,mod-2);
	int n,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	int sol=0;
	for(i=1;i<=n;i=j)
	{
		for(j=i+1;j<=n;j++) if(a[j]!=a[i]) break;
		if(j<=n)
		{
			sol+=(ll)(j-i)*a[i]%mod*I[n-i+1]%mod;
			sol%=mod;
		}
	}
	sol=(ll)sol*F[n]%mod;
	printf("%i\n",sol);
	return 0;
}