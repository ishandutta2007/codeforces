#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		bool flag=1;
		for(int i=2;i<=n;i++)
		  if(a[i]!=a[i-1])flag=0;
		if(flag)printf("%d\n",n);
		else printf("1\n");
	}
	return 0;
}