#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,res[1000005];
ll k;
int main()
{
	scanf("%d%lld",&n,&k);
	if(k<1ll*(n+1)*n/2)
	{
		printf("-1\n");
		return 0;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=max(i,n-i+1);
	if(k>=ans)
	{
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)printf("%d ",i);
		printf("\n");
		for(int i=1;i<=n;i++)printf("%d ",n-i+1);
		printf("\n");
		return 0;
	}
	else
	{
		printf("%lld\n",k);
		k-=1ll*(n+1)*n/2;
		for(int i=1;i<=n;i++)printf("%d ",i);
		printf("\n");
		for(int i=1;i<=n;i++)res[i]=i;
		for(int i=1;i<=n;i++)
		{
			ll d=max(1,n-i+1-i);
			if(d<=k)
			{
				k-=d;
				swap(res[i],res[n-i+1]);
			}
			else
			{
				ll v=i+k;
				swap(res[i],res[v]);
				k=0;
			}
			printf("%d ",res[i]);
		}
		printf("\n");
	}
	return 0;
}