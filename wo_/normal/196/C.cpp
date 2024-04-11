#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<long long, long long> Point;
typedef pair<Point, int> P;

P ps[1500];
int ans[1500];
vector<int> G[1500];
int N;

int par[1500];
int sz[1500];

void dfs(int v,int p){
	par[v]=p;
	sz[v]=1;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs(u,v);
		sz[v]+=sz[u];
	}
}

P center;

bool cmp(const P &p1_,const P &p2_){
	Point p1=p1_.first;
	Point p2=p2_.first;
	Point center=::center.first;
	long long dx1=p1.first-center.first;
	long long dy1=p1.second-center.second;
	long long dx2=p2.first-center.first;
	long long dy2=p2.second-center.second;
	return dx1*dy2-dx2*dy1>0;
}

void solve(int v,int l,int r){
	sort(ps+l,ps+r);
	ans[ps[l].second]=v;
	center=ps[l];
	sort(ps+l+1,ps+r,cmp);
	int cur_l=l+1;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==par[v]) continue;
		solve(u,cur_l,cur_l+sz[u]);
		cur_l+=sz[u];
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ps[i]=P(Point(x,y),i);
	}
	dfs(0,-1);
	solve(0,0,N);
	for(int i=0;i<N;i++){
		printf("%d%c",ans[i]+1,i==N-1?'\n':' ');
	}
	return 0;
}