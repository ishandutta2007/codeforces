#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int N=200050;
vector<int> E[N];
int sz[N],a[N];
bool was[N];
void DFSSZ(int u,int p){sz[u]=1;for(int v:E[u])if(v!=p&&!was[v])DFSSZ(v,u),sz[u]+=sz[v];}
int Find(int u,int p,int n){for(int v:E[u])if(v!=p&&!was[v]&&sz[v]*2>n)return Find(v,u,n);return u;}
int Find(int u){DFSSZ(u,u);was[u=Find(u,u,sz[u])]=1;return u;}
struct Line{ll k,n;Line(){}Line(ll a,ll b):k(a),n(b){}ll Get(ll x){return x*k+n;}};
const int M=2*N;
const int lim=N;
const ll inf=1e18;
Line line[M];
int tsz,rs[M],ls[M];
void cl(){tsz=0;}
void AddLine(int&c,int ss,int se,Line k){
	if(!c){c=++tsz,ls[c]=rs[c]=0,line[c]=k;return;}
	ll A=line[c].Get(ss),B=k.Get(ss),C=line[c].Get(se),D=k.Get(se);
	if(A>=B&&C>=D)return;
	if(A<=B&&C<=D){line[c]=k;return;}
	int mid=ss+se>>1;
	if(A<B)swap(line[c],k);
	if(line[c].Get(mid)>=k.Get(mid))AddLine(rs[c],mid+1,se,k);
	else swap(line[c],k),AddLine(ls[c],ss,mid,k);
}
ll Get(int c,int ss,int se,int qi){
	if(!c)return -inf;
	if(ss==se)return line[c].Get(qi);
	ll ans=line[c].Get(qi);
	int mid=ss+se>>1;
	ans=max(ans,qi<=mid?Get(ls[c],ss,mid,qi):Get(rs[c],mid+1,se,qi));
	return ans;
}
struct info{
	int root;
	info(){root=0;}
	void add(ll x,ll y){AddLine(root,1,lim,Line(x,y));}
	ll get(int dep,ll x){return x+Get(root,1,lim,dep);}
};
ll sol;
void Build(int u,int p,int dep,ll sum,ll ans,info&A){
	sum+=a[u];ans+=(ll)a[u]*dep;
	A.add(sum,ans);ckmx(sol,ans);
	for(int v:E[u])if(v!=p&&!was[v])Build(v,u,dep+1,sum,ans,A);
}
void Calc(int u,int p,int dep,ll sum,ll ans,info A){
	ans+=sum+a[u];sum+=a[u];
	ckmx(sol,A.get(dep,ans));
	for(int v:E[u])if(v!=p&&!was[v])Calc(v,u,dep+1,sum,ans,A);
}
void Solve(int u){
	u=Find(u);
	ckmx(sol,(ll)a[u]);
	info all=info();all.add(a[u],a[u]);
	cl();
	for(int v:E[u])if(!was[v]){
		Calc(v,u,1,0,0,all);
		Build(v,u,2,a[u],a[u],all);
	}
	cl();reverse(E[u].begin(),E[u].end());
	all=info();
	for(int v:E[u])if(!was[v]){
		Calc(v,u,1,0,0,all);
		Build(v,u,2,a[u],a[u],all);
	}
	for(int v:E[u])if(!was[v])Solve(v);
}
int main(){
	int n=ri();
	for(int i=1,u,v;i<n;i++)rd(u,v),E[u].pb(v),E[v].pb(u);
	for(int i=1;i<=n;i++)rd(a[i]);
	Solve(1);
	printf("%lld\n",sol);
	return 0;
}