#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
ll w[N],sum[N],a[N],weg[N],pos[N];
ll ck(ll x, ll mod){ x%=mod;if(x<0) x+=mod;return x;}
struct BIT
{
	ll sum[N],mod;
	void init(ll m){ mod=m;}
	BIT(){ for(int i=0;i<N;i++) sum[i]=0;}
	void Set(int i, ll f){ f=ck(f,mod);for(;i<N;i+=i&-i) sum[i]+=f,sum[i]=ck(sum[i],mod);}
	ll Get(int i){ ll ans=0;for(;i;i-=i&-i) ans+=sum[i],ans=ck(ans,mod);return ans;}
	ll Get(int l, int r){ return ck(Get(r)-Get(l-1),mod);}
} WTree,STree;
int main()
{
	int n,q,l,r,i,j,k;
	scanf("%i %i",&n,&q);WTree.init(3e18);STree.init(1e9+7);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]-=i-n;
	for(i=1;i<=n;i++) scanf("%lld",&w[i]),WTree.Set(i,w[i]);
	for(i=1;i<=n;i++) STree.Set(i,a[i]*w[i]);
	int mod=1e9+7;
	while(q--)
	{
		scanf("%i %i",&l,&r);
		if(l<0)
		{
			l=-l;
			WTree.Set(l,r-w[l]);
			STree.Set(l,-a[l]*w[l]);
			w[l]=r;
			STree.Set(l,a[l]*w[l]);
		}
		else
		{
            int top=r,bot=l,mid;
            ll all=WTree.Get(l,r);
            while(top>=bot)
			{
				mid=top+bot>>1;
				ll lo=WTree.Get(l,mid-1);
				ll hi=WTree.Get(mid+1,r);
				if(lo>all/2) top=mid-1;
				else if(hi>all/2) bot=mid+1;
				else break;
			}
			//printf("mid:%i ",mid);
            ll fin=a[mid];
            ll lo=STree.Get(l,mid-1),hi=STree.Get(mid+1,r);
            ll ow=WTree.Get(l,mid-1)%mod,up=WTree.Get(mid+1,r)%mod;
            ll ans=(fin*ow%mod-lo+mod)%mod;
            ans+=(hi-fin*up%mod+mod)%mod;
            ans%=mod;
            printf("%lld\n",ans);
		}
	}
	return 0;
}