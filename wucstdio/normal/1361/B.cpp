#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int t,n,p;
ll k[1000005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;i++)scanf("%lld",&k[i]);
		if(p==1)
		{
			printf("%d\n",n&1);
			continue;
		}
		sort(k+1,k+n+1);
		ll ans=0,dif=0,cur=1000000;
		for(int i=n;i>=1;i--)
		{
			if(dif==0)
			{
				cur=k[i];
				dif=1;
				ans+=quick_pow(p,k[i]);
			}
			else
			{
				while(cur>k[i])
				{
					cur--;
					dif*=p;
					if(dif>1000000)break;
				}
				if(cur==k[i])
				{
					dif--;
					ans-=quick_pow(p,k[i]);
				}
				else
				{
					for(int j=1;j<=i;j++)ans-=quick_pow(p,k[j]);
					break;
				}
			}
		}
		ans%=MOD;
		if(ans<0)ans+=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}