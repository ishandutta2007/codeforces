#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=200050;
const int L=20;
const int inf=1e9+7;
vector<int> E[N];
set<pair<int,int>> sts[N];
int add[N];
struct DSU{
	int p[N];
	void init(){for(int i=0;i<N;i++)p[i]=i;}
	DSU(){}
	int Find(int x){return x==p[x]?x:p[x]=Find(p[x]);}
	void Union(int x,int y){p[Find(x)]=Find(y);}
} DS;
int d[N],ud[N],dep[N],par[N][L];
bool mark[N];
void DFS(int u,int p){
	d[u]=mark[u]?0:inf;
	par[u][0]=p;
	dep[u]=dep[p]+1;
	for(int i=1;i<L;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u])if(v!=p){
		DFS(v,u);
		ckmn(d[u],d[v]+1);
	}
}
void DFS2(int u,int p){
	if(!p)ud[u]=mark[u]?0:inf;
	if(mark[u])ud[u]=0;
	int mn=inf,sec=inf;
	for(int v:E[u])if(v!=p){
		int tmp=d[v]+1;
		if(mn>tmp)sec=mn,mn=tmp;
		else ckmn(sec,tmp);
	}
	for(int v:E[u])if(v!=p){
		int tmp=d[v]+1;
		int now=mn;
		if(tmp==mn)now=sec;
		ud[v]=min(ud[u]+1,now+1);
		DFS2(v,u);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int val[N];
bool alive[N];

void sw(int x,int y){
	swap(add[x],add[y]);
	swap(sts[x],sts[y]);
}
void Merge(int x,int y){
	for(auto p:sts[y]){
		val[p.second]+=add[y]-add[x];
		p.first+=add[y]-add[x];
		sts[x].insert(p);
	}
}

bool ans[N];
int q_u[N],q_v[N],k;
vector<int> Qs[N];
void Solve(int u,int p){
	for(int v:E[u])if(v!=p){
		Solve(v,u);
		add[v]--;
		if(sts[u].size()<sts[v].size())sw(u,v);
		Merge(u,v);
	}
	sts[u].insert({k-add[u],u});
	val[u]=k-add[u];
	alive[u]=1;
	while(sts[u].size()){
		auto x=*sts[u].begin();
		int rlv=x.first+add[u];
		if(rlv<0){
			alive[x.second]=0;
			sts[u].erase(x);
		}else{
			break;
		}
	}
	int d=min(::d[u],ud[u]);
	int chng=k-d;
	int mao=0;
	//printf("%i %i %i %i\n",::d[u],ud[u],d,chng);
	//printf("u:%i\n",u);
	while(sts[u].size()){
		auto x=sts[u].lower_bound({d-add[u],0});
		if(x==sts[u].end())break;
		int rlv=x->first+add[u];
		if(rlv<chng){
			if(mao)DS.Union(mao,x->second);
			mao=DS.Find(x->second);
			sts[u].erase(x);
		}else{
			break;
		}
	}
	if(mao){
		sts[u].insert({k-d-add[u],mao});
		val[mao]=k-d-add[u];
	}
	for(int q:Qs[u]){
		int x=DS.Find(q_u[q]);
		int y=DS.Find(q_v[q]);
		if(alive[x] && alive[y] && val[x]+add[u]+val[y]+add[u]>=k)ans[q]=1;
		else ans[q]=0;
	}
	//for(int i=1;i<=8;i++)printf("(%i %i) ",alive[DS.Find(i)],val[DS.Find(i)]+add[u]);
	//printf("\n");
}
int main(){
	DS.init();
	int n,r;
	scanf("%i %i %i",&n,&k,&r);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(int i=1,u;i<=r;i++)scanf("%i",&u),mark[u]=1;
	DFS(1,0);
	DFS2(1,0);
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		scanf("%i %i",&q_u[i],&q_v[i]);
		int lca=LCA(q_u[i],q_v[i]);
		Qs[lca].pb(i);
	}
	Solve(1,0);
	for(int i=1;i<=q;i++){
		if(ans[i])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}