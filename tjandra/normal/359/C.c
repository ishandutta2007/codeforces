#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
int ai[100000],an[100000];
int main()
{
	llu S=0,G;
	u p,m,n,i,j,k;
	scanf("%u%u%u",&n,&p,ai);
	for(S=*ai,k=0,j=1;--n;)
	{
		scanf("%u",&m);
		S+=m;
		if(m==ai[k])j++;
		else
		{
			an[k++]=j;
			ai[k]=m;j=1;
		}
	}
//	printf("S=%llu\n",S);
	for(an[k]=j,G=S-ai[k];k;k--)
	{
//		printf("G=%llu\n",G);
		i=an[k];
		j=S-G-ai[k-1];
		for(m=0;i%p==0&&m<j;m++)i/=p;/*GRRR!!!*/
		if(m!=j)
		{
			G+=m;
			goto fin;
		}
		an[k-1]+=i;G+=j;
	}
//	printf("ding!\n");
	i=an[0];
	for(k=0;i!=0&&i%p==0;k++)i/=p;
	G+=k;fin:;
	if(G>S)G=S;
	for(n=1,m=p;G;G>>=1)
	{
		if(G&1)n=n*(llu)m%1000000007u;
		m=m*(llu)m%1000000007u;
	}
	printf("%u\n",n);
	return 0;
}