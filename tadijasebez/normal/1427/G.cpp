#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
const int N=205;
const int H=N*N;
struct Edge{int v,c;Edge(int a,int b):v(a),c(b){}};
vector<Edge> edges;
vector<int> G[H];
void AddEdge(int u,int v,int c){
	G[u].pb(edges.size());edges.pb(Edge(v,c));
	G[v].pb(edges.size());edges.pb(Edge(u,c));
}
bool was[H];
void cl(){for(int i=0;i<H;i++)was[i]=0;}
bool DFS(int u,bool sink[],bool src){
	was[u]=1;
	if(sink[u])return 1;
	for(int e:G[u]){
		if(edges[e].c>0&&!was[edges[e].v]){
			if(src&&edges[e^1].c>0)continue;
			if(DFS(edges[e].v,sink,src)){
				edges[e].c--;
				edges[e^1].c++;
				return 1;
			}
		}
	}
	return 0;
}
bool src[H],sink[H];
int idx[N][N],a[N][N],tot;
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%i",&a[i][j]),idx[i][j]=++tot;
	vector<pii> pts;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j]!=-1){
			if(i<n&&a[i+1][j]!=-1)AddEdge(idx[i][j],idx[i+1][j],1);
			if(j<n&&a[i][j+1]!=-1)AddEdge(idx[i][j],idx[i][j+1],1);
			if(a[i][j]>0)pts.pb({a[i][j],idx[i][j]}),sink[idx[i][j]]=1;
		}
	}
	sort(pts.begin(),pts.end());
	int flow=0;
	ll ans=0;
	for(int i=0;i+1<pts.size();i++){
		while(DFS(pts[i].second,src,1))flow--,cl();
		cl();
		src[pts[i].second]=1;
		sink[pts[i].second]=0;
		for(pii p:pts)if(src[p.second]&&!was[p.second]){
			while(DFS(p.second,sink,0))flow++,cl();
		}
		cl();
		ans+=(ll)flow*(pts[i+1].first-pts[i].first);
	}
	printf("%lld\n",ans);
	return 0;
}