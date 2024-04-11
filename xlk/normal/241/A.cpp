#include<stdio.h>
int s,z,m,k,u,t;
int d[100020];
int w[100020];
int main()
{
	scanf("%d %d",&m,&k);
	for(int i=0;i<m;i++)
		scanf("%d",d+i),z+=d[i];
	for(int i=0;i<m;i++)
		scanf("%d",w+i);
	for(int i=0;i<m;i++)
	{
		if(u<w[i])
			u=w[i];
		s+=w[i];
		if(s<d[i])
		{
			t=(d[i]-s+u-1)/u;
			z+=t*k;
			s+=u*t;
		}
		s-=d[i];
	}
	printf("%d",z);
	return 0;
}