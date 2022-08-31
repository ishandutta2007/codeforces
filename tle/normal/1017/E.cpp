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
pii g;
pii operator + (pii a,pii b)
{return pii(a.fi+b.fi,a.se+b.se);}
pii operator - (pii a,pii b)
{return pii(a.fi-b.fi,a.se-b.se);}
ll len(pii x) {return (ll)x.fi*x.fi+(ll)x.se*x.se;}
pii yf(pii x)
{
	int t=__gcd(x.fi,x.se);
	if(t<0) t=-t;
	x.fi/=t; x.se/=t;
	return x;
}
int id[SZ],gi;
pii yy[SZ];
ll ls[SZ];
long double as[SZ];
bool cmp(int i,int j)
{
	if((i==gi)!=(j==gi))
		return (i==gi)>(j==gi);
	if(yy[i]==yy[j])
		return ls[i]<ls[j];
	return as[i]<as[j]; 
}
ll operator * (pii a,pii b)
{return a.fi*(ll)b.se-a.se*(ll)b.fi;}
vector<pii> graham(vector<pii> v)
{
	vector<pii> s; g=pii(2e9,2e9);
	for(auto r:v) g=min(g,r);
	for(int i=0;i<int(v.size());++i) id[i]=i;
	for(int i=0;i<int(v.size());++i)
	{
		yy[i]=v[i]-g; ls[i]=len(yy[i]);
		if(!ls[i]) {gi=i; continue;}
		as[i]=atan2l(yy[i].se,yy[i].fi);
		yy[i]=yf(yy[i]);
	}
	sort(id,id+v.size(),cmp);
	static pii st[SZ]; int sn=0;
	for(int i=0;i<int(v.size());++i)
	{
		pii x=v[id[i]];
		while(sn>=2&&(x-st[sn-1])*(st[sn]-st[sn-1])>=0) --sn;
		st[++sn]=x;
	}
	for(int i=1;i<=sn;++i)
		s.pb(st[i]);
	return s;
}
typedef pair<ll,ll> pll;
vector<pii> A,B;
int n,m;
vector<pll> gf(vector<pii> x)
{
	int n=x.size();
	vector<pll> v;
	for(int i=0;i<n;++i)
		v.pb(pll(len(x[(i+1)%n]-x[i]),len(x[(i+2)%n]-x[i])));
	return v;
}
vector<pll> sf(vector<pll> s)
{
    int n=s.size(),i=0,j=1,k=0; pll t;
    while(i<n && j<n && k<n){
        if (s[(i+k)%n]==s[(j+k)%n]) k++;
        else{
            if (s[(i+k)%n]>s[(j+k)%n]) i+=k+1; 
            else j+=k+1;
            if (i==j) j++;
            k=0;
        }
    }
	int tt=i<j?i:j;
	vector<pll> g;
	for(int i=0;i<n;++i)
		g.pb(s[(i+tt)%n]);
	return g;
}
int main()
{
	scanf("%d%d",&n,&m);
	pii t;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&t.fi,&t.se),A.pb(t);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&t.fi,&t.se),B.pb(t);
	A=graham(A); B=graham(B);
	vector<pll> X=sf(gf(A)),Y=sf(gf(B));
	if(X==Y) puts("YES");
	else puts("NO");
}