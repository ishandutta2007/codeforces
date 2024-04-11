#include<stdio.h>
long long a[100020],n;
int main()
{
	scanf("%I64d",&n);
	for(int i=0;i<n;i++)
		scanf("%I64d",a+i);
	for(int i=0;i<n-1;i++)
		if((a[i+1]-a[i])*(a[i]-a[0])<0)
			return printf("3\n1 %d %d",i+1,i+2),0;
	puts("0");
}