#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n,k;
ll a[200010];
ll b[200010];
int s[200010];
ll ans;
bool check(ll val)
{
	memset(s,0,sizeof(s));
	int num=k;
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			continue;
		}
		ll sum=a[i];
		s[min(sum/b[i]+1,1ll*(k+1))]++;
		while(sum<1ll*k*b[i])
		{
			if(!num)
			{
				break;
			}
			sum+=val;
			s[min(sum/b[i]+1,1ll*(k+1))]++;
			num--;
		}
	}
	for(int i=1;i<=k;i++)
	{
		s[i]+=s[i-1];
		if(s[i]>i)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	k--;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	ll l=0,r=2000000000000ll;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	if(!ans)
	{
		printf(check(0)?"0":"-1");
	}
	else
	{
		printf("%lld",ans);
	}
}