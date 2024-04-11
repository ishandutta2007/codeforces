#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=abs(a[i]);
			if(i&1)printf("%d ",a[i]);
			else printf("%d ",-a[i]);
		}
		printf("\n");
	}
	return 0;
}