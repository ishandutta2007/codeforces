#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[10005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum==0)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		sort(a+1,a+n+1);
		if(sum<0)
		{
			for(int i=1;i<=n;i++)printf("%d ",a[i]);
			printf("\n");
		}
		else
		{
			for(int i=n;i>=1;i--)printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}