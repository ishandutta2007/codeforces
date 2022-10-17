#include<stdio.h>
int n;
double a[100020];
double z,w;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf",a+i);	
	for(int i=0;i<n;i++)
	{
		++w*=a[i];
		z+=w;
	}
	z*=2;
	for(int i=0;i<n;i++)
		z-=a[i];
	printf("%.20lf\n",z);
	return 0;
}