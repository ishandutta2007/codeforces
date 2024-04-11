#include <stdio.h>
const int mod=1e9+7,N=1e6+10;
int po[N*2],a[N*2],f[N*2],sol;
int main()
{
	int n,i,j,x;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&x),a[x]++;
	po[0]=1;
	for(i=1;i<=n;i++) po[i]=(po[i-1]*2)%mod;
	for(i=N-1;i>1;i--)
	{
		x=0;
		for(j=i;j<N;j+=i) x+=a[j];
		if(x)
		{
			f[i]=(1ll*x*po[x-1])%mod;
			for(j=i+i;j<N;j+=i) f[i]=(f[i]-f[j]+mod)%mod;
			sol=(1ll*f[i]*i+sol)%mod;
		}
	}
	printf("%i\n",sol);
	return 0;
}