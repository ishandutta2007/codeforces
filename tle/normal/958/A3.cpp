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
typedef pair<ld,ld> pnt;
#define SZ 1234567
int n,n1,n2; pnt p1[SZ],p2[SZ];
pair<ld,pii> ps[5050666]; int pn=0;
inline ld dis(pnt x) {return x.fi*x.fi+x.se*x.se;}
inline ld ang(pnt x) {return atan2l(x.se,x.fi);}
inline pnt operator - (pnt a,pnt b) {return pnt(a.fi-b.fi,a.se-b.se);}
inline pnt operator + (pnt a,pnt b) {return pnt(a.fi+b.fi,a.se+b.se);}
inline ld dis(pnt x,pnt y) {return dis(x-y);}
ld co,si;
/*
pnt rot(pnt g,ld t) {return pnt
(g.fi*cos(t)-g.se*sin(t),
g.fi*sin(t)+g.se*cos(t));}*/
inline pnt rot(pnt g) {return pnt(g.fi*co-g.se*si,g.fi*si+g.se*co);}
pair<pnt,int> q1[SZ],qt[SZ];
bool vis[SZ];
void chk(pnt a1,pnt a2,pnt b1,pnt b2)
{
	cerr<<"=";
	//a1b1
	ld x1=ang(a2-a1),x2=ang(b2-b1);
	co=cosl(x2-x1); si=sinl(x2-x1);
	int tt=0;
	for(int i=1;i<=n1&&i<=3000;++i)
		qt[++tt].fi=rot(p1[i]-a1)+b1;
	sort(qt+1,qt+tt+1);
	int sb=0;
	for(int i=1;i<=n2&&i<=3000;++i)
	{
		int o=lower_bound(qt+1,qt+tt+1,mp(p2[i],0))-qt;
		bool s=0;
		for(int j=max(o-10,1);j<=min(o+10,n1);++j)
			if(dis(qt[j].fi,p2[i])<1) {s=1; break;}
		sb+=s;
	}
	if(sb<5) return;
	for(int i=1;i<=n1;++i)
		q1[i].fi=rot(p1[i]-a1)+b1,q1[i].se=i,vis[i]=0;
	sort(q1+1,q1+n1+1);
	vector<pii> rs;
	int fail=0;
	for(int i=1;i<=n2;++i)
	{
		int o=lower_bound(q1+1,q1+n1+1,mp(p2[i],0))-q1;
		bool s=0;
		for(int j=max(o-10,1);j<=min(o+10,n1);++j)
		{
			if(dis(q1[j].fi,p2[i])<1&&!vis[q1[j].se])
			{
				rs.pb(pii(q1[j].se,i));
				fail=0; s=1; vis[q1[j].se]=1; break;
			}
		}
		if(!s) ++fail;
		if(fail>100) return;
	}
	random_shuffle(rs.begin(),rs.end());
	if(rs.size()>=n*0.95)
	{
		if(rs.size()>n) rs.resize(n);
		for(int _=0;_<rs.size();++_)
			printf("%d %d\n",rs[_].fi,rs[_].se);
		for(int _=rs.size();_<n;++_)
			printf("1 1\n");
		exit(0);
	}
}
pnt md; ld gg[SZ];
bool cmp(int a,int b) {return gg[a]<gg[b];}
inline bool myc(const pair<ld,pii>&a,const pair<ld,pii>&b) {return a.fi<b.fi;}
int main()
{
	cin>>n>>n1;
	for(int i=1;i<=n1;++i)
		cin>>p1[i].fi>>p1[i].se;
	cin>>n2;
	for(int i=1;i<=n2;++i)
		cin>>p2[i].fi>>p2[i].se;
	for(int i=1;i<=n1&&pn<4000000;++i)
	{
		md=p1[i]; vector<int> rs;
		for(int j=1;j<=n1;++j) if(j!=i)
			rs.pb(j),gg[j]=ang(p1[j]-md);
		sort(rs.begin(),rs.end(),cmp);
		for(unsigned _=0;_<rs.size();++_)
		{
			int x=rs[_],y=rs[(_+1)%rs.size()];
			ps[++pn]=mp(dis(p1[x],p1[y]),pii(x,y));
		}
	}
	while(pn<5000000)
	{
		int x=rand()%n1+1,y=rand()%n1+1;
		if(x!=y) ps[++pn]=mp(dis(p1[x],p1[y]),pii(x,y));
	}
	sort(ps+1,ps+1+pn,myc);
	for(int w=1;w<=n2;++w)
	{
		cerr<<"=====\n";
		md=p2[w]; vector<int> rs;
		for(int j=1;j<=n2;++j) if(j!=w)
			rs.pb(j),gg[j]=ang(p2[j]-md);
		sort(rs.begin(),rs.end(),cmp);
		int uu=0;
		int p=rand()%rs.size();
		for(unsigned _=0;_<rs.size();++_)
		{
		int i=rs[(_+p)%rs.size()],j=rs[(_+1+p)%rs.size()];
		ld dx=dis(p2[i],p2[j]);
		int s=lower_bound(ps+1,ps+1+pn,mp(dx,pii(0,0)))-ps;
		for(int k=max(s-5,1);k<=min(s+5,pn);++k)
		if(fabs(dx-ps[k].fi)<0.1)
		{
			chk(p1[ps[k].se.fi],p1[ps[k].se.se],p2[i],p2[j]);
			chk(p1[ps[k].se.fi],p1[ps[k].se.se],p2[j],p2[i]);
			++uu;
		}
		if(uu>30) break;
		}
		int i=rand()%n2+1,j=rand()%n2+1;
		if(i==j) continue;
		ld dx=dis(p2[i],p2[j]);
		int s=lower_bound(ps+1,ps+1+pn,mp(dx,pii(0,0)))-ps;
		for(int k=max(s-10,1);k<=min(s+10,pn);++k)
		if(fabs(dx-ps[k].fi)<0.01)
		{
			chk(p1[ps[k].se.fi],p1[ps[k].se.se],p2[i],p2[j]);
			chk(p1[ps[k].se.fi],p1[ps[k].se.se],p2[j],p2[i]);
		}
	}
	throw "GG";
}