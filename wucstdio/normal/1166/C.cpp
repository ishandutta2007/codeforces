#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[200005];
ll ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)a[i]=-a[i];
	}
	sort(a+1,a+n+1);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		while(now<i&&a[now]*2<a[i])now++;
		ans+=i-now;
	}
	printf("%I64d\n",ans);
	return 0;
}