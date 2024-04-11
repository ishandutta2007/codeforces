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
int n,m,q,S,sz[SZ],se[SZ],ff[SZ]; Edg
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
void uni(int a,int b)
{
	int ga=gf(a),gb=gf(b);
	if(ga^gb) ff[ga]=gb;
}
bool gg[SZ];
#define U 20
int ea[SZ],eb[SZ],up[SZ][U],dep[SZ];
void dfs(int x,int f=0)
{
	up[x][0]=f; dep[x]=dep[f]+1;
	for(int i=1;i<U;i++) up[x][i]=up[up[x][i-1]][i-1];
	for esb(x,e,b) if(b!=f)
		dfs(b,x);
}
int lca(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);
	//dep[a]<=dep[b]
	for(int i=U-1;i>=0;--i)
		if(dep[up[b][i]]>=dep[a]) b=up[b][i];
	if(a==b) return a;
	for(int i=U-1;i>=0;--i)
		if(up[a][i]!=up[b][i]) a=up[a][i],b=up[b][i];
	return up[a][0];
}
int dis(int a,int b)
{
	return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
typedef pair<int,pii> qwq;
qwq zj[SZ]; int dj[SZ];
int qa[SZ],qb[SZ];
vector<int> ss[SZ];
vector<int> h0[SZ];
vector<ll> h1[SZ];
map<pii,ld> anss;
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	S=1e9;//if(n>1) S=sqrt(n/(log(n)/log(2))); ++S;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",ea+i,eb+i);
		uni(ea[i],eb[i]); adde(ea[i],eb[i]);
	}
	for(int i=1;i<=m;i++) ++se[gf(ea[i])];
	for(int i=1;i<=n;i++) ++sz[gf(i)];
	for(int i=1;i<=n;i++)
	{
		int g=gf(i); if(g!=i) continue;
		if(sz[g]!=se[g]+1) gg[g]=1;
		else dfs(g),h0[i].resize(sz[g]+1),h1[i].resize(sz[g]+1);
	}
	for(int i=1;i<=n;i++) ss[gf(i)].pb(i);
	for(int i=1;i<=n;i++) zj[i]=qwq(0,pii(i,i));
	for(int i=1;i<=n;i++)
	{
		int g=gf(i);
		if(gg[g]) continue;
		int a=zj[g].se.fi,b=zj[g].se.se;
		zj[g]=max(zj[g],qwq(dis(a,i),pii(a,i)));
		zj[g]=max(zj[g],qwq(dis(b,i),pii(b,i)));
	}
	for(int i=1;i<=n;i++)
	{
		int g=gf(i);
		if(gg[g]) continue;
		dj[i]=max(dis(zj[g].se.fi,i),dis(zj[g].se.se,i));
		++h0[g][dj[i]]; h1[g][dj[i]]+=dj[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(gf(i)!=i||gg[i]) continue;
		for(int j=sz[i]-1;j>=0;--j)
			h0[i][j]+=h0[i][j+1],h1[i][j]+=h1[i][j+1];
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",qa+i,qb+i);
		qa[i]=gf(qa[i]);qb[i]=gf(qb[i]);
		if(gg[qa[i]]||gg[qb[i]]||qa[i]==qb[i])
			puts("-1");
		else
		{
			if(pii(sz[qa[i]],qa[i])>pii(sz[qb[i]],qb[i])) swap(qa[i],qb[i]);
			if(anss.count(pii(qa[i],qb[i])))
			{
				printf("%.10lf\n",anss[pii(qa[i],qb[i])]);
				continue;
			}
			//sz[qa[i]]<=sz[qb[i]]
			//dj[a]+dj[b]>=max(zj[qa[i]],zj[qb[i]])-1
			int mx=max(zj[qa[i]].fi,zj[qb[i]].fi)-1;
			ll c1=0,c0=0;
			for(auto a:ss[qa[i]])
			{
				int geq=mx-dj[a];
				if(geq<0) geq=0; if(geq>=sz[qb[i]]) geq=sz[qb[i]];
				ll g0=h0[qb[i]][geq],g1=h1[qb[i]][geq];
				c0+=g0; c1+=g1+g0*(dj[a]+1);
			}
			c0=sz[qa[i]]*ll(sz[qb[i]])-c0;
			c1+=c0*(mx+1);
			ld ans=c1/ld(sz[qa[i]])/ld(sz[qb[i]]);
			printf("%.10lf\n",anss[pii(qa[i],qb[i])]=ans);
		}
	}
}