#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct edge{
	int t, f, r;
	edge(int T, int F, int R):t(T), f(F), r(R){}
};

vector<edge> map[10010];
int ed[5001][2];
int n, m;
int edn[5001];

void added(int x, int y, int f){
	map[x].emplace_back(y, f, map[y].size());
	map[y].emplace_back(x, 0, map[x].size()-1);
}


int iter[10010];
int lev[10010];
bool bfs(){
	for(int i=0; i<=n+m+1; i++) lev[i] = iter[i] = 0;
	queue<int> Q;
	Q.emplace(0);
	lev[0] = 1;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(auto &e: map[x]) if(lev[e.t] == 0 && e.f > 0){
			lev[e.t] = lev[x] + 1;
			Q.push(e.t);
		}
	}
	return lev[n+m+1] != 0;
}
int min(int a, int b){return a>b?b:a;}
int dfs(int x, int F){
	
	if(x==n+m+1) return F;
	for(int &i = iter[x]; i<map[x].size(); i++){
		auto &e = map[x][i];
		if(lev[e.t] <= lev[x] || e.f == 0) continue;
		int t = dfs(e.t, min(F, e.f));
		if(t>0){
	//		printf("<<<<%d %d %d\n", x, e.f, map[x][i].f);
			e.f -= t;
			map[e.t][e.r].f += t;
	//		printf("))))%d %d %d\n", x, e.f, map[x][i].f);
			return t;
		}
	}
	return 0;
}

int edm[5010];

int main(){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d%d", &ed[i][0], &ed[i][1]);
	}
	
	for(int i=0; i<=n+m+1; i++) map[i].clear(), iter[i] = 0;
	for(int i=1; i<=m; i++){
		added(0, i, 1);
		added(i, m+ed[i][0], 1);
		edn[i] = map[i].size()-1;
		added(i, m+ed[i][1], 1);
	}
	for(int i=1; i<=n; i++){
		added(m+i, m+n+1, 0);
		edm[i] = map[m+i].size()-1;
	}
	int f = 0;
	int k=0;
	while(f<m){
		int t;
		while(!bfs()){
			k++;
			for(int i=1; i<=n; i++) map[m+i][edm[i]].f++;
		}
		while((t = dfs(0, 100000000)) > 0){
			f+=t;
		}
	}
	
	printf("%d\n", k);
	for(int i=1; i<=m; i++){
		if(map[i][edn[i]].f == 0) printf("%d %d\n", ed[i][0], ed[i][1]);
		else printf("%d %d\n", ed[i][1], ed[i][0]);
	}
	return 0;
}