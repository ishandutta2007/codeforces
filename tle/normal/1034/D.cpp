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
int n,k,a[SZ],b[SZ];
map<pii,int> odt;
void spl(int t)
{
	auto g=odt.lower_bound(pii(t+1,-1)); --g;
	pair<pii,int> u=*g;
	if(u.fi.fi==t) return;
	odt.erase(g);
	odt[pii(u.fi.fi,t-1)]=u.se;
	odt[pii(t,u.fi.se)]=u.se;
}
vector<pair<pii,int> > es[SZ];
ll dt[SZ];
pair<ll,ll> f(int t)
{
	ll s0=0,s1=0,c1=0,cur=0; int p=1;
	for(int i=1;i<=n;++i) dt[i]=0;
	for(int i=1;i<=n;++i)
	{
		for(auto t:es[i])
		{
			if(t.fi.se<p)
				c1+=t.se*(ll)(t.fi.se-t.fi.fi+1);
			else if(t.fi.fi>p)
				dt[t.fi.fi]+=t.se,
				dt[t.fi.se+1]-=t.se;
			else
				cur+=t.se,dt[t.fi.se+1]-=t.se,
				c1+=t.se*(ll)(p-t.fi.fi+1);
		}
		while(cur>t)
			cur+=dt[++p],c1+=cur;
		s0+=p-1; s1+=c1-cur;
	}
	return mp(s0,s1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d",a+i,b+i),--b[i];
	odt[pii(0,n+1)]=0;
	for(int i=1;i<=n;++i)
	{
		spl(a[i]); spl(b[i]+1);
		auto g=odt.lower_bound(pii(a[i],0));
		while(g->fi.fi<=b[i])
			es[i].pb(mp(pii(g->se+1,i),g->fi.se-g->fi.fi+1)),
			odt.erase(g++);
		odt[pii(a[i],b[i])]=i;
	}
	int l=0,r=1e9;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(f(m).fi<=k) r=m; else l=m+1;
	}
	pair<ll,ll> u=f(l);
	cout<<u.se+(k-u.fi)*(ll)l<<"\n";
}