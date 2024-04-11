#include<bits/stdc++.h>
#define maxn 100005
#define ll long long 
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
ll k,a[maxn],b[maxn];
ll calc(ll t)
{
	ll tot=0;
	for(int i=1;i<=n;++i)
	{
		ll L=0,R=a[i],ans=0;
		while(L<=R)
		{
			ll M=(L+R)/2;
			if(a[i]-M*M*3-M*3-1>=t)ans=M,L=M+1;
			else R=M-1;
		}
		b[i]=ans;
		tot+=ans;
	}
	return tot;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	ll L=-(ll)4e18,R=(ll)2e9,ans=R;
	while(L<=R)
	{
		ll M=(L+R)/2;
		if(calc(M)<=k)ans=M,R=M-1;
		else L=M+1;
	}
	calc(ans);
	for(int i=1;i<=n;++i)k-=b[i];
	priority_queue< pair<ll,int> > pq;
	for(int i=1;i<=n;++i)if(b[i]<a[i])pq.push(mp(a[i]-b[i]*b[i]*3-b[i]*3-1,i));
	for(int i=1;i<=k;++i)
	{
		int u=pq.top().second;pq.pop();
		++b[u];
		if(b[u]<a[u])pq.push(mp(a[u]-b[u]*b[u]*3-b[u]*3-1,u));
	}
	for(int i=1;i<=n;++i)printf("%lld ",b[i]);
}