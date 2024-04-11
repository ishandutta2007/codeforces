#include <cstdio>
using namespace std;
#define mod 1000000007
int c[1<<20],pw[1<<20],bit[1<<20];
__inline__ __attribute__((always_inline)) void fwt(const int&l){
	for(int i=1; i<l; i<<=1)
		for(int j=0; j<l; j+=i<<1)
			for(int k=j; k<j+i; ++k)
				c[k]+=c[k+i];
}
int main(){
	int n,ans;
	scanf("%d",&n);
	for(int i=n,x; i; --i,++c[x])
		scanf("%d",&x);
	fwt(1048576);
	for(int i=bit[0]=pw[0]=1; i<1048576; ++i)
		bit[i]=(__builtin_parity(i)?-1:1),pw[i]=pw[i-1]*2%mod;
	for(int i=0; i<1048576; ++i)
		ans=(ans+pw[c[i]]*bit[i])%mod;
	printf("%d",(ans+mod)%mod);
	return 0;
}