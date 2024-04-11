#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[1005],ans[1005],top;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	  a[i]=a[i+1]-a[i];
	for(int i=2;i<=n;i++)
	{
		bool flag=1;
		for(int j=1;j<=n-i+1;j++)
		  if(a[j]!=a[i+j-1])flag=0;
		if(flag)ans[++top]=i-1;
	}
	ans[++top]=n;
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
	  printf("%d ",ans[i]);
	printf("\n");
	return 0;
}