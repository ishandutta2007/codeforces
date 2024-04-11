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
#define SZ 2234567
int n,p[SZ]; ll k,w[SZ],v[SZ]; Edg
void dfs(int x)
{
	for esb(x,e,b)
		v[b]=v[x]^w[b],dfs(b);
}
typedef pair<int*,int> sb;
struct MyVec
{
pair<sb,sb> uu[SZ];
int sz;
void clear() {sz=0;}
void pb(const pair<sb,sb>&t)
{uu[sz++]=t;if(sz>=n+1) throw "GG";}
pair<sb,sb>*begin() {return uu;}
pair<sb,sb>*end() {return uu+sz;}
}que,ts;
char ch,B[1<<20],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
ll aa; int bb;ll F(){
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
#define gll F()
int tt[4][SZ],tn[4];
int X[SZ];
int main()
{
	n=gll,k=gll;
	for(int i=2;i<=n;++i)
		p[i]=gll,w[i]=gll,ad_de(p[i],i);
	dfs(1);
	sort(v+1,v+1+n);
	for(int i=1;i<=n;++i) X[i-1]=i;
	que.pb(mp(mp(&X[0],n),mp(&X[0],n)));
	ll ans=0;
	for(int i=61;i>=0;--i)
	{
		ll tot=0;
		for(auto&p:que)
		{
			ll l[2]={0,0},r[2]={0,0};
			for(int t=0;t<p.fi.se;++t)
				++l[(v[p.fi.fi[t]]>>i)&1];
			for(int t=0;t<p.se.se;++t)
				++r[(v[p.se.fi[t]]>>i)&1];
			tot+=l[0]*r[0]+l[1]*r[1];
		}
		if(k<=tot)
		{
			for(auto&p:que)
			{
				ll l[2]={0,0},r[2]={0,0};
				for(int t=0;t<p.fi.se;++t)
					++l[(v[p.fi.fi[t]]>>i)&1];
				for(int t=0;t<p.se.se;++t)
					++r[(v[p.se.fi[t]]>>i)&1];
				if(l[0]&&r[0])
					ts.pb(mp(mp(p.fi.fi,l[0]),mp(p.se.fi,r[0])));
				if(l[1]&&r[1])
					ts.pb(mp(mp(p.fi.fi+l[0],l[1]),mp(p.se.fi+r[0],r[1])));
			}
		}
		else
		{
			k-=tot; ans|=1LL<<i;
			for(auto&p:que)
			{
				ll l[2]={0,0},r[2]={0,0};
				for(int t=0;t<p.fi.se;++t)
					++l[(v[p.fi.fi[t]]>>i)&1];
				for(int t=0;t<p.se.se;++t)
					++r[(v[p.se.fi[t]]>>i)&1];
				if(l[0]&&r[1])
					ts.pb(mp(mp(p.fi.fi,l[0]),mp(p.se.fi+r[0],r[1])));
				if(l[1]&&r[0])
					ts.pb(mp(mp(p.fi.fi+l[0],l[1]),mp(p.se.fi,r[0])));
			}
		}
		que.sz=ts.sz;
		for(int j=0;j<ts.sz;++j)
			que.uu[j]=ts.uu[j];
		ts.sz=0;
	}
	cout<<ans<<"\n";
}