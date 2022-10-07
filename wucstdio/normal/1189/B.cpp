#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]>=a[n-1]+a[n-2])
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n-2;i++)printf("%d ",a[i]);
	printf("%d %d\n",a[n],a[n-1]);
	return 0;
}