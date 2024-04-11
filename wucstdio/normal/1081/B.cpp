#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans[100005],num[100005],a[100005];
int rest[100005],now,p[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=n-a[i];
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]%i!=0)
		{
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
	{
		if(num[a[i]]==0)
		{
			p[a[i]]=++now;
			num[a[i]]=a[i];
		}
		printf("%d ",p[a[i]]);
		num[a[i]]--;
	}
	printf("\n");
	return 0;
}