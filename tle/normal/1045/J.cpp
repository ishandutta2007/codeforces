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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define SZ 666666
#define W 103
#define U 20
int eu[100055][W];
int n,dep[SZ]; Edgc
const int MOD[2]={998244353,666623333};
ll po[2][SZ],f1[SZ],f2[SZ];
struct hh{int a,b,l;
ll hs()
{return a*(ll)MOD[1]+b+l*23333333LL;}
};
hh ehh(int x,int y)
{
	hh t; t.l=dep[y]-dep[x];
	t.a=(f1[y]-f1[x]*po[0][t.l])%MOD[0];
	if(t.a<0) t.a+=MOD[0];
	t.b=(f2[y]-f2[x]*po[1][t.l])%MOD[1];
	if(t.b<0) t.b+=MOD[1];
	return t;
}
hh operator + (hh a,hh b)
{
	hh c;
	c.a=(a.a*po[0][b.l]+b.a)%MOD[0];
	c.b=(a.b*po[1][b.l]+b.b)%MOD[1];
	c.l=a.l+b.l; return c;
}
int up[U][100055],fe[SZ];
void dfs(int x,int f=0)
{
	dep[x]=dep[f]+1;
	up[0][x]=f;
	for(int i=1;i<U;++i)
		up[i][x]=up[i-1][up[i-1][x]];
	eu[x][0]=x;
	for(int i=1;i<W;++i)
		eu[x][i]=eu[f][i-1];
	for esb(x,e,b) if(b!=f)
		fe[b]=vc[e]-'a'+1,
		f1[b]=(f1[x]*29+fe[b])%MOD[0],
		f2[b]=(f2[x]*29+fe[b])%MOD[1],
		dfs(b,x);
}
int jump(int x,int d)
{
	if(dep[x]==d) return x;
	for(int j=U-1;j>=0;--j)
		if(dep[up[j][x]]>=d) x=up[j][x];
	return x;
}
int lca(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);
	b=jump(b,dep[a]);
	if(a==b) return a;
	for(int j=U-1;j>=0;--j)
		if(up[j][a]!=up[j][b])
			a=up[j][a],b=up[j][b];
	return up[0][a];
}
__gnu_pbds::gp_hash_table<ll,int> h;
int q,ans[SZ],pn;
vector<pair<ll,int> > pool[400055];
int vs[W][100055];
vector<pair<ll,int> >&gp(int a,int b)
{
	if(!vs[a][b]) vs[a][b]=++pn;
	return pool[vs[a][b]];
}
int X; ll tmp[SZ];
void ddd(int t)
{
	if(eu[t][X])
		++h[tmp[t]=ehh(eu[t][X],t).hs()];
	for(auto p:pool[vs[X][t]])
	{
		if(p.se>0)
			ans[p.se]+=h[p.fi];
		else ans[-p.se]-=h[p.fi];
	}
	for esb(t,e,b) if(b!=up[0][t]) ddd(b);
	if(eu[t][X])
		--h[tmp[t]];
}
int main()
{
	po[0][0]=po[1][0]=1;
	for(int i=0;i<2;++i)
		for(int j=1;j<SZ;++j)
			po[i][j]=po[i][j-1]*29%MOD[i];
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)
	{
		char c[3];
		scanf("%d%d%s",&a,&b,c);
		adde(a,b,c[0]);
	}
	dfs(1);
	scanf("%d",&q);
	for(int ii=1;ii<=q;++ii)
	{
		int u,v;
		static char s[103];
		scanf("%d%d%s",&u,&v,s);
		if(u==v) continue;
		int sl=strlen(s);
		ll A,B;
		{
		hh w{0,0,0};
		for(int i=0;s[i];++i) s[i]=s[i]-'a'+1;
		for(int i=0;s[i];++i)
			w=w+hh{s[i],s[i],1};
		A=w.hs();
		w=hh{0,0,0};
		for(int i=0;s[i];++i)
			w=hh{s[i],s[i],1}+w;
		B=w.hs();
		}
		int l=lca(u,v);
		int uu=jump(u,min(dep[u],dep[l]+sl-1)),
		vv=jump(v,min(dep[v],dep[l]+sl-1));
		static int as[SZ],bs[SZ]; int an=0,bn=0;
		static hh aa[233],bb[233];
		for(int w=uu;w!=l;w=up[0][w]) as[++an]=(fe[w]);
		for(int w=vv;w!=l;w=up[0][w]) bs[++bn]=(fe[w]);
		reverse(bs+1,bs+1+bn);
		aa[an+1]=bb[0]=hh{0,0,0};
		for(int i=an;i>=1;--i)
			aa[i]=hh{as[i],as[i],1}+aa[i+1];
		for(int i=1;i<=bn;++i)
			bb[i]=bb[i-1]+hh{bs[i],bs[i],1};
		for(int p=1;p<=an;++p)
		{
			int qq=p+sl-an-1;
			if(qq>=1&&qq<=bn&&(aa[p]+bb[qq]).hs()==A) ++ans[ii];
		}
		if(u!=uu)
			gp(sl,uu).pb(mp(B,-ii)),
			gp(sl,u).pb(mp(B,ii));
		if(v!=vv)
			gp(sl,vv).pb(mp(A,-ii)),
			gp(sl,v).pb(mp(A,ii));
	}
	for(X=1;X<=100;++X)
		h.clear(), ddd(1);
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
}