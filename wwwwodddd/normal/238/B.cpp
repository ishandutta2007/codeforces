#include<stdio.h>
#include<algorithm>
using namespace std;
int n,h,a[100020],b[100020],v;
int main()
{
	scanf("%d %d",&n,&h);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	int p=min_element(a,a+n)-a;
	sort(a,a+n);
	int t1=a[n-1]+a[n-2]-a[0]-a[1],t2=max(a[n-1]+a[n-2],a[0]+a[n-1]+h)-min(a[0]+a[1]+h,a[1]+a[2]);
	if(n<3||t2>t1)
		p=n;
	printf("%d\n",min(t1,t2));
	for(int i=0;i<n;i++)
		printf("%d ",1+(p==i));
	return 0;
}