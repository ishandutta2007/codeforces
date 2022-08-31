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
#define SZ 233333
#define P 20
int n,m,a[SZ],fst[SZ],vb[SZ],nxt[SZ],as[SZ],M=0,fa[SZ];
void ad_de(int a,int b) {++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
int cc=0,st[SZ],ed[SZ],dfx[SZ];
void dfs(int x)
{
    st[x]=++cc; dfx[cc]=x;
    for(int e=fst[x];e;e=nxt[e])
    {
        int b=vb[e]; if(b==fa[x]) continue;
        fa[b]=x; dfs(b);
    }
    ed[x]=++cc; dfx[cc]=x;
}
typedef pair<int,int> pii;
int cc_=0,app[SZ],dep[SZ],lo2[SZ];
pii pp[SZ],minn[200099][P];
void dfs_(int x)
{
    ++cc_; app[x]=cc_; pp[cc_]=pii(dep[x],x);
    for(int e=fst[x];e;e=nxt[e])
    {
        int b=vb[e]; if(b==fa[x]) continue;
        dep[b]=dep[x]+1; dfs_(b);
        pp[++cc_]=pii(dep[x],x);
    }
}
void build()
{
    for(int i=1;i<=cc_;i++) minn[i][0]=pp[i];
    for(int i=1;i<=cc_;i++)
    {
        int g=0;
        while((1<<g)<=i) ++g;
        lo2[i]=g-1;
    }
    for(int p=1;p<P;p++)
    {
        for(int i=1;i<=cc_;i++)
        {
            if(i+(1<<p)-1>cc_) break;
            minn[i][p]=min(minn[i][p-1],minn[i+(1<<(p-1))][p-1]);
        }
    }
}
int lca(int a,int b)
{
    a=app[a]; b=app[b];
    if(a>b) swap(a,b);
    int l2=lo2[b-a+1];
    return min(minn[a][l2],minn[b-(1<<l2)+1][l2]).second;
}
int bs,qn=0;
struct query {int l,r,m,id;} qs[SZ];
bool operator < (query a,query b)
{
    if(a.l/bs!=b.l/bs) return a.l/bs<b.l/bs;
    else if((a.l/bs)&1) return a.r<b.r;
    return a.r>b.r;
}
#define Addq(l_,r_,m_,id_) ++qn, qs[qn].l=l_, qs[qn].r=r_, qs[qn].m=m_, qs[qn].id=id_;
int typ[SZ],cov[SZ];
ll cnt[2][SZ];
ll ans=0,anss[SZ];
void edt(int p)
{
	cov[p]^=1;
	int k=(cov[p])?1:(-1),t=typ[p];
	cnt[t][a[p]]+=k;
	ans+=cnt[!t][a[p]]*k;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",typ+i);
    for(int i=1;i<=n;i++) scanf("%d",a+i), as[i]=a[i];
    sort(as+1,as+1+n); int nn=unique(as+1,as+1+n)-as-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(as+1,as+1+nn,a[i])-as;
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adde(a,b);
    }
    dfs(1); dfs_(1); build(); scanf("%d",&m);
	bs=n/sqrt(m/3.0)+1; bs=max(bs,1);
    for(int i=1;i<=m;i++)
    {
        int a,b,p;
        scanf("%d%d",&a,&b);
        p=lca(a,b);
        if(st[a]>st[b]) swap(a,b);
        if(p==a) Addq(st[a],st[b],0,i)
        else Addq(ed[a],st[b],p,i)
    }
    sort(qs+1,qs+1+qn);
    int l=1,r=0;
    for(int i=1;i<=qn;i++)
    {
        int ql=qs[i].l,qr=qs[i].r;
        while(l>ql) edt(dfx[--l]);
        while(r<qr) edt(dfx[++r]);
        while(l<ql) edt(dfx[l++]);
        while(r>qr) edt(dfx[r--]);
        if(qs[i].m) edt(qs[i].m);
        anss[qs[i].id]=ans;
        if(qs[i].m) edt(qs[i].m);
    }
    for(int i=1;i<=m;i++) printf("%lld\n",anss[i]);
}