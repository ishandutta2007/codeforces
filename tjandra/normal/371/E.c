#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
int F(const void*x,const void*y){return(*(u*)x>=*(u*)y)+(*(u*)x>*(u*)y)-1;}
llu Ns[300000];
u N[300000],S[300000];
int G(const void*x,const void*y)
{
	return(N[*(u*)x]>=N[*(u*)y])+(N[*(u*)x]>N[*(u*)y])-1;
}
int main()
{
	llu s,M;
	int in;
	u n,i,k,lo,hi;
	scanf("%u",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i",&in);
		N[i]=in+100000000;
		S[i]=i;
	}
	qsort(S,n,sizeof(u),G);
	qsort(N,n,sizeof(u),F);Ns[0]=N[0];
	for(i=0;++i<n;)Ns[i]=Ns[i-1]+N[i];
	for(s=0,scanf("%u",&k),i=1;i<k;i++)
	{
		s+=i*(llu)N[i]-Ns[i-1];
	}
	for(lo=0,hi=k-1,M=s;i<n;i++)
	{
		s+=(k-1)*(llu)N[i]-Ns[i-1]+Ns[i-k];
		s-=Ns[i-1]-Ns[i-k]-(k-1)*(llu)N[i-k];
		if(M>s)
		{
			M=s;lo=i-k+1;hi=i;
		}
	}
	for(i=lo;i<=hi;i++)printf("%u ",S[i]+1);
	putchar('\n');
	return 0;
}