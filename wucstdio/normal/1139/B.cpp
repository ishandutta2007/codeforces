#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[200005],ans,now;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	now=2147483647;
	for(int i=n;i>=1;i--)
	{
		now--;
		now=min(now,a[i]);
		if(now==0)break;
		ans+=now;
	}
	printf("%I64d\n",ans);
	return 0;
}