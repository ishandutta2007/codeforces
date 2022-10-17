#include<stdio.h>
int n,s;
int z[6020];
int P(int x)
{
	if(x<2)
		return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		z[i]=1;
	s=n*(n+1)/2;
	if(!P(s))
	{
		if(s&1&&!P(s-2))
			s-=3,z[2]=3;
		for(int i=2;i<=s;i++)
			if(P(i)&&P(s-i))
			{
				z[i-1]=2;
				break;
			}
	}
	for(int i=0;i<n;i++)
		printf("%d ",z[i]);
	return 0;
}