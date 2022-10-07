#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,a[200005],k,ans,num;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]^=a[i-1];
		if(a[i]&(1<<k-1))a[i]^=(1<<k)-1;
	}
	sort(a+1,a+n+1);
	ans=n*(n+1)/2;
	int nowl=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[nowl])
		{
			ll num=i-nowl>>1;
			ans-=num*(num-1)/2+(i-nowl-num)*(i-nowl-num-1)/2;
			nowl=i;
		}
	}
	ll num=n+1-nowl>>1;
	ans-=num*(num-1)/2+(n+1-nowl-num)*(n+1-nowl-num-1)/2;
	printf("%I64d\n",ans);
	return 0;
}