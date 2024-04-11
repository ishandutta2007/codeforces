#include<stdio.h>
int main(){
	long long int n,i=1;
	scanf("%lld",&n);
	long long int x=1,y=2,z=3;
	if(n>2){
		while(z<=n){
			x=y;
			y=z;
			z=x+y;
			i++;
		}
	}
	if (n==2)
	{
		printf("1");
		return 0;
	}
	else {
		printf("%lld\n", i);
	}
	return 0;
}