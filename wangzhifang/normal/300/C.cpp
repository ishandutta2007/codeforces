#include <cstdio>
#include <algorithm>
#define mod 1000000007
#define max_n 1000000
using namespace std;
long long frac[max_n+1],ifrac[max_n+1];
long long quickpow(long long a,long long k,long long p){
	long long ret=1;
	for(; k; a=a*a%p,k>>=1)
		(k&1)&&(ret=ret*a%p);
	return ret;
}
#define inv(x) quickpow(x,mod-2,mod)
int val(int i,int a,int b,int l){
	int ret=0,k=1;
	for(++l; --l; k*=10,i>>=1)
		ret+=k*((i&1)?b:a);
	return ret;
}
int main(){
	int a,b,n;
	long long ans;
	scanf("%d%d%d",&a,&b,&n);
	a>b&&(swap(a,b),0),frac[0]=1,ans=0;
	for(int i=0; ++i<=n; frac[i]=frac[i-1]*i%mod);
	ifrac[n]=inv(frac[n]);
	for(int i=n+1; --i; ifrac[i-1]=ifrac[i]*i%mod);
	for(int i=-1,j,k,l=1,frc1,frc2; (j=val(++i,a,b,l))<=n*b; (i+1==(1<<l))&&(++l,i=-1)){
		frc1=j-n*a;
		if(frc1<0)
			continue;
		frc2=b-a;
		if(frc1%frc2)
			continue;
		k=frc1/frc2;
		ans+=frac[n]*ifrac[k]%mod*ifrac[n-k]%mod;
	}
	printf("%lld\n",ans%mod);
	return 0;
}