#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[105],d;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=2;i<=n;i++)
		{
			a[1]+=min(a[i],d/(i-1));
			d-=min(a[i],d/(i-1))*(i-1);
		}
		printf("%d\n",a[1]);
	}
	return 0;
}