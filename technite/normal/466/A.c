#include<stdio.h>
int main()
{
	int n,m,a,b;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	int cost =0;

	
	if(b/m<a)
	{
		cost=cost+(int)(n/m)*b;
		if(a*(n%m)>b) {
			cost+=b;}
		else cost+=a*(n%m);
	}
	else cost=a*n;
	printf("%d",cost);
}