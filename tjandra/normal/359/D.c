#include<stdio.h>
typedef unsigned u;
u N[300000],L[300000],R[300000];
int main()
{
	u n,i,j,k,d,r;
	scanf("%u",&n);
	for(i=0;i<n;i++)
	{
		scanf("%u",N+i);
		for(j=i;j;)
		{
			if(N[j-1]%N[i]!=0)break;
			j=L[j-1];
		}
		L[i]=j;
	}
	for(i=n--;i--;)
	{
		for(j=i;j!=n;)
		{
			if(N[j+1]%N[i]!=0)break;
			j=R[j+1];
		}
		R[i]=j;
	}
	for(d=R[N[j=i=0]=0],r=1;i++<n;)
	{
		if(R[i]-L[i]>d)
		{
			d=R[i]-L[i];
			N[j=0]=L[i];
		}
		else if(R[i]-L[i]==d&&L[i]!=N[j])N[++j]=L[i];
	}
	printf("%u %u\n%u",++j,d,*N+1);
	for(i=0;++i<j;)printf(" %u",N[i]+1);
	putchar('\n');
	return 0;
}