#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[1000005],s[1000005],sum,ans=1000000000000000000;
void check(ll p)
{
	ll now=0,res=0;
	int last=0;
	for(int i=1;i<=n;i++)s[i]=(s[i-1]+a[i])%p;
	for(int i=1;i<=n;i++)
	{
		ll pre=now;
		now=(now+a[i])%p;
		if(now<pre)
		{
			for(int j=last;j<i;j++)
			{
				if(s[j]*2<p)res+=s[j];
				else res+=p-s[j];
			}
			last=i;
		}
	}
	ans=min(ans,res);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	for(ll i=2;i*i<=sum;i++)
	{
		if(sum%i==0)
		{
			check(i);
			while(sum%i==0)sum/=i;
		}
	}
	if(sum!=1)check(sum);
	if(ans==1000000000000000000)printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}