#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
ll d[100005],ans;
bool vis[1000005];
void check()
{
	ll x=ans;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i)continue;
		while(x%i==0)x/=i;
		if(x==1)ans*=i;
		return;
	}
	ans=ans*ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=1;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&d[i]);
			ans=ans/__gcd(ans,d[i])*d[i];
			if(ans>1e13)flag=0;
			vis[d[i]]=1;
		}
		if(flag)check();
		if(flag)if(vis[1]||(ans<=1000000&&vis[ans]))flag=0;
		if(flag)
		for(ll i=2;i*i<=ans;i++)
		{
			if(ans%i)continue;
			if(ans/i>1e6||!vis[i]||!vis[ans/i])
			{
				flag=0;
				break;
			}
		}
		for(int i=1;i<=n;i++)vis[d[i]]=0;
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}