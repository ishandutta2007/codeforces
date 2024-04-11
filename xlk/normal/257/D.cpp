#include <stdio.h>
int n;
int a[100020];
int v[100020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	long long s=0;
	for(int i=n;i--;)
	{
		if(a[i]>s)
			v[i]=1,s=a[i]-s;
		else
			s-=a[i];
	}
	int t=0;
	for(int i=0;i<n;i++)
	{
		t^=v[i];
		printf("%s",t?"+":"-");
	}
	return 0;
}