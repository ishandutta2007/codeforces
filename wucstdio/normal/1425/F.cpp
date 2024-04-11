#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		printf("? %d %d\n",i,n);
		fflush(stdout);
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n-1;i++)a[i]-=a[i+1];
	printf("? %d %d\n",n-2,n-1);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	v-=a[n-2];
	a[n]=a[n-1]-v;
	a[n-1]=v;
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}