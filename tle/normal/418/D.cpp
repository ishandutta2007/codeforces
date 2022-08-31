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
#define U 20
int n,sz[SZ],dep[SZ],up[100099][U],son[SZ],top[SZ]; Edg
int d1[SZ],D=0,d2[SZ],rv[SZ];
int mn=0,l2[SZ];
pii mi[200055][U]; int fv[SZ];
void dfs1(int x,int f=0)
{
	d1[x]=++D; rv[D]=x;
	up[x][0]=f;
	for(int i=1;i<U;++i)
		up[x][i]=up[up[x][i-1]][i-1];
	dep[x]=dep[f]+1;
	fv[x]=++mn;
	mi[mn][0]=pii(dep[x],x);
	sz[x]=1;
	for esb(x,e,b) if(b!=f)
	{
		dfs1(b,x),sz[x]+=sz[b];
		if(sz[b]>sz[son[x]])
			son[x]=b;
		mi[++mn][0]=pii(dep[x],x);
	}
	d2[x]=D;
}
int jump(int a,int d)
{
	for(int i=U-1;i>=0;--i)
		if(dep[up[a][i]]>=d)
			a=up[a][i];
	return a;
}
int lca_(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);
	b=jump(b,dep[a]);
	if(a==b) return a;
	for(int i=U-1;i>=0;--i)
		if(up[a][i]!=up[b][i])
			a=up[a][i],b=up[b][i];
	return up[a][0];
}
int lca(int a,int b)
{
//	cout<<a<<","<<b<<"!";
//	int ab=lca_(a,b);
	a=fv[a],b=fv[b];
	if(a>b) swap(a,b);
	int g=l2[b-a+1];
	int aa=min(mi[a][g],mi[b-(1<<g)+1][g]).se;
//	cout<<" lca="<<min(mi[a][g],mi[b-(1<<g)+1][g]).se<<"   "<<a<<","<<b<<","<<g<<"\n";
//	if(aa!=ab)
//	{
//		system("pause");
//	}
	return aa;
}
int dis(int a,int b)
{
	if(a==0||b==0) return -1;
	return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
struct zj
{
int a,b,d;
zj(){a=b=0; d=-1;}
zj(int p,int q)
{
	a=p,b=q,d=dis(p,q);
}
};
bool operator < (zj a,zj b)
{
	return a.d<b.d;
}
zj operator + (zj a,zj b)
{
	zj s=max(a,b);
	s=max(s,zj(a.a,b.a));
	s=max(s,zj(a.a,b.b));
	s=max(s,zj(a.b,b.a));
	s=max(s,zj(a.b,b.b));
	return s;
}
#define M M_
const int M=131072;
zj seg[SZ];
int qryd(int l,int r,int uv)
{
	if(l>r) return 0;
	zj u;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) u=u+seg[l^1];
		if(r&1) u=u+seg[r^1];
	}
	return max(dis(u.a,uv),dis(u.b,uv));
}
int m;
int main()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)
	{
		scanf("%d%d",&a,&b);
		adde(a,b);
	}
	dfs1(1);
	for(int i=1;i<U;++i)
		for(int j=1;j+(1<<(i-1))<=n+n;++j)
			mi[j][i]=min(mi[j][i-1],mi[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=n+n;++i)
	{
		while((1<<l2[i])<=i) ++l2[i];
		--l2[i];
	}
	for(int i=1;i<=n;++i)
		seg[M+d1[i]]=zj(i,i);
	for(int i=M-1;i>=1;--i)
		seg[i]=seg[i+i]+seg[i+i+1];
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int l=lca(a,b);
		//a--l--b
		int td=dep[l]-dep[a]+dep[l]-dep[b];
		td=-td;
		int sb=(td-1)/2;
		int d11=dep[l]-dep[a];
		int ans=0;
		if(sb<-d11)
		{
			int w=jump(a,dep[a]-sb);
			//subtree w: a
			//all-subtree w: b
			ans=max(ans,qryd(d1[w],d2[w],a));
			ans=max(ans,qryd(1,d1[w]-1,b));
			ans=max(ans,qryd(d2[w]+1,n,b));
		}
		else
		{
			int w=jump(b,dep[b]-sb);
			//subtree w: b
			//all-subtree w: a
			ans=max(ans,qryd(d1[w],d2[w],b));
			ans=max(ans,qryd(1,d1[w]-1,a));
			ans=max(ans,qryd(d2[w]+1,n,a));
		}
		printf("%d\n",ans);
	}
}