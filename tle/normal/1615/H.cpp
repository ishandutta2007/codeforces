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
#include <assert.h>
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

int N,S,T,M=1; //M=1 is important!!
int fst[SZ],vb[SZ],nxt[SZ]; ll vc[SZ];
void ad_de_(int a,int b,ll c)
{++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}
void ad_de(int a,int b,ll c){ad_de_(a,b,c);ad_de_(b,a,0);}
int d[SZ],ff[SZ];
bool bfs() {
	static int qs[SZ]; int h=0,t=0;
	memset(d,-1,sizeof(int)*(N+1));
	qs[t++]=S; d[S]=0;
	while(h^t) {
		int x=qs[h++];
		for esb(x,e,b) {
			if((~d[b])||!vc[e]) continue;
			d[b]=d[x]+1; qs[t++]=b;
		}
	}
	return d[T]!=-1;
}
ll dfs(int x,ll u) {
	if(x==T||!u) return u;
	ll f=0;
	for(int&e=fst[x];e;e=nxt[e]) {
		int b=vb[e];
		if(d[b]!=d[x]+1) continue;
		ll s=dfs(vb[e],min(u-f,(ll)vc[e]));
		f+=s; vc[e]-=s; vc[e^1]+=s;
		if(f==u) break;
	}
	if(!f) d[x]=-1;
	return f;
}
ll dinic() {
	ll ans=0;
	memcpy(ff,fst,sizeof(int)*(N+1));
	while(bfs())
		ans+=dfs(S,1e18),
		memcpy(fst,ff,sizeof(int)*(N+1));
	return ans;
}

int n,m,a[SZ],es[SZ];
vector<int> edg[SZ];
ll dt[SZ];
bool vis[SZ];
void fz(int l,int r) {
	if(l==r) return;
	vector<int> ans;
	for(int i=1;i<=n;++i) {
		if(l<=es[i]&&es[i]<=r)
			ans.pb(i);
	}
	if(!ans.size()) return;
//	cerr<<l<<"~"<<r<<"\n";
	int m=(l+r)>>1;
	M=1;
	for(int i=1;i<=n;++i) fst[i]=0;
	S=n+1,T=n+2; N=T;
//	cout<<"mid:"<<m<<"\n";
	for(auto i:ans) {
		ll s0=abs(a[i]-m),
		s1=abs(a[i]-m-1);
		dt[i]=s0-s1;
//		cerr<<i<<":"<<dt[i]<<"\n";
		if(dt[i]>0) ad_de(S,i,dt[i]);
		else ad_de(i,T,-dt[i]);
	}
	for(auto i:ans)
		for(auto b:edg[i]) if(l<=es[b]&&es[b]<=r) {
//			cerr<<i<<"->"<<b<<"\n";
			ad_de(i,b,1e18);
		}
	ll d=dinic();
//	cerr<<"GG:"<<d<<"\n";
	for(auto i:ans) vis[i]=0;
	bfs();
//	for(int i=1;i<=N;++i)
//		cout<<i<<": "<<::d[i]<<"\n";
	for(auto i:ans)
		if(::d[i]==-1) es[i]=m; else es[i]=m+1;
	fst[S]=fst[T]=0;
	for(auto i:ans) fst[i]=0;
	fz(l,m);
	fz(m+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	int mi=2e9,mx=-2e9;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),
		mi=min(mi,a[i]),mx=max(mx,a[i]);
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),
		edg[a].pb(b);
	for(int i=1;i<=n;++i) es[i]=mi;
	fz(mi,mx);
	for(int i=1;i<=n;++i)
		printf("%d ",es[i]);
	puts("");
}