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
#define SZ 2312313
int n,q,fa[SZ],fv[SZ];
ll dep[SZ];
const int M=1048576;
int ls[SZ],rs[SZ];
ll tg[SZ],mi[SZ];
void pd(int x)
{
	if(!tg[x]) return;
	mi[x]+=tg[x];
	if(x<=M)
		tg[x+x]+=tg[x],
		tg[x+x+1]+=tg[x];
	tg[x]=0;
}
void upd(int x)
{
	pd(x+x); pd(x+x+1);
	mi[x]=min(mi[x+x],mi[x+x+1]);
}
ll qry(int x,int l,int r)
{
	if(rs[x]<l||r<ls[x]) return 1e18;
	pd(x); if(l<=ls[x]&&rs[x]<=r) return mi[x];
	return min(qry(x+x,l,r),qry(x+x+1,l,r));
}
void edt(int x,int l,int r,ll v)
{
	if(rs[x]<l||r<ls[x]) return;
	pd(x);
	if(l<=ls[x]&&rs[x]<=r)
	{
		tg[x]+=v;
		return;
	}
	edt(x+x,l,r,v);
	edt(x+x+1,l,r,v);
	upd(x);
}
vector<int> son[SZ];
int L[SZ],R[SZ];
int v[SZ],l[SZ],r[SZ];
vector<int> ss[SZ];
ll ans[SZ];
void go(int x)
{
	L[x]=1e9; R[x]=-1e9;
	if(!son[x].size()) L[x]=R[x]=x;
	for(auto s:son[x])
	{
		dep[s]=dep[x]+fv[s]; go(s);
		L[x]=min(L[x],L[s]);
		R[x]=max(R[x],R[s]);
	}
}
ll tt=0;
void go2(int x)
{
	for(auto t:ss[x])
		ans[t]=qry(1,l[t],r[t])+tt;
	for(auto s:son[x])
	{
		tt+=fv[s];
		edt(1,L[s],R[s],-fv[s]*2LL);
		go2(s);
		tt-=fv[s];
		edt(1,L[s],R[s],fv[s]*2LL);
	}
}
int main()
{
	memset(mi,127/3,sizeof mi);
	for(int i=1;i<=M;++i) ls[i+M]=rs[i+M]=i;
	for(int i=M-1;i>=1;--i)
		ls[i]=ls[i+i],rs[i]=rs[i+i+1];
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;++i)
		scanf("%d%d",fa+i,fv+i),son[fa[i]].pb(i);
	for(int i=1;i<=q;++i)
		scanf("%d%d%d",v+i,l+i,r+i),ss[v[i]].pb(i);
	go(1);
	for(int i=1;i<=n;++i)
		if(!son[i].size()) mi[i+M]=dep[i];
	for(int i=M-1;i>=1;--i) upd(i);
	go2(1);
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
}