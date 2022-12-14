#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
#define ll long long
#define ld long double
ll p[N],q[N],n,X,ans;int num,tot;
ll phi(ll x){ll ret=x;for(int i=1;i<=num;i++)if(!(x%p[i]))ret/=p[i],ret*=p[i]-1;return ret;}
// ll q_mul(ll x,ll n,ll mod){if(n<2147483647&&x<2147483647)return n*x%mod;ll ret=0;for(;n;n>>=1,x=(x<<1)%mod)if(n&1)ret=(ret+x)%mod;return ret;}
ll q_mul(ll x,ll y,ll mod){return ((x*y-(ll)(((ld)x*y+0.5)/mod)*mod)%mod+mod)%mod;}
ll q_pow(ll x,ll n,ll mod){ll ret=1;for(;n;n>>=1,x=q_mul(x,x,mod))if(n&1)ret=q_mul(ret,x,mod);return ret;}
void work(ll g)
{
	ll mod=n/g,ph=phi(mod),x=X%mod,K=ph;
	for(int i=1;i<=tot;i++)while(K%q[i]==0&&q_pow(x,K/q[i],mod)==1)K/=q[i];
	ans+=ph/K;
}
void get_pri(ll x)
{
	q[++tot]=x+1;
	for(int i=2;i<=(x/i);i++)
		if(x%i==0){q[++tot]=i;while(x%i==0)x/=i;}
	if(x!=1)q[++tot]=x;
}
void init()
{
	ll x=n;
	for(int i=2;i<=(x/i);i++)
		if(x%i==0){p[++num]=i;while(x%i==0)x/=i;}
	if(x!=1)p[++num]=x;
	for(int i=1;i<=num;i++)get_pri(p[i]-1);
	sort(q+1,q+tot+1);tot=unique(q+1,q+tot+1)-q-1;
}
int main()
{
	scanf("%lld%lld",&n,&X);init();int i;
	for(i=1;i<(n/i);i++)
		if(n%i==0)work(i),work(n/i);
	if(1ll*i*i==n)work(i);
	printf("%lld\n",ans);
	return 0;
}