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
#define SZ 2234567
int k,n,N;
//an old template
struct pnt
{
    ld x,y;
    pnt() {}
    pnt(ld a,ld b) {x=a; y=b;}
}p[SZ];
pnt operator - (pnt a,pnt b) {return pnt(a.x-b.x,a.y-b.y);}
ld operator * (pnt a,pnt b) {return a.x*b.y-a.y*b.x;}
ld pf(ld x) {return x*x;} 
ld dis(pnt a,pnt b) {return sqrt(pf(a.x-b.x)+pf(a.y-b.y));}
pnt mid(pnt a,pnt b) {return pnt((a.x+b.x)/2,(a.y+b.y)/2);}
struct lne
{
    ld a,b,c;
    lne() {a=b=c=0;}
    lne(ld x,ld y,ld z) {a=x;b=y;c=z;}
};
ld dj(pnt a,pnt b)
{
	return a.x*b.x+a.y*b.y;
}
pnt operator * (lne a,lne b)
{
    return pnt((b.c*a.b-a.c*b.b)/(a.a*b.b-a.b*b.a),
                (a.c*b.a-b.c*a.a)/(a.a*b.b-a.b*b.a));
}
lne zcx(pnt a,pnt b)
{
    ld mx=(a.x+b.x)/2,my=(a.y+b.y)/2;
    ld la=a.x-b.x,lb=a.y-b.y,lc=-(mx*la+my*lb);
    return lne(la,lb,lc);
}
pnt wx(pnt a,pnt b,pnt c) {return zcx(a,b)*zcx(a,c);}
ld eps=1e-6;
pnt np(pnt a,pnt b,pnt c)
{
    if(fabs((b-a)*(c-a))<eps)
    {
        double abl=dis(a,b),acl=dis(a,c),bcl=dis(b,c),ans=-1;
        pnt ap;
        if(abl>ans) ans=abl, ap=mid(a,b);
        if(acl>ans) ans=acl, ap=mid(a,c);
        if(bcl>ans) ans=bcl, ap=mid(b,c);
        return ap;
    }
    return wx(a,b,c);
}
ld gr(pnt o,pnt a,pnt b,pnt c) {return max(max(dis(o,a),dis(o,b)),dis(o,c));}
pair<pnt,ld> rs[SZ]; int rn;
ld area(pnt a,pnt b,pnt c)
{
	return fabs((b-a)*(c-a));
}
bool in(pnt a,pnt b,pnt c,pnt o)
{
	return fabs(area(a,b,c)-
	area(a,b,o)-area(c,b,o)
	-area(a,c,o))<10;
}
ld dis(pair<pnt,ld> A,pair<pnt,ld> B)
{
	ld d=dis(A.fi,B.fi),r1=A.se,r2=B.se;
	ld d00=fabs(d+r1+r2),
	d01=fabs(d+r1-r2),
	d10=fabs(d-r1+r2),
	d11=fabs(d-r1-r2);
	//+: 0   -:1
	return max(max(min(d11,d10),
	min(d01,d00)),max(min(d11,d01),
	min(d10,d00)));
}
int ff[SZ];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
pair<ld,pii> es[SZ]; int en;
const ld PI=acos(-1);
ld ang(pnt s)
{
	return atan2(s.y,s.x);
}
vector<int> ap[SZ];
int main()
{
	scanf("%d%d",&k,&n); N=k*n;
	for(int i=1;i<=N;++i)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	random_shuffle(p+1,p+1+N);
	while(clock()<CLOCKS_PER_SEC*10)
	{
		int x=rand()%N+1,y=rand()%N+1,z=rand()%N+1;
		if(x==y||x==z||y==z) continue;
		if(rn>=2000) break;
		pnt o=np(p[x],p[y],p[z]);
		if(in(p[x],p[y],p[z],o));
		else continue;
		ld R=gr(o,p[x],p[y],p[z]);
		int cn=0;
		vector<ld> pr;
		pr.pb(-PI);
		pr.pb(PI);
		for(int j=1;j<=N;++j)
		{
			ld r=dis(o,p[j]);
			if(0.85*R<=r&&r<=1.15*R)
			{
				pr.pb(ang(p[j]-o));
				++cn;
			}
		}
		if(cn<n) continue;
		if(o.x*o.x+o.y*o.y<=1000000.0*1000000);
		else continue;
		if(R>=240000&&R<=760000);
		else continue;
		sort(pr.begin(),pr.end());
		bool bad=0;
		ld mx=0;
		for(int i=1;i<pr.size();++i)
			if(pr[i]-pr[i-1]>1)
				mx=max(mx,pr[i]-pr[i-1]),
				bad=1;
		if(bad) continue;
		/*
		{
			cout<<"FAKE!"<<mx<<"\n";
			for(auto g:pr)
				cerr<<g<<",";
			cerr<<"?\n";
			system("pause"); 
		}*/
		rs[++rn]=mp(o,R);
//		cerr<<cn<<"!";
	}
	for(int i=1;i<=rn;++i)
		for(int j=i+1;j<=rn;++j)
		{
			ld d=dis(rs[i],rs[j]);
			es[++en]=mp(d,pii(i,j));
		}
	sort(es+1,es+1+en);
	int tt=rn;
	for(int i=1;i<=en;++i)
	{
		int x=gf(es[i].se.fi),y=gf(es[i].se.se);
		if(x!=y)
		{
			--tt; ff[x]=y;
			if(tt==k) break;
		}
	}
	for(int i=1;i<=rn;++i) ap[gf(i)].pb(i);
	for(int i=1;i<=rn;++i)
		if(!ff[i])
		{
			ld mi=8e18; int X;
			for(auto x:ap[i])
			{
				ld dd=0;
				for(auto y:ap[i])
					dd+=dis(rs[x],rs[y]);
				if(dd<mi) mi=dd,X=x;
			}
//			cout<<i<<":"<<ap[i].size()<<"\n";
			printf("%.10lf %.10lf %.10lf\n",
			rs[X].fi.x,rs[X].fi.y,rs[X].se);
		}
}