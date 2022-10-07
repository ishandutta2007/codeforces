#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
int n,m,k,cnt[5005];
ll p,h[100005],t[100005];
bool check(ll v)
{
	memset(cnt,0,sizeof(cnt));
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		if(h[i]+t[i]*m<=v)continue;
		tot+=(h[i]+t[i]*m-v-1)/p+1;
		if(tot>m*k)return 0;
		for(ll now=(h[i]+t[i]*m-v-1)%p+1;now+v<=h[i]+t[i]*m;now+=p)
		{
			if(now<=h[i])cnt[1]++;
			else
			{
				ll d=(now-h[i]-1)/t[i]+1;
				if(d==m)return 0;
				cnt[d+1]++;
			}
		}
	}
	ll s=0;
	for(int i=1;i<=m;i++)
	{
		s+=cnt[i];
		s-=k;
		if(s<0)s=0;
	}
	return s==0;
}
int main()
{
	scanf("%d%d%d%lld",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&h[i],&t[i]);
	}
	ll l=0,r=1000000000000000;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}