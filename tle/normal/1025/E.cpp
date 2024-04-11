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
int n,m,dx[]={-1,1,0,0},dy[]={0,0,-1,1};
pii ps[SZ];
pair<pii,int> a[SZ],b[SZ]; int pn;
typedef vector<pair<pii,pii> > vp;
int tg[SZ],cp[SZ],p1[SZ],p2[SZ];
bool my_cmp(pair<pii,int> a_,pair<pii,int> b_)
{
	auto a=a_,b=b_;
	if(a.fi.fi!=1) a.fi.se=n+1-a.fi.se;
	if(b.fi.fi!=1) b.fi.se=n+1-b.fi.se;
	return a<b;
}
vp work()
{
	vp v,r;
	for(int i=1;i<=m;++i)
	{
		pii S=a[i].fi;
		while(S.fi>2)
			v.pb(mp(S,pii(S.fi-1,S.se))),--S.fi;
		while(S.se<i)
			v.pb(mp(S,pii(S.fi,S.se+1))),++S.se;
		if(S.fi!=1)
		v.pb(mp(S,pii(S.fi-1,S.se))),--S.fi;
		while(S.se>i)
			v.pb(mp(S,pii(S.fi,S.se-1))),--S.se;
		p1[i]=a[i].se;
	}
	for(int i=1;i<=m;++i)
		p2[i]=b[i].se;
	for(int i=1;i<=m;++i)
	{
		if(p1[i]==p2[i]) continue;
		int g=0;
		for(int j=i;j<=m;++j)
			if(p1[j]==p2[i]) g=j;
		v.pb(mp(mp(1,g),mp(2,g)));
		for(int j=g-1;j>=i;--j)
			v.pb(mp(mp(1,j),mp(1,j+1))),
			v.pb(mp(mp(2,j+1),mp(2,j)));
		v.pb(mp(mp(2,i),mp(1,i)));
		int t=p1[g];
		for(int j=g-1;j>=i;--j)
			p1[j+1]=p1[j];
		p1[i]=t;
	}
	for(int i=1;i<=m;++i)
	{
		pii S=b[i].fi;
		while(S.fi>2)
			r.pb(mp(S,pii(S.fi-1,S.se))),--S.fi;
		while(S.se<i)
			r.pb(mp(S,pii(S.fi,S.se+1))),++S.se;
		if(S.fi!=1)
		r.pb(mp(S,pii(S.fi-1,S.se))),--S.fi;
		while(S.se>i)
			r.pb(mp(S,pii(S.fi,S.se-1))),--S.se;
	}
	reverse(r.begin(),r.end());
	for(auto&g:r)
		swap(g.fi,g.se),v.pb(g);
	return v;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=m;++i)
		scanf("%d%d",&a[i].fi.fi,&a[i].fi.se),a[i].se=i;
	for(int i=1;i<=m;++i)
		scanf("%d%d",&b[i].fi.fi,&b[i].fi.se),b[i].se=i;
	sort(a+1,a+1+m,my_cmp);
	sort(b+1,b+1+m,my_cmp);
	vp t1=work();
	for(int i=1;i<=m;++i)
		a[i].fi.fi=n+1-a[i].fi.fi;
	for(int i=1;i<=m;++i)
		b[i].fi.fi=n+1-b[i].fi.fi;
	sort(a+1,a+1+m,my_cmp);
	sort(b+1,b+1+m,my_cmp);
	vp t2=work();
	for(auto&t:t2)
		t.fi.fi=n+1-t.fi.fi,
		t.se.fi=n+1-t.se.fi;
	if(t1.size()>t2.size()) t1=t2;
	printf("%d\n",int(t1.size()));
	for(auto t:t1)
		printf("%d %d %d %d\n",t.fi.fi,t.fi.se,t.se.fi,t.se.se);
}