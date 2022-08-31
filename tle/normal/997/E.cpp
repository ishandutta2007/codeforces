#pragma GCC optimize("-O3","-funroll-all-loops")
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
int n,p[SZ],q,ls[SZ],rs[SZ];
vector<int> v[SZ];
int s1[SZ],n1,s2[SZ],n2;
//sqrt-blocking works better than segment tree
const int S=350;
#define B S
typedef pair<ll,ll> pll;
inline pll operator + (pll a,pll b)
{
	if(!a.se) return b;
	if(!b.se) return a;
	if(a.fi<b.fi) return a;
	if(a.fi>b.fi) return b;
	return pll(a.fi,a.se+b.se);
}
ll x[SZ]; pll bmi[SZ],bmt[SZ],emi[SZ];
ll ba[SZ],bt[SZ];
void pd(int b)
{
	if(!bt[b]&&!bmt[b].se) return;
	bmi[b]=mp(8e18,0);
	for(int j=b*S;j<b*S+S;++j)
	{
		emi[j]=emi[j]+pll(bmt[b].fi+x[j],bmt[b].se);
		x[j]+=bt[b]; bmi[b]=bmi[b]+pll(x[j],1);
	}
	bmt[b]=mp(0,0); bt[b]=0;
}
void fedt(int b,int l,int r,int v)
{
	for(int j=max(b*S,l);j<b*S+S&&j<=r;++j) x[j]+=v;
	bmi[b]=mp(8e18,0);
	for(int j=b*S;j<b*S+S;++j)
		bmi[b]=bmi[b]+pll(x[j],1);
}
void edt(int l,int r,int x)
{
	pd(l/B),fedt(l/B,l,r,x);
	if(l/B!=r/B) pd(r/B),fedt(r/B,l,r,x);
	for(int s=l/B+1;s<r/B;++s)
		bt[s]+=x;
}
void pr()
{
	for(int s=0;s<=n/B;++s)
	{
		if(bmi[s].fi+bt[s]==-1) ba[s]+=bmi[s].se;
		bmt[s]=bmt[s]+pll(bt[s],1);
	}
}
ll qry(int l)
{
	int bl=l/B;
	pd(bl); ll ans=0;
	for(int t=l;t/B==bl;++t)
		ans+=(emi[t].fi==-1)?emi[t].se:0;
	for(int t=bl+1;t<=n/B;++t)
		ans+=ba[t];
	return ans;
}
ll ans[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
		scanf("%d%d",ls+i,rs+i),v[rs[i]].pb(i);
	//max-min-len>=0, required:=0
	for(int i=1;i<=n;++i)
	{
		while(n1&&p[s1[n1]]<p[i])
			edt(s1[n1-1]+1,s1[n1],p[i]-p[s1[n1]]),--n1;
		while(n2&&p[s2[n2]]>p[i])
			edt(s2[n2-1]+1,s2[n2],p[s2[n2]]-p[i]),--n2;
		s1[++n1]=i; s2[++n2]=i;
		edt(1,i,-1); pr();
		for(auto p:v[i])
			ans[p]=qry(ls[p]);
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
}