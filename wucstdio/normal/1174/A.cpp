#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	n*=2;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[1]==a[n])
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}