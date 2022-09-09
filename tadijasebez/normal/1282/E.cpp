#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> was;
vector<vector<int>> E;
void AddEdge(int u,int v){E[u].pb(v);E[v].pb(u);}
void DFS(int u){
	was[u]=1;
	for(int v:E[u])if(!was[v])DFS(v);
	printf("%i ",u);
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		E.clear();E.resize(n+1);
		set<pair<int,int>> sgs;
		map<pair<int,int>,vector<int>> two;
		auto Add=[&](int x,int y,int i){
			if(x>y)swap(x,y);
			if(sgs.count({x,y}))sgs.erase({x,y});
			else sgs.insert({x,y});
			two[{x,y}].pb(i);
		};
		for(int i=1;i<=n-2;i++){
			int a,b,c;
			scanf("%i %i %i",&a,&b,&c);
			Add(a,b,i);
			Add(b,c,i);
			Add(c,a,i);
		}
		for(auto s:sgs)AddEdge(s.first,s.second);
		was.clear();was.resize(n+1);
		DFS(1);
		printf("\n");
		E.clear();E.resize(n-1);
		for(auto p:two)if(p.second.size()==2)AddEdge(p.second.front(),p.second.back());
		was.clear();was.resize(n-1);
		DFS(1);
		printf("\n");
	}
}