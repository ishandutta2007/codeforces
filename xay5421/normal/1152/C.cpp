#include<cstdio>
#include<algorithm> 
#define int long long
int a,b,c,val=0x3f3f3f3f3f3f3f3fll,ans=0x3f3f3f3f3f3f3f3fll;
signed main(){
	scanf("%lld%lld",&a,&b);
	if(a==b){return puts("0"),0;}
	if(b<a)a^=b^=a^=b;c=b-a;
	for(int i=1;1ll*i*i<=c;++i)if(c%i==0){
		int d=i,k=(a+d-1)/d*d-a;
		if(1ll*(a+k)/d*(b+k)<val)val=1ll*(a+k)/d*(b+k),ans=k;
		d=c/i,k=(a+d-1)/d*d-a;
		if(1ll*(a+k)/d*(b+k)<val)val=1ll*(a+k)/d*(b+k),ans=k;
	}
	printf("%I64d\n",ans);
	return 0;
}
//(a+k)*(b+k)/gcd(a+k,b-a)