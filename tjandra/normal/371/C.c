#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
int main()
{
	char Ch;
	llu r,L,U,M;
	u b,s,c,B,S,C,pb,ps,pc,i,j,k;
	u cek(llu N)
	{
		llu nb,ns,nc;
		nb=B*N;ns=S*N;nc=C*N;
		if(nb>b)nb-=b;
		else nb=0;
		if(ns>s)ns-=s;
		else ns=0;
		if(nc>c)nc-=c;
		else nc=0;
		if(nb*pb+ns*ps+nc*pc<=r)return 1;
		return 0;
	}
	for(B=S=C=0;(Ch=getchar())!='\n';)
	{
		if(Ch=='B')B++;
		if(Ch=='S')S++;
		if(Ch=='C')C++;
	}
	scanf("%u%u%u%u%u%u%I64u",&b,&s,&c,&pb,&ps,&pc,&r);
	for(L=0,U=r+3000;(M=(L+U)>>1)>L;)
	{
		if(cek(M))L=M;
		else U=M;
	}
	printf("%I64u\n",L);
	return 0;
}