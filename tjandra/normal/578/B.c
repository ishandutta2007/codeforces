#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
int cmp(const void*x,const void*y){return*(int*)x-*(int*)y;}
llu D[222222][11],E[222222][11];
u A[222222],x;
llu F(u n,u k)
{
	llu s=0,r=A[--n],y,z;u i;y=r;
	if(D[n][k])return D[n][k]-1;
	if(!n)
	{
		for(i=k;i--;)r*=x;
		E[n][k]=r;
		return(D[n][k]=r+1)-1;
	}
	r=y|F(n,k);
	s=y|E[n-1][k];
	if(r<s){z=r;r=s;s=z;}
	for(i=k;i--;)
	{
		y*=x;
		if((z=y|F(n,i))>r){s=r;r=z;}
		else if(z>s&&z<r)s=z;
		if((z=y|E[n-1][i])>r){s=r;r=z;}
		else if(z>s&&z<r)s=z;
	}
	E[n][k]=s;
	return(D[n][k]=r+1)-1;
}
int main()
{
	u n,k,i=-1,j;
	for(scanf("%u%u%u",&n,&k,&x);++i<n;scanf("%u",A+i));
	qsort(A,n,sizeof(u),cmp);
	printf("%I64u\n",F(n,k));
//	for(i=-1;++i<n;putchar('\n'))for(j=-1;++j<n;)printf("(%I64i:%I64i) ",D[i][j]-1,E[i][j]);
	return 0;
}