#include<cstdio>
#include<vector>

using namespace std;

struct Edge{
	int to;
	bool is_positive;
	Edge(){}
	Edge(int a, bool b):to(a), is_positive(b){}
};

int M, N;
vector<int> raw[200200];
vector<Edge> G[400400];

bool visited[400400];
bool satisfied[400400];
bool ans[200200];

void dfs(int v, int p){
	if(visited[v]){
		return;
	}
	visited[v] = true;
	for(int i = 0; i < G[v].size(); ++i){
		int u = G[v][i].to;
		if(u == p) continue;
		dfs(u, v);
	}
	if(v < M){//var
		int nxt = -1;
		for(int i = 0; i < G[v].size(); ++i){
			if(G[v][i].to != p){
				nxt = G[v][i].to;
				break;
			}
		}
		int target = nxt == -1 ? p : nxt;
		if(satisfied[nxt]) target = p;
		for(int i = 0; i < G[v].size(); ++i){
			if(G[v][i].to == target){
				ans[v] = G[v][i].is_positive;
			}
		}
		for(int i = 0; i < G[v].size(); ++i){
			if(G[v][i].is_positive == ans[v]){
				satisfied[G[v][i].to] = true;
			}
		}
	}
}

void getGraph(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < raw[i].size(); ++j){
			int t = raw[i][j];
			int var = t < 0 ? - t - 1 : t - 1;
			int clo = i;
			bool flg = t > 0;
			G[var].push_back(Edge(clo + M, flg));
			G[clo + M].push_back(Edge(var, flg));
		}
	}
}

void input(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j){
			int v;
			scanf("%d", &v);
			raw[i].push_back(v);
		}
	}
}

int main(){
	input();
	getGraph();
	for(int i = N + M - 1; i >= M; --i){
		if(!visited[i]){
			dfs(i, -1);
		}
	}
	for(int i = M; i < N + M; ++i){
		if(!satisfied[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i = 0; i < M; ++i){
		printf("%d", ans[i] ? 1 : 0);
	}
	printf("\n");
	return 0;
}