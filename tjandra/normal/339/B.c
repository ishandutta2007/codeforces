#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
int main()
{
	llu r=0;
	u m,n,p=1,q;
	for(scanf("%u%u",&n,&m);m--;p=q)
	{
		scanf("%u",&q);
		if(q>=p)r+=q-p;
		else r+=n-p+q;
	}
	m=r/1000000000u;
	n=r%1000000000u;
	if(m)
	{
		printf("%u%.9u\n",m,n);
	}
	else printf("%u\n",n);
	return 0;
}