#include<stdio.h>
typedef unsigned u;
int main()
{
	u a,b,c,p,q,r,M=0,N;
	scanf("%u%u%u",&a,&b,&c);
	p=a+b-c;
	q=b+c-a;
	r=a-b+c;
	if(M<a){M=a;N=b+c;}
	if(M<b){M=b;N=a+c;}
	if(M<c){M=c;N=a+b;}
	if((p&1)|(q&1)|(r&1)|(M>N))printf("Impossible\n");
	else printf("%u %u %u\n",p>>1,q>>1,r>>1);
	return 0;
}