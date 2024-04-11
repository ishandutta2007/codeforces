#include <stdio.h>


int main() {
	int n,count=0;
	long long int k;
	scanf("%d %lld",&n,&k);
	while(k%2==0){
		k=  k/2;
		count ++;
	}
	printf("%d\n",(1+count) );

	
	return 0;
}