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
typedef long long ll;
int fst[SZ],nxt[SZ],vb[SZ],ff[SZ],M=1,N=0;
#define ad_de ad_dl
ll cap[SZ];
void _ad_dl(int a,int b,ll c)
{++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;cap[M]=c;}
void ad_dl(int a,int b,ll c)
{_ad_dl(a,b,c); _ad_dl(b,a,0);}
#define d d_
int S,T,q[SZ],d[SZ];
bool bfs()
{
	memset(d,-1,4*(N+1));
	d[T]=0; q[1]=T; int h=1,t=2;
	while(h!=t)
	{
		int cur=q[h++];
		for(int e=fst[cur];e;e=nxt[e])
		{
			int b=vb[e];
			if(d[b]==-1&&cap[e^1])
			{
				d[b]=d[cur]+1, q[t++]=b;
				if(b==S) return 1;
			}
		}
	}
	return d[S]!=-1;
}
ll dfs(int x,ll f)
{
	if(f<=0) return 0;
	if(x==T) return f;
	ll ca=0;
	for(int& e=fst[x];e;e=nxt[e])
	{
		int b=vb[e];
		if(d[b]+1!=d[x]) continue;
		ll w=dfs(b,(cap[e]<f-ca)?cap[e]:(f-ca));
		cap[e]-=w; cap[e^1]+=w; ca+=w;
		if(ca==f) break;
	}
	if(!ca) d[x]=-1;
	return ca;
}
ll dinic()
{
	ll ans=0;
	memcpy(ff,fst,4*(N+1));
	while(bfs())
		ans+=dfs(S,2e18), memcpy(fst,ff,4*(N+1));
	return ans;
}
#undef d
const ll G=1.01e7;
int n,e,u[SZ],v[SZ],a[SZ],b[SZ],c[SZ],d[SZ];
ll ds[SZ];
ll f(ll x)
{
	for(int i=1;i<=N;++i) fst[i]=ds[i]=0;
	N=n; S=++N; T=++N; M=1;
	for(int i=1;i<=e;++i)
	{
		ll L=a[i]*x+b[i]*G,R=c[i]*x+d[i]*G;
		ad_de(u[i],v[i],R-L); ds[v[i]]+=L; ds[u[i]]-=L;
	}
	ll sb=0;
	for(int i=1;i<=N;++i)
		if(ds[i]>0) ad_de(S,i,ds[i]),sb+=ds[i];
		else if(ds[i]<0) ad_de(i,T,-ds[i]);
	ll aa=sb-dinic();
	return aa;
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;++i)
		cin>>u[i]>>v[i]>>a[i]>>b[i]>>c[i]>>d[i];
	ll l=0,r=G;
	while(r-l>10)
	{
		ll m1=l+(r-l)/3,m2=r-(r-l)/3;
		if(f(m1)<f(m2)) r=m2; else l=m1;
	}
	pair<ll,ll> mi(8e18,8e18);
	for(ll t=l;t<=r;++t)
		mi=min(mi,mp(f(t),t));
	if(mi.fi)
	{
		puts("0");
		return 0;
	}
	l=mi.se,r=G;
	while(l<r)
	{
		ll m=(l+r+1)>>1;
		if(f(m)) r=m-1; else l=m;
	}
	ll ans=l;
	l=0,r=mi.se;
	while(l<r)
	{
		ll m=(l+r)>>1;
		if(f(m)) l=m+1; else r=m;
	}
	ans-=l;
	printf("%.10lf\n",ans/ld(G));
}