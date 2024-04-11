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
int n,x[SZ],y[SZ];
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
vector<pii> graham(vector<pii> v)
{
	vector<pii> s; g=pii(2e9,2e9);
	for(auto r:v) g=min(g,r);
	vector<pii> _;_.resize(v.size());
	for(int i=0;i<v.size();++i)
	{
		id[i]=i;
		t2[i]=v[i]-g;
		if(t2[i].fi||t2[i].se)
			t1[i]=ang(t2[i]);
		else t1[i]=-1e18;
		t3[i]=len(t2[i]);
		t2[i]=yf(t2[i]);
	}
	sort(id,id+v.size(),cmp_g);
	for(int i=0;i<v.size();++i) _[i]=v[id[i]];
	v=_; v.erase(unique(v.begin(),v.end()),v.end());
	pii st[SZ]; int sn=0;
	for(auto x:v)
	{
		while(sn>=2&&(x-st[sn-1])*(st[sn]-st[sn-1])>=0)
			--sn;
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
#define WIN {puts("Ani"); return 0;}
bool chk(pii a,pii b,pii c)
{
	ll t=cross(a,b,c);
	if(t>0) return 0;
	if(t==0)
		return min(a.fi,c.fi)<=b.fi
		&&b.fi<=max(a.fi,c.fi)
		&&min(a.se,c.se)<=b.se
		&&b.se<=max(a.se,c.se);
	return 1;
}
int nr(vector<pii>& v,pii p)
{
	int n=v.size();
	if(n==1)
	{
		if(p!=v[0]) return -1;
		return 0;
	}
	if(n==2)
	{
		if(min(v[0].fi,v[1].fi)<=p.fi
		&&p.fi<=max(v[0].fi,v[1].fi)
		&&min(v[0].se,v[1].se)<=p.se
		&&p.se<=max(v[0].se,v[1].se)
		&&(p-v[0])*(v[1]-v[0])==0)
			return 0;
		return -1;
	}
//	cerr<<"QAQ"<<cross(v[0],p,v[1])<<"ww\n";
	if(!chk(v[0],p,v[1])) return -1;
	if(!chk(v[n-1],p,v[0])) return -1;
//	cross(v[0],p,v[1])>0) return -1;
//	if(cross(v[0],p,v[n-1])<0) return -1;
//	cerr<<"++\n";
	int i=2,j=n-1,g=n-1;
	while(i<=j)
	{
		int m=(i+j)>>1;
		if(cross(v[0],p,v[m])>0)
			g=m,j=m-1;
		else i=j+1;
	}
	for(int pp=0;pp<3;++pp)
	{
		int gg=g-2+pp;
		if(!chk(v[gg-1],p,v[gg])) return -1;
	}
	return g;
}
int main()
{
	scanf("%d",&n);
	bool z=0;
	vector<pii> Z;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",x+i,y+i);
		z|=x[i]==0&&y[i]==0;
		if((x[i]%2==1)||(y[i]%2==1))
			B.pb(pii(x[i],y[i]));
		else A.pb(pii(x[i],y[i]));
	}
	if(!z) A.pb(pii(0,0));
	Z=A;
	for(auto t:B) Z.pb(t);
	vector<pii> G=graham(Z);
	if(G[0]!=pii(0,0)) throw "??";
	vector<pii> O; O.pb(pii(0,0));
	set<pii> sG;
	for(auto x:G) sG.insert(x);
	for(int i=1;i<=n;++i)
		if(!sG.count(pii(x[i],y[i])))
			O.pb(pii(x[i],y[i]));
	vector<pii> v[2]={O,O};
	for(int i=1;i<G.size();++i)
		v[i&1].pb(G[i]);
	for(int i=0;i<2;++i)
	{
		v[i]=graham(v[i]);
		sG.clear();
		for(auto x:v[i]) sG.insert(x);
		for(auto t:B)
			if(sG.count(t))
			{
				puts("Ani");
				return 0;
			}
	}
	puts("Borna");
}