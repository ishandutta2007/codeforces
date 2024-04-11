#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
ll MOD=1e9+7;
ll qp(ll a,ll b)
{
    a%=MOD; ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return ans;
}
ll divm(ll a,ll v)
{return a*qp(v,MOD-2)%MOD;}
//= = 
ll mulm(ll a,ll b)
{return a*b%MOD;}
// 
typedef pair<ll,ll> pll;
pll operator + (pll a,pll b)
{return pll((a.fi+b.fi)%MOD,(a.se+b.se)%MOD);}
pll operator - (pll a,pll b)
{return pll((a.fi-b.fi)%MOD,(a.se-b.se)%MOD);}
pll operator * (pll a,pll b)
{
	ll fii=a.fi*b.fi+a.se*b.se*5;
	ll see=a.se*b.fi+a.fi*b.se;
	return pll(fii%MOD,see%MOD);
}
pll operator * (pll a,ll b)
{
	return pll(a.fi*b%MOD,a.se*b%MOD);
}
pll qp(pll a,ll b)
{
	pll ans=pll(1,0);
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a; b>>=1;
	}
	return ans;
}
pair<pll,pll> qh(pll a,ll b)
{
	if(!b) return pair<pll,pll>(pll(1,0),pll(1,0));
	pair<pll,pll> hf_=qh(a,(b-1)>>1);
	pll hf=hf_.fi,ans=hf_.se*a;
	++ans.fi; ans=hf*ans;
	ll tot=((b-1)>>1)<<1;
	pll ma=hf_.se*hf_.se;
	while((tot++)<b) ma=ma*a;
	if(b&1);else ans=ans+ma;
	return pair<pll,pll>(ans,ma);
}
ll k,l,r;
template<class T>
inline void MM(T& s)
{s=(s%MOD+MOD)%MOD;}
ll ss[233][233],C[233][233],c[233];
void gc()
{
	ll jc=1;
	for(int i=1;i<=k;i++)
		jc=jc*i%MOD;
	for(int i=0;i<=k;i++)
		c[i]=divm(ss[k][i],jc);
}
pll top(ll x)
{return pll(x,0);}
ll inv2=qp(2,MOD-2),inv5=qp(5,MOD-2);
pll p(inv2,inv2),q(inv2,-inv2);
pll ps[SZ],qs[SZ];
ll gfib(ll r,int s)
{
	pll ans=pll(0,0);
	for(int j=0;j<=s;j++)
	{
		pll ex=ps[j]*qs[s-j];
		pll sum=qh(ex,r).fi*C[s][j];
		if((s-j)&1) ans=ans-sum;
		else ans=ans+sum;
	}
	ans=ans*qp(pll(0,inv5),s);
	//MM(ans.fi);
	return ans.fi;
}
ll gsum(ll r)
{
	ll ans=0;
	for(int i=0;i<=k;i++)
		ans=(ans+gfib(r,i)*c[i]%MOD)%MOD;
	return ans;
}
int main()
{
	ps[0]=qs[0]=pll(1,0);
	for(int i=1;i<=200;i++)
		ps[i]=ps[i-1]*p,
		qs[i]=qs[i-1]*q;
	ss[0][0]=C[0][0]=1;
	for(int i=1;i<=200;i++)
	{
		ss[i][0]=0; C[i][0]=1;
		for(int j=1;j<=i;j++)
			ss[i][j]=(ss[i-1][j-1]-
			mulm(i-1,ss[i-1][j]))%MOD,
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	scanf("%d%I64d%I64d",&k,&l,&r); l+=2; r+=2;
	gc(); ll ans=gsum(r)-gsum(l-1);
	ans=(ans%MOD+MOD)%MOD;
	printf("%I64d\n",ans);
}
//200 100000000000000000 100000000000000000