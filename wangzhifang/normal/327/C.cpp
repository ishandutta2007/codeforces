#include <cstdio>
#include <cstring>
#define mod 1000000007
#define max_l 100000
using namespace std;
char a[max_l+1];
long long quickpow(long long a,long long k) {
	long long ret=1;
	for(; k; a=a*a%mod,k>>=1)
		(k&1)&&(ret=ret*a%mod);
	return ret;
}
int main() {
	int k,l;
	long long tot=0;
	scanf("%s%d",a,&k);
	l=strlen(a);
	for(int i=-1; ++i<l; (a[i]=='0'||a[i]=='5')&&(tot+=quickpow(2,i)));
	long long tmp=quickpow(2,l);
	printf("%I64d\n",tot%mod*(1-quickpow(tmp,k)+mod)%mod*quickpow((1-tmp+mod),mod-2)%mod);
	return 0;
}