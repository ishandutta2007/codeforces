#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],maxx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=0)a[i]=-a[i]-1;
		maxx=min(maxx,a[i]);
	}
	if(n&1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==maxx)
			{
				a[i]=-a[i]-1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}