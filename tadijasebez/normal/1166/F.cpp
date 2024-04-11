#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=500050;
int my[N];
set<int> cmp[N];
struct DSU{
	int p[N];
	vector<int> all[N];
	void init(int n){for(int i=1;i<=n;i++)p[i]=i,all[i].pb(i),cmp[my[i]].insert(i);}
	DSU(){}
	void Add(int x){all[x]={x};p[x]=x;cmp[my[x]].insert(x);}
	int Find(int x){return p[x]==x?x:p[x]=Find(p[x]);}
	void Union(int x,int y){
		x=Find(x);y=Find(y);
		if(x==y)return;
		if(all[x].size()>all[y].size())swap(x,y);
		for(int i:all[x])cmp[my[i]].erase(x),cmp[my[i]].insert(y),all[y].pb(i);
		all[x].clear();
		p[x]=y;
	}
}DS;
map<int,int> node[N];
int tsz,las[N],fir[N];
void AddEdge(int u,int v,int c){
	if(!node[u][c])node[u][c]=++tsz,my[tsz]=u,DS.Add(tsz);
	if(!node[v][c])node[v][c]=++tsz,my[tsz]=v,DS.Add(tsz);
	DS.Union(fir[u],node[v][c]);
	DS.Union(fir[v],node[u][c]);
}
int main(){
	int n,m,c,q;
	scanf("%i %i %*i %i",&n,&m,&q);
	for(int i=1;i<=n;i++)fir[i]=++tsz,my[tsz]=i;
	DS.init(n);
	for(int i=1,u,v,c;i<=m;i++)scanf("%i %i %i",&u,&v,&c),AddEdge(u,v,c);
	while(q--){
		char t;int u,v,c;
		scanf("\n%c %i %i",&t,&u,&v);
		if(t=='?'){
			if(cmp[v].count(DS.Find(u)))printf("Yes\n");
			else printf("No\n");
		}else{
			scanf("%i",&c);
			AddEdge(u,v,c);
		}
	}
	return 0;
}