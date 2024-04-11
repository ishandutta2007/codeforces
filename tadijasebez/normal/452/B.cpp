#include <stdio.h>
#include <cmath>
int max(int a, int b)
{
	if(a>b) return a;
	return b;
}
int min(int a, int b)
{
	if(a>b) return b;
	return a;
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	int b=max(n,m),a=min(n,m);
	if(a==0){
		if(m>=n) printf("0 1\n0 %d\n0 0\n0 %d\n",m,m-1);
        else printf("1 0\n%d 0\n0 0\n%d 0\n",n,n-1);
	}
	else if( 2*sqrt((a-1)*(a-1)+b*b) > b+sqrt(a*a+b*b)){
		if(m>n) printf("1 0\n%d %d\n0 0\n%d %d\n",n,m,n-1,m);
		else printf("0 1\n%d %d\n0 0\n%d %d\n",n,m,n,m-1);
	}
	else{
		if(m>n) printf("0 0\n%d %d\n%d 0\n0 %d\n",n,m,n,m);
        else printf("0 0\n%d %d\n0 %d\n%d 0\n",n,m,m,n);
	}
	return 0;
}