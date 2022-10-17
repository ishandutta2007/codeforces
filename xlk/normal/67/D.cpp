#include<stdio.h>
#include<algorithm>
using namespace std;
int n,x;
int a[1000020];
int p[1000020];
int f[1000020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&x),p[x]=i;
	for(int i=0;i<n;i++)
		scanf("%d",&x),a[i]=-p[x]-1;
	for(int i=0;i<n;i++)
		*lower_bound(f,f+n,a[i])=a[i];
	printf("%d\n",lower_bound(f,f+n,0)-f);
	return 0;
}