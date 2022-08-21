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
#define SZ 1009999
int n,k,m,ea[SZ],eb[SZ]; Edgc
int ff[SZ],gg[SZ];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
int gx(int x) {return gg[x]?gg[x]=gx(gg[x]):x;}
#define U 20
int fe[SZ],fa[SZ],vis[SZ],up[SZ][U],dep[SZ];
void dfs(int x,int f=0)
{
	dep[x]=dep[f]+1; up[x][0]=f;
	for(int i=1;i<U;++i)
		up[x][i]=up[up[x][i-1]][i-1];
	fa[x]=f; vis[x]=1;
	for esb(x,e,b) if(b!=f)
	{
		if(vc[e]) fe[b]=2e9;
		dfs(b,x);
	}
}
inline int jump(int x,int d)
{
	for(int j=U-1;j>=0;--j)
		if(dep[up[x][j]]>=d) x=up[x][j];
	return x;
}
inline int lca(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	y=jump(y,dep[x]);
	if(x==y) return x;
	for(int j=U-1;j>=0;--j)
		if(up[x][j]!=up[y][j])
			x=up[x][j],y=up[y][j];
	return up[x][0];
}
int aa[SZ],bb[SZ],cc[SZ];
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",ea+i,eb+i);
		int ga=gf(ea[i]),gb=gf(eb[i]);
		if(ga^gb) ff[ga]=gb;
		adde(ea[i],eb[i],1);
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",aa+i,bb+i,cc+i);
		int ga=gf(aa[i]),gb=gf(bb[i]);
		if(ga==gb) continue;
		ff[ga]=gb; adde(aa[i],bb[i],0);
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]) dfs(i);
	for(int i=1;i<=m;++i)
	{
		int a=aa[i],b=bb[i],c=cc[i];
		int l=lca(a,b);
		for(int t=gx(a);dep[t]>dep[l];)
			fe[t]=min(fe[t],c),gg[t]=fa[t],t=gx(t);
		for(int t=gx(b);dep[t]>dep[l];)
			fe[t]=min(fe[t],c),gg[t]=fa[t],t=gx(t);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
		if(fe[i]>1.1e9) {ans=-1; break;}
		else ans+=fe[i];
	cout<<ans<<"\n";
}