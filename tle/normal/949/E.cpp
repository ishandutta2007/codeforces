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
int n;
vector<int> go(int rr,vector<int> g)
{
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	for(unsigned i=0;i<g.size();++i)
		if(g[i]==0) {g.erase(g.begin()+i); break;}
	if(!g.size()) return g;
	if(rr>=262144)
	{
		vector<int> h;
		h.resize(100);
		return h;
	}
	int bb=0;
	for(unsigned i=0;i<g.size();++i)
		if(g[i]&1) bb=1;
	if(!bb)
	{
		for(unsigned i=0;i<g.size();++i) g[i]/=2;
		return go(rr*2,g);
	}
	vector<int> r;
	for(int k=-1;k<=1;k+=2)
	{
		vector<int> h=g;
		for(unsigned i=0;i<h.size();++i)
			if(h[i]&1) h[i]=(h[i]-k)/2;
			else h[i]/=2;
		h=go(rr*2,h); h.pb(rr*k);
		if(k==-1) r=h;
		else if(h.size()<r.size()) r=h;
	}
	return r;
}
int main()
{
	scanf("%d",&n);vector<int> v;
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),v.pb(x);
	v=go(1,v);printf("%d\n",int(v.size()));
	for(auto x:v) printf("%d ",x);
}