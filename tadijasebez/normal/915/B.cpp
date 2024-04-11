#include <stdio.h>
int min(int a, int b){ return a>b?b:a;}
int abs(int x){ return x>0?x:-x;}
int main()
{
	int n,x,l,r;
	scanf("%i %i %i %i",&n,&x,&l,&r);
	if(l==1 && r==n) return printf("0\n"),0;
	if(l==1) return printf("%i\n",abs(x-r)+1),0;
	if(r==n) return printf("%i\n",abs(x-l)+1),0;
	printf("%i\n",min(abs(x-l),abs(x-r))+r-l+2);
	return 0;
}