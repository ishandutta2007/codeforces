#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int L=17;
int mark[N];
struct Graph{
	vector<int> E[N];
	int lid[N],rid[N],tid,par[N][L],dep[N];
	void AddEdge(int u,int v){E[u].pb(v);E[v].pb(u);}
	void DFS(int u,int p){
		lid[u]=++tid;
		par[u][0]=p;
		for(int i=1;i<L;i++)par[u][i]=par[par[u][i-1]][i-1];
		dep[u]=dep[p]+1;
		for(int v:E[u])if(v!=p)DFS(v,u);
		rid[u]=tid;
	}
	int LCA(int u,int v){
		if(dep[u]<dep[v])swap(u,v);
		for(int i=L-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
		for(int i=L-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
		return u==v?v:par[v][0];
	}
	pair<int,int> DP(int u,int p){
		int cnt=0,ans=0;
		for(int v:E[u])if(v!=p){
			pair<int,int> tmp=DP(v,u);
			ans+=tmp.first;
			cnt+=tmp.second;
		}
		if(mark[u])ans+=cnt,cnt=1;
		else if(cnt>1)ans++,cnt=0;
		return {ans,cnt};
	}
}G,V;
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),G.AddEdge(u,v);
	G.DFS(1,0);
	int q;
	scanf("%i",&q);
	while(q--){
		int m;
		scanf("%i",&m);
		vector<int> nodes(m);
		for(int &u:nodes)scanf("%i",&u),mark[u]=1;
		sort(nodes.begin(),nodes.end(),[&](int u,int v){return G.lid[u]<G.lid[v];});
		bool ok=1;
		for(int i=1;i<m;i++)nodes.pb(G.LCA(nodes[i-1],nodes[i]));
		sort(nodes.begin(),nodes.end(),[&](int u,int v){return G.lid[u]<G.lid[v];});
		nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
		stack<int> stk;
		for(int u:nodes){
			while(stk.size() && G.rid[stk.top()]<G.lid[u]){
				int v=stk.top();stk.pop();
				if(stk.size()){
					int w=stk.top();
					V.AddEdge(w,v);
					if(mark[w] && mark[v] && G.par[v][0]==w)ok=0;
				}
			}
			stk.push(u);
		}
		while(stk.size()){
			int v=stk.top();stk.pop();
			if(stk.size()){
				int w=stk.top();
				V.AddEdge(w,v);
				if(mark[w] && mark[v] && G.par[v][0]==w)ok=0;
			}
		}
		printf("%i\n",ok?V.DP(nodes[0],0).first:-1);
		for(int u:nodes)mark[u]=0,V.E[u].clear();
	}
	return 0;
}