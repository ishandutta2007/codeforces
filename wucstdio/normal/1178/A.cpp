#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[105],ans[105],top,sum,s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ans[++top]=1;
	s=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]*2<=a[1])
		{
			ans[++top]=i;
			s+=a[i];
		}
	}
	if(s*2>sum)
	{
		printf("%d\n",top);
		for(int i=1;i<=top;i++)printf("%d ",ans[i]);
		printf("\n");
		return 0;
	}
	printf("0\n");
	return 0;
}