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
int n; Edg
int fa[SZ],dep[SZ],so[SZ],sz[SZ];
void dfs(int x,int f=0)
{
	fa[x]=f; dep[x]=dep[f]+1;
	sz[x]=1; so[x]=0;
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x);
		sz[x]+=sz[b]; if(sz[b]>sz[so[x]]) so[x]=b;
	}
}
int top[SZ],dfn[SZ],C,ed[SZ],rv[SZ];
void dfs2(int x,int t)
{
	top[x]=t; dfn[x]=++C; rv[C]=x;
	if(so[x]) dfs2(so[x],t);
	for esb(x,e,b)
		if(b!=fa[x]&&b!=so[x])
			dfs2(b,b);
	ed[x]=C;
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
		if(dep[top[x]]<dep[top[y]]) y=fa[top[y]];
		else x=fa[top[x]];
	if(dep[x]<dep[y]) return x; return y;
}
int jump(int x,int d)
{
	while(dep[top[x]]>d)
		x=fa[top[x]];
	return rv[dfn[x]-dep[x]+d];
}
vector<pii> dc(int x,int y)
{
	vector<pii> v;
	while(top[x]!=top[y])
		if(dep[top[x]]<dep[top[y]])
			v.pb(pii(dfn[top[y]],dfn[y])),y=fa[top[y]];
		else v.pb(pii(dfn[top[x]],dfn[x])),x=fa[top[x]];
	if(dep[x]>dep[y]) swap(x,y);
	v.pb(pii(dfn[y]-dep[y]+dep[x]+1,dfn[y]));
	return v;
}
int m,N,t[SZ][2];
pair<pii,pii> ps[SZ];
#define M M_
#define SS 16000000
namespace TJ
{
int M=0,fst[SS],vb[SS*3],nxt[SS*3];
void ad_de(int a,int b){if(a&&b);else return;++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}
bool ins[SS]; int ss[SS],sn,dfnn[SS],low[SS],CC=0,Z=0,bl[SS];
void tj(int x)
{
	ins[x]=1; ss[++sn]=x; dfnn[x]=low[x]=++CC;
	for esb(x,e,b)
	{
		if(!dfnn[b]) tj(b),low[x]=min(low[x],low[b]);
		else if(ins[b]) low[x]=min(low[x],dfnn[b]);
	}
	if(low[x]!=dfnn[x]) return;
	++Z;
	while(1)
	{
		int t=ss[sn--];
		bl[t]=Z; ins[t]=0;
		if(t==x) break;
	}
}
}
const int M=131072;
int ls[SZ],rs[SZ],ol[SZ],es[SZ];
void upd(int x)
{
	if(ol[x]||ol[x+x]||ol[x+x+1])
	{
	++N;
	TJ::ad_de(N,ol[x]);
	TJ::ad_de(N,ol[x+x]);
	TJ::ad_de(N,ol[x+x+1]);
	ol[x]=N;
	}
}
void edt(int x,int ql,int qr,int g)
{
	if(ql>qr||rs[x]<ql||qr<ls[x]) return;
	if(ql<=ls[x]&&rs[x]<=qr)
	{
		++N; TJ::ad_de(N,ol[x]);
		TJ::ad_de(N,g);ol[x]=N;
		++N; TJ::ad_de(N,es[x]);
		TJ::ad_de(N,g);es[x]=N;
		return;
	}
	edt(x+x,ql,qr,g);
	edt(x+x+1,ql,qr,g);
	upd(x);
}
void conn(int x,int ql,int qr,int g)
{
	if(ql>qr||rs[x]<ql||qr<ls[x]) return;
	TJ::ad_de(g,es[x]);
	if(ql<=ls[x]&&rs[x]<=qr)
	{
		TJ::ad_de(g,ol[x]);
		return;
	}
	conn(x+x,ql,qr,g);
	conn(x+x+1,ql,qr,g);
}
int br() {return rand()*32768+rand();}
int main()
{
	for(int i=1;i<=M;++i)
		ls[i+M]=rs[i+M]=i;
	for(int i=M-1;i>=1;--i)
		ls[i]=ls[i+i],rs[i]=rs[i+i+1]; 
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	/*
	n=1e5;
	for(int i=2;i<=n;++i) adde(i/2,i);*/
	dfs(1); dfs2(1,1);
//	m=1e4;
	scanf("%d",&m);
	N=1;
	for(int i=1;i<=m;++i)
		/*
		ps[i].fi.fi=65536,//br()%n+1,
		ps[i].fi.se=65535,//br()%n+1,
		ps[i].se.fi=65536,//br()%n+1,
		ps[i].se.se=65535,//br()%n+1,*/
		scanf("%d%d%d%d",&ps[i].fi.fi,&ps[i].fi.se,
		&ps[i].se.fi,&ps[i].se.se),
		t[i][0]=++N,t[i][1]=++N;
	for(int i=1;i<=m;++i)
	{
		vector<pii> A=dc(ps[i].fi.fi,ps[i].fi.se),
		B=dc(ps[i].se.fi,ps[i].se.se);
		for(auto tt:A)
			conn(1,tt.fi,tt.se,t[i][0]);
		for(auto tt:B)
			conn(1,tt.fi,tt.se,t[i][1]);
		for(auto tt:A)
			edt(1,tt.fi,tt.se,t[i][1]);
		for(auto tt:B)
			edt(1,tt.fi,tt.se,t[i][0]);
	}
	memset(ol,0,sizeof ol);
	memset(es,0,sizeof es);
	for(int i=m;i>=1;--i)
	{
		vector<pii> A=dc(ps[i].fi.fi,ps[i].fi.se),
		B=dc(ps[i].se.fi,ps[i].se.se);
		for(auto tt:A)
			conn(1,tt.fi,tt.se,t[i][0]);
		for(auto tt:B)
			conn(1,tt.fi,tt.se,t[i][1]);
		for(auto tt:A)
			edt(1,tt.fi,tt.se,t[i][1]);
		for(auto tt:B)
			edt(1,tt.fi,tt.se,t[i][0]);
	}
	if(N>=SS-10||TJ::M>=SS*3-10) throw "WTF";
//	cerr<<N<<" "<<TJ::M<<"\n";
	for(int i=1;i<=N;++i)
		if(!TJ::dfnn[i]) TJ::tj(i);
	for(int i=1;i<=m;++i)
		if(TJ::bl[t[i][0]]==TJ::bl[t[i][1]])
		{
			puts("NO"); return 0;
		}
	puts("YES");
	for(int i=1;i<=m;++i)
		if(TJ::bl[t[i][0]]>TJ::bl[t[i][1]])
			puts("2");
		else puts("1");
}