#include<stdio.h>
typedef unsigned u;
u N[5555],S[5555],A[5555],x;
int main()
{
	u n,i=-1,j,k,d;
	for(scanf("%u",&n);++i<n;)scanf("%u",N+i);
	for(i=-1;++i<n;)
	{
		for(x=0,d=j=-1;++j<=n;)S[j]=0;
		for(j=i-1;++j<n;++A[d])
		{
			if((k=++S[N[j]])>x){x=k;d=N[j];}
			else if(k==x&&N[j]<d)d=N[j];
		}
	}
	for(i=0;++i<=n;)printf("%u%c",A[i],i<n?' ':'\n');
	return 0;
}