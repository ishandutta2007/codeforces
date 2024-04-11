#include <stdio.h>
const int mod=1e9+7;
int pow(int x, long long k)
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
	long long n;
	scanf("%lld\n",&n);
	if(n==0) printf("1\n");
	else printf("%i\n",1ll*pow(2,n-1)*(pow(2,n)+1)%mod);
	return 0;
}