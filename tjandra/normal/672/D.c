#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
u N[555555],n;
u lo(u k)
{
	u i;llu r=0llu,t;
	for(i=0;++i<n;)
	if((r+=(t=(N[i]-N[i-1])*(llu)i))>k)return N[i-1]+(k-(r-t))/i;
	return N[n-1];
}
u hi(u k)
{
	u i;llu r=0llu,t;
	for(i=n;--i;)
	if((r+=(t=(N[i]-N[i-1])*(llu)(n-i)))>k)return N[i]-(k-(r-t))/(n-i);
	return*N;
}
int main()
{
	u i=-1,k,l,h;llu s=0;
	for(scanf("%u%u",&n,&k);++i<n;s+=(N[i]=l))scanf("%u",&l);
	qsort(N,n,sizeof(u),F);
	l=lo(k);h=hi(k);
	printf("%u\n",l>=h?s%n?1:0:h-l);
	return 0;
}