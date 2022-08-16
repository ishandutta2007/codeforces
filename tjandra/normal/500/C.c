#include<stdio.h>
typedef unsigned u;
u W[1111],L[1111],R[1111],T[1111];
int main()
{
	u n,m,i,j,k,l,r=0,w=0;
	scanf("%u%u",&n,&m);
	for(i=0;i++<n;scanf("%u",W+i));
	for(i=0;i++<m;)
	{
		scanf("%u",&j);++w;
		for(R[k=i]=j,l=L[j],L[j]=i;--k>l;)if(T[R[k]]!=w)
		{r+=W[R[k]];T[R[k]]=w;}
	}
	printf("%u\n",r);
	return 0;
}