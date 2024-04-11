#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[105],ans,sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans=max(ans,a[i]);
		sum+=a[i];
	}
	sum*=2;
	ans=max(ans,sum/n+1);
	printf("%d\n",ans);
	return 0;
}