#include<stdio.h>
#include<iostream>
using namespace std;
int a[100020];
int j,n;
long long z;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
		scanf("%d",a+i);
	for(int i=0;i<n-1;i++)
	{
		for(j=1;i+j*2<n;j*=2)
			;
		z+=a[i];
		a[i+j]+=a[i];
		printf("%I64d\n",z);
	}
	return 0;
}