#include <cstdio>
int n,a,d;
unsigned long long m=368131125,mod=1e9,x=1.2e10;
int main(){
	scanf("%d%d%d",&n,&a,&d);
	printf("%llu %llu\n",m*a%mod*x+1,m*d%mod*x);
	return 0;
}