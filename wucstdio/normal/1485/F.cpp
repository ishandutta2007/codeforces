#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int t,n,r[200005];
ll b[200005],s[200005],f[200005],c[200005];
map<ll,int>mp;
void add(int p,ll v)
{
	while(p<=n+1)
	{
		c[p]+=v;
		p+=p^(p&(p-1));
	}
}
ll sum(int p)
{
	ll ans=0;
	while(p)
	{
		ans+=c[p];
		p&=p-1;
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n+1;i++)c[i]=0;
		mp.clear();
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]),s[i]=s[i-1]+b[i];
		for(int i=n;i>=1;i--)
		{
			mp[s[i]]=i;
			r[i]=mp[s[i-1]];
			if(!r[i])r[i]=n+1;
		}
		f[0]=1;
		add(r[1],1);
		for(int i=1;i<=n;i++)
		{
			f[i]=0;
			f[i]+=sum(n+1)-sum(i-1);
			f[i]%=MOD;
			if(i<n)add(r[i+1],f[i]);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}