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
#define SZ 666666
int n,x[SZ],y[SZ],fa[SZ],fe[SZ]; Edgc
int sz[SZ],mi=2e9,u;
void dd(int w,int f=0)
{
	sz[w]=1; fa[w]=f;
	int mx=0;
	for esb(w,e,b) if(b!=f)
	{
		dd(b,w); sz[w]+=sz[b];
		mx=max(mx,sz[b]);
	}
	mx=max(mx,n-sz[w]);
	if(mx<mi) mi=mx,u=w;
}
void go(int x,int l,ll s)
{
	fe[x]=l*(ll)s; l=1;
	for esb(x,e,b) if(b!=fa[x])
		go(b,l,s),l+=sz[b];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
		scanf("%d%d",x+i,y+i),
		adde(x[i],y[i],i);
	dd(1);
	int U=u; dd(u); u=U;
	vector<pii> s;
	for esb(u,e,b)
		s.pb(pii(sz[b],b));
	sort(s.begin(),s.end());
	ll mx=-1; int I,l,r;
	{
	int L=0,R=n-1;
	for(int i=0;i<=s.size();++i)
	{
		if(i) L+=s[i-1].fi,R-=s[i-1].fi;
		ll u=(L+1)*ll(R+1);
		if(u>mx) mx=u,I=i,l=L,r=R;
	}
	}
	int cl=1;
	for(int i=0;i<I;++i)
	{
		int t=s[i].fi;
		go(s[i].se,cl,1);
		cl+=t;
	}
	cl=1;
	for(int i=I;i<s.size();++i)
	{
		int t=s[i].fi;
		go(s[i].se,cl,l+1);
		cl+=t;
	}
	for(int i=1;i<=n;++i)
		if(i!=u)
			printf("%d %d %d\n",i,fa[i],fe[i]);
}