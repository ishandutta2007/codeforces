#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u p[300003],q[300003];
int F(const void*x,const void*y){return(int)p[*(u*)x]-(int)p[*(u*)y];}
int main()
{
	u n,i,j,k;
	scanf("%u",&n);
	for(i=0;i<n;scanf("%u",p+i++))q[i]=i;
	qsort(q,n,sizeof(u),F);
	for(i=j=0;i<n;i++,j++)
	{
		if(j<p[q[i]])j=p[q[i]];
		else p[q[i]]=j;
	}
	printf("%u",p[0]);
	for(i=0;++i<n;)printf(" %u",p[i]);
	putchar('\n');
	return 0;
}