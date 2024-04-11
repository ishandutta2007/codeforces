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
#include<bits/stdc++.h>
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
int n,k,m,x[SZ];
ll lt[SZ];
struct cmp
{
bool operator () (int a,int b)
{
	return (lt[a]!=lt[b])?(lt[a]<lt[b]):(a<b);
}
}cc;
set<int,cmp> ca[SZ];
multiset<int> cb;
set<pair<ll,pii> > eve;
int main()
{
	ca[0].insert(0);
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=k;++i)
	{
		scanf("%d",x+i);
		assert(1<=x[i]&&x[i]<=n);
		ca[x[i]].insert(i);
		cb.insert(x[i]);
	}
	ll last=0;
	for(int i=1;i<=m;++i)
	{
		ll t; int a,b;
		scanf("%lld%d%d",&t,&a,&b); ll t_=t;
		assert(t>last);last=t;
		assert(1<=a&&a<=n);
		assert(1<=b&&b<=n);
		assert(a!=b);
		while(cb.empty()||(eve.size()&&eve.begin()->fi<=t))
		{
			auto g_=eve.begin();
			auto g=*g_;
			eve.erase(g_);
			ll tim=g.fi,car=g.se.fi,pos=g.se.se;
			x[car]=pos; t=max(t,tim);
			lt[car]=tim; cb.insert(pos);
			ca[pos].insert(car);
		}
		auto tmp=cb.lower_bound(a);
		int f1=0,f2=0,d1=0,d2=0;
		if(tmp!=cb.end()) f1=*tmp;
		if(tmp!=cb.begin()) f2=*(--tmp);
		d1=abs(f1-a); d2=abs(f2-a);
		if(!f1) d1=1e9; if(!f2) d2=1e9;
		int c1=*ca[f1].begin(),c2=*ca[f2].begin();
		int p;
		if(d1==d2) p=(cc(c1,c2))?c1:c2;
		else if(d1<d2) p=c1; else p=c2;
		int q=x[p];
		cb.erase(cb.find(q));
		t=max(t,lt[p]);
		ca[q].erase(p); t+=min(d1,d2);
		eve.insert(make_pair(t+abs(b-a),pii(p,b)));
		printf("%d %lld\n",p,t-t_);
	}
}