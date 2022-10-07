#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,u,v,a[105];
void solve()
{
	scanf("%d%d%d",&n,&u,&v);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		if(abs(a[i]-a[i-1])>=2)
		{
			printf("0\n");
			return;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(abs(a[i]-a[i-1])>=1)
		{
			printf("%d\n",min(u,v));
			return;
		}
	}
	printf("%d\n",v+min(u,v));
}
int main()
{
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}