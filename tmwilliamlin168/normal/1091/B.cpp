#include "cstdio"
int a,b;
long long n,sum1,sum2;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n*2;i++){
		scanf("%d%d",&a,&b);
		sum1+=a;
		sum2+=b;
	}
	printf("%lld %lld\n",sum1/n,sum2/n);
	return 0;
}