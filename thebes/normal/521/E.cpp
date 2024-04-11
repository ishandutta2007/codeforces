#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 2e5+5;
int N, M, i, x, y, par[MN], dep[MN], ds[MN], id[MN], vs[MN];
vi adj[MN], cadj[MN], vec; vector<pii> ed;

int fnd(int x){return ds[x]=x==ds[x]?x:fnd(ds[x]);}

void dfs(int n,int p,int d){
	par[n] = p; dep[n] = d; vs[n] = 1;
	for(auto v : adj[n]){
		if(v==p) continue;
		dfs(v, n, d+1);
	}
}

inline void add(int x,int y){
	cadj[x].pb(y);
	cadj[y].pb(x);
	while(x^y){
		if(dep[x]<dep[y]) swap(x,y);
		cadj[x].pb(par[x]);
		cadj[par[x]].pb(x);
		x = par[x];
	}
}

void go(int n,int p,int d){
	vec.pb(n);
	if(n==d) return;
	vs[n] = 1;
	for(auto v : cadj[n]){
		if(v==p||vs[v]) continue;
		go(v, n, d);
		cadj[n].erase(find(cadj[n].begin(),cadj[n].end(),v));
		return;
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
		ds[i] = i;
	for(i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		if(fnd(x)^fnd(y)){
			ds[fnd(x)]=fnd(y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		else ed.pb({x,y});
	}
	for(i=1;i<=N;i++)
		ds[i] = i;
	for(i=1;i<=N;i++){
		if(vs[i]) continue;
		dfs(i, 0, 0);
	}
	memset(vs,0,sizeof(vs));
	int idx = 0;
	memset(id,-1,sizeof(id));
	for(auto v : ed){
		x = v.F, y = v.S;
		while(x^y){
			if(dep[x]<dep[y]) swap(x,y);
			if(id[x]!=-1){
				add(ed[id[x]].F,ed[id[x]].S);
				add(v.F,v.S);
				vi pt;
				for(i=1;i<=N;i++){
					sort(cadj[i].begin(),cadj[i].end());
					cadj[i].erase(unique(cadj[i].begin(),cadj[i].end()),cadj[i].end());
					if(cadj[i].size()==3) pt.pb(i);
				}
				printf("YES\n");
				for(i=0;i<3;i++){
					vec.clear();
					go(pt[0],0,pt[1]);
					printf("%d ",vec.size());
					for(auto u : vec){
						printf("%d ",u);
					}
					printf("\n");
				}
				return 0;
			}
			else{
				id[x] = idx;
				x = par[x];
			}
		}
		idx++;
	}
	printf("NO\n");
	return 0;
}