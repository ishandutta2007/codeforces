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
vector<pii> A,B; pii g;
pii operator + (pii a,pii b)
{return pii(a.fi+b.fi,a.se+b.se);}
pii operator - (pii a,pii b)
{return pii(a.fi-b.fi,a.se-b.se);}
ll operator * (pii a,pii b)
{return a.fi*(ll)b.se-a.se*(ll)b.fi;}
ll len(pii x) {return x.fi*(ll)x.fi+x.se*(ll)x.se;}
long double t1[SZ];
pii t2[SZ];
ll t3[SZ];
int id[SZ];
long double ang(pii t)
{return atan2l(t.se,t.fi);}
pii yf(pii x)
{
	if(x.fi||x.se);else return x;
	int g=__gcd(x.fi,x.se);
	if(g<0) g=-g;
	x.fi/=g; x.se/=g;
	return x;
}
bool cmp_g(int a,int b)
{
	if(t2[a]!=t2[b])
		return t1[a]<t1[b];
	return t3[a]<t3[b];
}
ll cross(pii p0,pii p1,pii p2)
{return (p1-p0)*(p2-p0);}
vector<pair<pii,int> > graham(vector<pair<pii,int> > v)
{
	vector<pair<pii,int> > s; g=pii(2e9,2e9);
	for(auto r:v) g=min(g,r.fi);
	vector<pair<pii,int> > _;_.resize(v.size());
	for(int i=0;i<v.size();++i)
	{
		id[i]=i;
		t2[i]=v[i].fi-g;
		if(t2[i].fi||t2[i].se)
			t1[i]=ang(t2[i]);
		else t1[i]=-1e18;
		t3[i]=len(t2[i]);
		t2[i]=yf(t2[i]);
	}
	sort(id,id+v.size(),cmp_g);
	for(int i=0;i<v.size();++i) _[i]=v[id[i]];
	v=_; v.erase(unique(v.begin(),v.end()),v.end());
	pair<pii,int> st[SZ]; int sn=0;
	for(auto x:v)
	{
		while(sn>=2&&(x.fi-st[sn-1].fi)*
		(st[sn].fi-st[sn-1].fi)>=0) --sn;
		st[++sn]=x;
	}
	for(int i=1;i<=sn;++i)
		s.pb(st[i]);
	return s;
}
bool in(pii a,pii b,pii c,pii z)
{
	return abs(cross(a,b,c))
	==abs(cross(a,b,z))
	+abs(cross(b,c,z))
	+abs(cross(a,c,z));
}
int n,x[SZ],y[SZ],c[SZ]; pii p[SZ];
vector<pair<pii,int> > v;
vector<pii> op;
void work(int a,int b,int c)
{
	for(int i=1;i<=n;++i)
		if(i!=a&&i!=b&&i!=c
		&&in(p[a],p[b],p[c],p[i])
		&&::c[c]==::c[i])
		{
			op.pb(pii(c,i));
			work(a,b,i);
			work(i,c,a);
			work(i,c,b);
			return;
		}
	for(int i=1;i<=n;++i)
		if(i!=a&&i!=b&&i!=c
		&&in(p[a],p[b],p[c],p[i]))
			op.pb(pii(a,i));
}
int main()
{
	scanf("%d",&n);
	bool as=1;
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",x+i,y+i,c+i),
		v.pb(mp(p[i]=pii(x[i],y[i]),i)),
		as&=c[i]==c[1];
	if(as)
	{
	    for(int i=1;i<n;++i)
	    	op.pb(pii(i,n));
	}
	else
	{
	v=graham(v);
	int dd=0,cc=0;
	for(int i=0;i<v.size();++i)
		if(c[v[i].se]!=c[v[(i+1)%v.size()].se])
			++dd,cc=(i+1)%v.size();
	if(dd>2)
	{
		puts("Impossible");
		return 0;
	}
	if(dd==0)
	{
		for(int i=0;i+1<v.size();++i)
			op.pb(pii(v[i].se,v[i+1].se));
		int t=-1;
		for(int i=1;i<=n;++i)
			if(c[i]!=c[v[0].se]) t=i;
		for(int i=0;i<v.size();++i)
			work(v[i].se,v[(i+1)%v.size()].se,t);
	}
	else
	{
		for(int i=0;i<v.size();++i)
			if(c[v[i].se]==c[v[(i+1)%v.size()].se])
				op.pb(pii(v[i].se,v[(i+1)%v.size()].se));
		vector<int> s[2];
		for(int i=0;i<v.size();++i)
		{
			int t=v[(i+cc)%v.size()].se;
			s[c[t]].pb(t);
		}
		for(int i=0;i+1<s[0].size();++i)
			work(s[0][i],s[0][i+1],s[1][0]);
		for(int i=0;i+1<s[1].size();++i)
			work(s[1][i],s[1][i+1],s[0][0]);
	}
	}
	printf("%d\n",int(op.size()));
	for(auto t:op)
		printf("%d %d\n",t.fi-1,t.se-1);
}