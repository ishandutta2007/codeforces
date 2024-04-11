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
#define yn yyn
int n,t,x[SZ],y[SZ];
int ys[SZ],yn;
pair<int,pair<pii,int> > os[SZ]; int on;
const int M=128;
pii operator + (pii a,pii b)
{
	if(a.fi<b.fi) return a;
	if(b.fi<a.fi) return b;
	return pii(a.fi,a.se+b.se);
}
pii seg[SZ]; int tg[SZ],ls[SZ],rs[SZ];
void pd(int x)
{
	if(!tg[x]) return;
	seg[x].fi+=tg[x];
	if(x<=M)
		tg[x+x]+=tg[x],tg[x+x+1]+=tg[x];
	tg[x]=0;
}
void upd(int x)
{
	pd(x+x); pd(x+x+1);
	seg[x]=seg[x+x]+seg[x+x+1];
}
void edt(int x,int l,int r,int v)
{
	if(l>r||rs[x]<l||r<ls[x]) return;
	pd(x);
	if(l<=ls[x]&&rs[x]<=r)
	{
		tg[x]+=v; return;
	}
	edt(x+x,l,r,v);
	edt(x+x+1,l,r,v);
	upd(x);
}
map<int,ll> rss;
ll calc(int s)
{
	if(rss.count(s)) return rss[s];
	yn=0;
	for(int i=1;i<=n;++i)
		ys[++yn]=y[i]-s,ys[++yn]=y[i]+s+1;
	sort(ys+1,ys+1+yn); yn=unique(ys+1,ys+1+yn)-ys-1;
	int tot=ys[yn]-ys[1]; on=0;
	for(int i=1;i<=n;++i)
	{
		int L=lower_bound(ys+1,ys+1+yn,y[i]-s)-ys,
		R=lower_bound(ys+1,ys+1+yn,y[i]+s+1)-ys;
		os[++on]=mp(x[i]-s,mp(pii(L,R-1),1));
		os[++on]=mp(x[i]+s+1,mp(pii(L,R-1),-1));
	}
	sort(os+1,os+1+on);
	for(int i=1;i<=M+M;++i) seg[i]=pii(0,0),tg[i]=0;
	for(int i=1;i<yn;++i) seg[i+M]=pii(0,ys[i+1]-ys[i]);
	for(int i=M-1;i>=1;--i) seg[i]=seg[i+i]+seg[i+i+1];
	ll ans=0;
	for(int i=1;i<=on;++i)
		edt(1,os[i].se.fi.fi,os[i].se.fi.se,os[i].se.se),
		ans+=(tot-seg[1].se)*ll(os[i+1].fi-os[i].fi);
	return rss[s]=ans;
}
ll cd(int s)
{
	return calc(s)-calc(s-1);
}
const int MOD=998244353;
ll S1(ll x)
{return x*(x+1)/2%MOD;}
ll S2(ll x)
{
	ll t[]={x,x+1,2*x+1};
	for(int i=0;i<3;++i)
		if(t[i]%2==0) {t[i]/=2; break;}
	for(int i=0;i<3;++i)
		if(t[i]%3==0) {t[i]/=3; break;}
	return t[0]*(ll)t[1]%MOD*t[2]%MOD;
}
bool cp(ll l,ll r)
{
	if(l>=r) return 1;
	return cd(r)-cd(l)==(r-l)*(cd(l+1)-cd(l));
}
int main()
{
	for(int i=1;i<=M;++i) ls[i+M]=rs[i+M]=i;
	for(int i=M-1;i>=1;--i) ls[i]=ls[i+i],rs[i]=rs[i+i+1];
//	n=50,t=1e6;
	cin>>n>>t;
	for(int i=1;i<=n;++i)
//		x[i]=rand()*32+rand(),y[i]=rand()*32+rand();
		cin>>x[i]>>y[i];
//	ll aa=0;
//	for(int i=1;i<=t;++i) aa+=cd(i)*i,aa%=MOD;
//	cout<<aa<<"\n";
//	return 0;
	ll L=1,ans=0;
	while(L<=t)
	{
		if(L==t)
		{
			ans+=cd(L)%MOD*L;
			ans%=MOD;
			break;
		}
		ll u=cd(L+1)-cd(L);
		ll l=L+1,r=t;
		while(l<r)
		{
			ll m=(l+r+1)>>1;
			if(cd(m)-cd(m-1)!=u
			||(!cp(L,m))||(!cp(L,m-1))
			||(!cp(L,m-2))||(!cp(L,m-3)))
				r=m-1;
			else l=m;
		}
		ll b=cd(L),n=l-L;
		b%=MOD; u%=MOD;
		//(b+u*i)*(i+L)  i in [0,n]
		ans+=S2(n)*u+S1(n)*((u*L+b)%MOD)+L*b%MOD*(n+1);
		ans%=MOD;
		L=l+1;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}