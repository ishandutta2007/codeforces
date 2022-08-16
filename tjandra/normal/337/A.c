#include<stdio.h>
typedef unsigned u;
u dat[1003];
int main()
{
	u m,n,i,j,s,r=1002;
	for(scanf("%u%u",&m,&n);n--;)
	{
		scanf("%u",&i);
		dat[i]++;
	}
	for(i=j=0,s=0;i<=1001;)
	{
		s-=dat[i++];
		while(s<m)
		{
			s+=dat[j++];
			if(j==1002)
			{
				if(r>(j-i-1))r=j-i-1;
				goto fin;
			}
		}
		if(r>(j-i-1))r=j-i-1;
	}
	fin:;
	printf("%u\n",r);
	return 0;
}