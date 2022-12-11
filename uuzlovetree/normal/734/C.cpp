#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
ll n,x,s;
ll a[maxn],b[maxn],c[maxn],d[maxn];
int m,k;
int main()
{
	scanf("%I64d%d%d",&n,&m,&k);
	scanf("%I64d%I64d",&x,&s);
	for(int i=1;i<=m;++i)scanf("%I64d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%I64d",&b[i]);
	for(int i=1;i<=k;++i)scanf("%I64d",&c[i]);
	for(int i=1;i<=k;++i)scanf("%I64d",&d[i]);
	ll ans=5e18;
	a[0]=x;b[0]=0;
	for(int i=0;i<=m;++i)if(s-b[i]>=0)
	{
		ll res=0;
		ll nx=a[i],ns=s-b[i];
		int l=0,r=k,t=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(d[mid]<=ns)t=mid,l=mid+1;
			else r=mid-1;
		}
		res=(n-c[t])*nx;
		ans=min(ans,res);
	}
	printf("%I64d\n",ans);
	return 0;
}