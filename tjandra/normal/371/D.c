#include<stdio.h>
typedef unsigned u;
u p[200002],d[200002],a[200002],e[200002];
int main()
{
	u n,i,j,k,q;
	scanf("%u",&n);d[n]=n;
	for(i=0;i<n;scanf("%u",p+i++))d[i]=i;
	for(scanf("%u",&q);q--;)
	{
		scanf("%u",&i);
		if(i==2){scanf("%u",&i);printf("%u\n",a[--i]);continue;}
		scanf("%u%u",&i,&j);i--;
		while(j)
		{
			for(k=0;d[i]!=i;i=d[i])e[k++]=i;
			while(k--)d[e[k]]=i;
			if(i==n)break;
			if(j>=p[i]-a[i])
			{
				j-=p[i]-a[i];a[i]=p[i];
				d[i]=i+1;
			}
			else{a[i]+=j;j=0;}
		}
	}
	return 0;
}