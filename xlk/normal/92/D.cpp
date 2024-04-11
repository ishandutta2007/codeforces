#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[100020],c[100020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),c[i]=a[i];
	for(int i=n-2;i>=0;i--)
		c[i]=min(c[i],c[i+1]);
	for(int i=0;i<n;i++)
		printf("%d ",lower_bound(c+i+1,c+n,a[i])-c-i-2);
	return 0;
}