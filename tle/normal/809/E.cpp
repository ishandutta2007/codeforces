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
#define SZ 666666
int n,a[SZ],p[SZ],g[SZ],h[SZ];
vector<int> ys[SZ];
Edg
int d[SZ],sz[SZ],son[SZ];
void dfs(int x,int f=0)
{
	d[x]=d[f]+1; sz[x]=1;
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x); sz[x]+=sz[b];
		if(sz[b]>sz[son[x]]) son[x]=b;
	}
}
const int MOD=1e9+7;
ll s0[SZ],s1[SZ],cp[SZ]; int cr; ll ans=0;
void clr(int x)
{
	for(auto s:ys[a[x]])
		s0[s]=s1[s]=0;
}
void ins(int x)
{
	for(auto s:ys[a[x]])
		(s0[s]+=p[a[x]]*(ll)h[s])%=MOD,
		(s1[s]+=p[a[x]]*(ll)h[s]%MOD*d[x])%=MOD;
}
void upd(int x)
{
	//(p1+p2-cd)*sth
	//(p1-cd)*sth
	for(auto s:ys[a[x]])
		ans+=(s1[s]+s0[s]*(ll)(d[x]-cr))%MOD*p[a[x]],
		ans%=MOD;
	//p[a[x]]*h[s]*(d[x]+d[y]-cr)*p[a[y]]
}
int skip=0;
template<void(*func)(int)>
void edt(int x,int f)
{
    func(x);
    for esb(x,e,b)
        if(b!=f&&b!=skip) edt<func>(b,x);
}
void dd(int x,int f=0,bool kep=0)
{
    for esb(x,e,b)
        if(b!=f&&b!=son[x]) dd(b,x);
    if(son[x])
        dd(son[x],x,1), skip=son[x];
    cr=d[x]*2;
	for esb(x,e,b) if(b!=f&&b!=son[x])
        edt<upd>(b,x), edt<ins>(b,x);
    upd(x); ins(x);
    
    skip=0;
    if(!kep) edt<clr>(x,f);
}
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=max(n,10);++i)
	{
		int j=i,t=i;
		for(int s=2;s*s<=j;++s) if(j%s==0)
		{
			t=t/s*(s-1); while(j%s==0) j/=s;
		}
		if(j>1) t=t/j*(j-1);
		p[i]=t; g[i]=i*qp(p[i],MOD-2)%MOD;
	}
	for(int i=1;i<=n;++i) h[i]=g[i];
	for(int i=1;i<=n;++i)
		for(int j=i+i;j<=n;j+=i) h[j]=(h[j]-h[i])%MOD;
	
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i) ys[j].pb(i);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	dfs(1); dd(1);
	ans=(ans%MOD+MOD)%MOD;
	ll sb=n*(ll)(n-1)/2; sb%=MOD;
	sb=qp(sb,MOD-2);
	ans=ans*sb%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}
//?