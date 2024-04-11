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
#define SZ 2222222
int n,r;
pii p[SZ];
int ls[SZ],ln;
const int M=1048576;
int tg[SZ],mx[SZ];
void pd(int x)
{
	if(!tg[x]) return;
	mx[x]+=tg[x];
	if(x<=M)
		tg[x+x]+=tg[x],
		tg[x+x+1]+=tg[x];
	tg[x]=0;
}
void upd(int x)
{
	pd(x+x); pd(x+x+1);
	mx[x]=max(mx[x+x],mx[x+x+1]);
}
void add(int x,int l,int r,int ql,int qr,int v)
{
	if(r<ql||qr<l) return;
	if(ql<=l&&r<=qr)
	{
		tg[x]+=v; return;
	}
	int m=(l+r)>>1;
	add(x+x,l,m,ql,qr,v);
	add(x+x+1,m+1,r,ql,qr,v);
	upd(x);
}
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&p[i].fi,&p[i].se);
		int x=p[i].fi+p[i].se,
		y=p[i].fi-p[i].se;
		ls[++ln]=y-r;
		ls[++ln]=y+r+1;
	}
	sort(ls+1,ls+1+ln);
	map<int,vector<pair<pii,int>> > ms;
	for(int i=1;i<=n;++i)
	{
		int x=p[i].fi+p[i].se,
		y=p[i].fi-p[i].se;
		#define LS(t) (lower_bound(ls+1,ls+1+ln,t)-ls)
		int L=LS(y-r),R=LS(y+r+1)-1;
		ms[x-r].pb(mp(pii(L,R),1));
		ms[x+r+1].pb(mp(pii(L,R),-1));
	}
	int ans=0;
	for(auto g:ms)
	{
		for(auto r:g.se)
			add(1,0,M-1,r.fi.fi,r.fi.se,r.se);
		ans=max(ans,mx[1]);
	}
	printf("%d\n",ans);
}