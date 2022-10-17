#include<stdio.h>
long long T,n;
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<6)
			puts("15");
		else{
			int k=n%2;
			printf("%lld\n",n/2*5ll+k*5ll);
		}
	}
	return 0;
}