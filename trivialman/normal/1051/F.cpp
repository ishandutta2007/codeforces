#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
#define N 100010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define CL(x) memset(x,0,sizeof(x))

struct GNode{int to;LL d;};
struct Edge{
	int from,to;
	bool operator<(Edge x)const{return this->from<x.from||this->from==x.from&&this->to<x.to;}
};
vector<GNode> g[N];
set<Edge> outedge;
int prior[N][20],tin[N],tout[N],I=0;
bool visited[N];
LL h[N],d[30][N];
int n,m,q;

void dfs(int v){
	tin[v]=++I;
	visited[v]=true;
	for(int i=0;prior[v][i]>=0;++i)prior[v][i+1]=prior[prior[v][i]][i];
	for(auto e:g[v]){
		if(!visited[e.to]){
			prior[e.to][0]=v;
			h[e.to]=h[v]+e.d;
			outedge.erase(Edge{min(e.to,v),max(e.to,v)});
			dfs(e.to);
		}
	}
	tout[v]=I;
}

struct cmp{
	bool operator()(GNode x,GNode y)const{
		return x.d>y.d;
	}
};
void dij(int v, LL d[N]){
	rep(i,1,n)d[i]=1e18;
	priority_queue<GNode,vector<GNode>,cmp> nowD;
	nowD.push(GNode{v,0});d[v]=0;
	while(!nowD.empty()){
		GNode tmp=nowD.top();
		nowD.pop();
		if(d[tmp.to]<tmp.d)continue;
		for(auto e:g[tmp.to]){
			if(d[e.to]>tmp.d+e.d){
				d[e.to]=tmp.d+e.d;
				nowD.push({e.to,d[e.to]});
			}
		}
	}
}

bool isAncestor(int x,int y){
	return tin[x]<=tin[y]&&tout[x]>=tout[y];
}
int getLCA(int x,int y){
	if(isAncestor(x,y))return x;
	if(isAncestor(y,x))return y;
	for(int i=19;i>=0;--i){//for;i; 
		int p=prior[x][i];
		if(p>=0&&!isAncestor(p,y))x=p;
	}
	return prior[x][0];
}

int main(){
	CL(g);
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(GNode{y,z});
		g[y].push_back(GNode{x,z});
		if(x>y)swap(x,y);
		outedge.insert(Edge{x,y});
	}
	
	CL(visited);CL(h);
	memset(prior,-1,sizeof(prior));
	dfs(1);//build spanning tree
	int outnum=0;
	for(auto e:outedge)dij(e.from,d[++outnum]);
	
	scanf("%d",&q);
	rep(qs,1,q){
		int x,y;
		scanf("%d%d",&x,&y);
		int lca=getLCA(x,y);
		LL ans=h[x]+h[y]-(h[lca]<<1);
		rep(i,1,outnum)ans=min(ans,d[i][x]+d[i][y]);
		printf("%lld\n",ans);
	}
	return 0;
}