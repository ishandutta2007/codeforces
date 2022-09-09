#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000050;
int go[N][2],a[N],b[N],n,i,j,p,sz[N],tsz;
ll k,x[N];
int main()
{
	scanf("%i %lld",&n,&k);
	for(i=2;i<=n;i++) scanf("%i %lld",&p,&x[i]),x[i]^=x[p];
	for(i=1;i<=n;i++) a[i]=b[i]=1;
	ll ans=0;
	for(j=61;~j;j--)
	{
		for(i=1;i<=tsz;i++) go[i][0]=go[i][1]=sz[i]=0;
		tsz=0;
		for(i=1;i<=n;i++)
		{
			int g=(x[i]>>j)&1;
			if(!go[a[i]][g]) go[a[i]][g]=++tsz;
			sz[a[i]=go[a[i]][g]]++;
		}
		ll sum=0;
		for(i=1;i<=n;i++)
		{
			int g=(x[i]>>j)&1;
			sum+=sz[go[b[i]][g]];
		}
		if(sum<k)
		{
			ans+=(ll)1<<j;
			k-=sum;
			for(i=1;i<=n;i++)
			{
				int g=(x[i]>>j)&1;
				b[i]=go[b[i]][g^1];
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				int g=(x[i]>>j)&1;
				b[i]=go[b[i]][g];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}