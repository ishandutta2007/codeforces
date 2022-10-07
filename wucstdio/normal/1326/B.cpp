#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005];
int main()
{
	scanf("%d",&n);
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		printf("%d ",maxx+a[i]);
		maxx=max(maxx,maxx+a[i]);
	}
	printf("\n");
	return 0;
}