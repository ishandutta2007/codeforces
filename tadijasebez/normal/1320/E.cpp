#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define fir first
#define sec second
const int inf=1e9+7;
const int N=200050;
const int L=20;
vector<int> E[N];
vector<pii> G[N];
int lid[N],rid[N],tid,dep[N],par[N][L];
void DFS(int u,int p){
	lid[u]=++tid;
	dep[u]=dep[p]+1;
	par[u][0]=p;
	for(int i=1;i<L;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u])if(v!=p)DFS(v,u);
	rid[u]=tid;
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
void AddEdge(int u,int v,int w){
	G[u].pb({v,w});
	G[v].pb({u,w});
	//printf("G(%i %i %i)\n",u,v,w);
}
struct triple{int f,s,t;triple(){}triple(int a,int b,int c):f(a),s(b),t(c){}}dist[N];
bool operator < (triple a,triple b){return make_tuple(b.f,b.s,b.t)<make_tuple(a.f,a.s,a.t);}
bool operator != (triple a,triple b){return make_tuple(b.f,b.s,b.t)!=make_tuple(a.f,a.s,a.t);}
int main(){
	int n;scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	int q;scanf("%i",&q);
	while(q--){
		int k,m;scanf("%i %i",&k,&m);
		vector<pii> vir(k);
		vector<int> imp(m),nds;
		for(auto &i:vir)scanf("%i %i",&i.fir,&i.sec),nds.pb(i.fir);
		for(auto &i:imp)scanf("%i",&i),nds.pb(i);
		sort(nds.begin(),nds.end(),[&](int i,int j){return lid[i]<lid[j];});
		for(int i=1;i<m+k;i++)nds.pb(LCA(nds[i-1],nds[i]));
		sort(nds.begin(),nds.end(),[&](int i,int j){return lid[i]<lid[j];});
		nds.erase(unique(nds.begin(),nds.end()),nds.end());
		stack<int> stk;
		for(int u:nds){
			if(stk.empty())stk.push(u);
			else{
				while(rid[stk.top()]<lid[u])stk.pop();
				AddEdge(stk.top(),u,dep[u]-dep[stk.top()]);
				stk.push(u);
			}
		}
		for(int u:nds)dist[u]=triple(inf,0,0);
		priority_queue<pair<triple,int>> pq;
		for(int i=0;i<k;i++){
			dist[vir[i].fir]={0,i,0};
			pq.push({dist[vir[i].fir],vir[i].fir});
		}
		while(pq.size()){
			int u=pq.top().second;
			triple d=pq.top().first;
			pq.pop();
			if(d!=dist[u])continue;
			//printf("%i %i %i %i\n",u,d.f,d.s,d.t);
			for(auto e:G[u]){
				triple d2=d;
				d2.t+=e.sec;
				d2.f=(d2.t+vir[d2.s].sec-1)/vir[d2.s].sec;
				if(dist[e.fir]<d2){
					dist[e.fir]=d2;
					pq.push({d2,e.fir});
				}
			}
		}
		for(int u:imp)printf("%i ",dist[u].s+1);
		printf("\n");
		for(int u:nds)G[u].clear();
	}
	return 0;
}