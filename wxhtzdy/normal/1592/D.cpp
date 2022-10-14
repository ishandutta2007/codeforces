#include <bits/stdc++.h>
using namespace std;
const int N=1050;
vector<int> E[N];
vector<pair<int,int>> edges;
void DFS(int u,int p){
	edges.push_back({u,p});
	for(int v:E[u])if(v!=p)DFS(v,u);
}
int Ask(int l,int r){
	set<int> q;
	for(int i=l;i<=r;i++)q.insert(edges[i].first),q.insert(edges[i].second);
	printf("? %i\n",q.size());
	for(int i:q)printf("%i ",i);
	printf("\n");
	fflush(stdout);
	int x;scanf("%i",&x);
	return x;
}
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0);
	int mx=Ask(1,n-1);
	int bot=1,top=n-1;
	while(bot<top){
		int mid=bot+top>>1;
		if(Ask(bot,mid)==mx)top=mid;
		else bot=mid+1;
	}
	printf("! %i %i\n",edges[bot].first,edges[bot].second);
	fflush(stdout);
	return 0;
}