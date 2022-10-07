#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==2&&a[i-1]==3)
		{
			printf("Infinite\n");
			return 0;
		}
		if(a[i]==3&&a[i-1]==2)
		{
			printf("Infinite\n");
			return 0;
		}
		if(a[i]==1&&a[i-1]==2)ans+=3;
		if(a[i]==1&&a[i-1]==3)ans+=4;
		if(a[i]==2&&a[i-1]==1)ans+=3;
		if(a[i]==3&&a[i-1]==1)ans+=4;
	}
	for(int i=3;i<=n;i++)
	{
		if(a[i]==2&&a[i-1]==1&&a[i-2]==3)
		  ans--;
	}
	printf("Finite\n");
	printf("%d\n",ans);
	return 0;
}