#include<stdio.h>
typedef unsigned u;
u satu[100],dua[100];
int main()
{
	u n,k,i,j,x;
	scanf("%u%u",&n,&k);
	for(i=j=0;i<n;i++,j++)
	{
		if(j==k)j=0;
		scanf("%u",&x);
		if(x==1)satu[j]++;
		if(x==2)dua[j]++;
	}
	for(i=j=0;i<k;i++)
	{
		j+=satu[i]>dua[i]?dua[i]:satu[i];
	}
	printf("%u\n",j);
	return 0;
}