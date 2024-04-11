#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[200005],prime[1000005],num;
bool flag[1000005];
void pre(int n)
{
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])prime[++num]=i;
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	pre(1000000);
	scanf("%d",&n);
	ll maxx=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	ll m=num;
	for(int i=-(int)min((ll)n,maxx-1);i<=n;i++)prime[++m]=maxx+i;
	ll st=prime[num+1];
	for(int i=1;i<=num;i++)
	{
		ll s=num+(prime[i]-(st-1)%prime[i]);
		for(ll j=s;j<=m;j+=prime[i])
		{
			while(prime[j]%prime[i]==0)
			  prime[j]/=prime[i];
		}
	}
	for(int i=(int)num+1;i<=m;i++)
	  if(prime[i]!=1)prime[++num]=prime[i];
	ll ans=n;
	for(int i=1;i<=num;i++)
	{
		ll p=prime[i];
		ll res=0;
		for(int j=1;j<=n;j++)
		{
			res+=a[j]<p?p-a[j]:min(a[j]%p,p-a[j]%p);
			if(res>ans)break;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}