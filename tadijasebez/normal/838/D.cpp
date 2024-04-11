#include <stdio.h>
const int mod=1e9+7;
int pow(int x, int k)
{
	if(k==0) return 1;
	int ans=1;
	if(k&1) ans=x;
	int y=pow(x,k>>1);
	y=1ll*y*y%mod;
	return 1ll*y*ans%mod;
}
int main()
{
	int n,m;
	scanf("%i%i",&n,&m);
	printf("%i\n",1ll*pow(n+1,m-1)*(n-m+1)%mod*pow(2,m)%mod);
	return 0;
}