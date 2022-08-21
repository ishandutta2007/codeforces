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
#define SZ 444444
int n,m;
set<int> adj[100005];
int ea[SZ],eb[SZ];
vector<int> bu[100005];
bool sb[SZ];
pair<ll,ll> su[SZ];
ll ans=0;
int*ds[SZ],dd[220][100055];
namespace Org
{
Edg
int qs[SZ];
void bfs(int s,int*d)
{
	for(int i=1;i<=n;++i) d[i]=-1;
	d[s]=0; int h=0,t=0; qs[t++]=s;
	while(h^t)
	{
		int x=qs[h++];
		for esb(x,e,b) if(d[b]==-1)
			d[b]=d[x]+1,qs[t++]=b;
	}
}
int sz[SZ]; ll sd=0;
vector<int> sp,sg;
void dfs(int x,int f=0,int d=0)
{
	sz[x]=1; sd+=d;
	for esb(x,e,b) if(sb[b]&&b!=f)
		dfs(b,x,d+1),sz[x]+=sz[b];
	sp.pb(sz[x]); sg.pb(x);
}
void work(int x)
{
	sp.clear(); sg.clear();
	sd=0; dfs(x);
	for(auto p:sp)
		ans+=(sz[x]-p)*(ll)p*2;
	su[x]=mp(ll(sp.size()),sd);
	bu[x]=sg;
}
}
int G=1,Z=0,V[SZ],R[SZ],vpp[SZ],vpe[SZ];
vector<pii> add[SZ];
vector<int> cv[SZ];
bool gone[SZ],ok[SZ];
void ccv(int a,int b,int c,int t)
{
	++Z; V[Z]=b;
	if(vpp[a]) vpp[t]=vpp[a],R[vpe[a]]=Z;
	else vpp[t]=Z;
	if(vpp[c]) R[Z]=vpp[c],vpe[t]=vpe[c];
	else vpe[t]=Z;
}
int mk[SZ],Q=0;
ll s1[SZ],s0[SZ];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),
		ea[i]=a,eb[i]=b,
		Org::adde(a,b),
		adj[a].insert(b),
		adj[b].insert(a);
	queue<int> r;
	for(int i=1;i<=n;++i)
		if(adj[i].size()==1)
			r.push(i);
	while(!r.empty())
	{
		int x=r.front(); r.pop();
		if(adj[x].size()!=1) continue;
		sb[x]=1;
		for(auto b:adj[x])
		{
			adj[b].erase(x);
			if(adj[b].size()==1) r.push(b);
		}
	}
	for(int i=1;i<=n;++i) adj[i].clear();
	for(int i=1;i<=n;++i)
		if(!sb[i])
		{
			Org::work(i);
//			cout<<i<<":"<<su[i].fi<<","<<su[i].se<<"\n";
		}
	for(int i=1;i<=m;++i)
		if(!sb[ea[i]]&&!sb[eb[i]])
			add[ea[i]].pb(pii(eb[i],G)),
			add[eb[i]].pb(pii(ea[i],G));
	for(int i=1;i<=n;++i)
		if(add[i].size()==2) ok[i]=1;
	for(int i=1;i<=n;++i)
		if(ok[i])
		{
			bool cy=0;
			for(auto t:add[i])
				if(t.fi==i) cy=1;
			if(cy)
			{
				ok[i]=0;
				continue;
			}
			vector<pii> ns;
			for(auto t:add[i])
				if(!gone[t.fi]) ns.pb(t);
			if(ns.size()!=2) throw "GG";
			auto X=ns[0],Y=ns[1]; gone[i]=1;
			++G; ccv(X.se^1,i,Y.se,G);
			++G; ccv(Y.se^1,i,X.se,G);
			add[X.fi].pb(pii(Y.fi,G-1));
			if(X.fi!=Y.fi)
				add[Y.fi].pb(pii(X.fi,G));
		}
	for(int i=1;i<=n;++i)
		if(!ok[i]&&!sb[i])
			for(auto g:add[i])
			{
				if(gone[g.fi]) continue;
				for(int j=vpp[g.se];j;j=R[j])
					cv[g.se].pb(V[j]);
			}
	for(int i=1,g=0;i<=n;++i)
		if(!ok[i]&&!sb[i])
		{
			ds[i]=dd[g++]; Org::bfs(i,ds[i]);
			ll c1=0,c0=0;
			for(int j=1;j<=n;++j) c1+=ds[i][j],++c0;
			for(auto j:bu[i]) c1-=ds[i][j],--c0;
			ans+=c1*su[i].fi+c0*su[i].se;
		}
//	for(int i=1;i<=n;++i)
//		if(!ok[i]&&!sb[i])
//			cout<<i<<" ";
//	cout<<"\n";
	for(int i=1;i<=n;++i)
		if(!ok[i]&&!sb[i])
			for(auto g:add[i])
			{
				if(gone[g.fi]) continue;
				if(i>g.fi||!cv[g.se].size()) continue;
				++Q; int j=g.fi; vector<int>&v=cv[g.se];
//				cout<<i<<"~"<<g.fi<<"|";
//				for(auto t:v) cout<<t<<" ";cout<<"\n";
				int l=v.size();
				for(auto p:v)
				{
					mk[p]=Q;
					for(auto tt:bu[p]) mk[tt]=Q;
				}
				auto dv=[&](int x) {if(x&1)--x; return x/2;};
				ll s2=0;
				for(int p=0;p<l;++p)
					s1[p+1]=s1[p]+su[v[p]].fi*(ll)p,
					s0[p+1]=s0[p]+su[v[p]].fi,
					s2+=su[v[p]].se;
//				cerr<<s2<<"!!\n";
				for(int p=1;p<=n;++p) if(mk[p]!=Q)
				{
					int D1=ds[i][p],D2=ds[j][p];
//					cout<<min(D1+1,D2+1)<<"?"<<ans<<"\n";
					ans+=s2;
					//[0,l-1] min(D1+i+1,D2+l-i)
					//D1+i+1<=D2+l-i
					//2i<=D2-D1+l-1
					int g=dv(D2-D1+l-1);
					if(g<0) g=-1;
					if(g>=l) g=l-1;
					ans+=s0[g+1]*(D1+1)+s1[g+1];
					ans+=(s0[l]-s0[g+1])*(D2+l)
					-(s1[l]-s1[g+1]);
//					cout<<"ans2="<<ans<<"\n";
				}
				int D=ds[i][j];
				//min(D+a+1+l-b,b-a)
				//D+a+1+l-b>=b-a
				//b<=(D+2a+1+l)/2
				s2=0;
				for(int a=l-1;a>=0;--a)
				{
					int b=dv(D+a+a+1+l);
					b=max(b,a); b=min(b,l-1);
					//(x,y) l (p,q)
					//l*x*p+y*p+q*x
					//[a+1,b] [b+1,l-1]
					ll S=0;
					S+=(s1[b+1]-s1[a+1])-(ll)a*(s0[b+1]-s0[a+1]);
					S+=-(s1[l]-s1[b+1])+(ll)(D+a+1+l)*(s0[l]-s0[b+1]);
					ans+=(S*su[v[a]].fi
					+su[v[a]].se*(s0[l]-s0[a+1])
					+su[v[a]].fi*s2)*2;
					s2+=su[v[a]].se;
				}
			}
//	cerr<<ans<<"?\n";
	cout<<ans/2<<"\n";
}