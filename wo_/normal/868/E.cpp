#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int dp[55][55][55][55];

vector<int> G[55];
bool isL[55];
int N;

int cnt[55];
int M;

int S;

int dis[55][55];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N - 1; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
		dis[u][v] = w;
		dis[v][u] = w;
	}
	for(int i = 0; i < N; ++i){
		isL[i] = (G[i].size() == 1);
	}
	scanf("%d", &S);
	S--;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int x;
		scanf("%d", &x);
		x--;
		cnt[x]++;
	}
}

const int inf = 1e9;

int rec(int u, int v, int x, int y){
//	printf("%d %d %d %d\n", u, v, x, y);
	if(x == 0 && y == 0) return 0;
	if(dp[u][v][x][y] != -1) return dp[u][v][x][y];
	if(y == 0) return inf;
	if(isL[v]){
		int nxt = rec(v, u, 0, x);
		dp[u][v][x][y] = nxt + dis[u][v];
	//	printf("zero %d %d %d %d %d\n", u, v, x, y, dp[u][v][x][y]);
		return dp[u][v][x][y];
	}/*
	vector<vector<int> > tmp;
	for(int i = 0; i < G[v].size(); ++i){
		int w = G[v][i];
		if(w == u) continue;
		vector<int> vec;
		vec.push_back(0);
		for(int j = 1; j <= y; ++j){
			int k = x + y - j;
			int cur = rec(v, w, k, j);
			vec.push_back(cur);
		}
		printf("%d %d %d %d:\n", u, v, x, y);
		printf("vec%d: ", w);
		for(int j = 0; j <= y; ++j){
			printf("%d ", vec[j]);
		}
		printf("\n");
		tmp.push_back(vec);
	}
	int lb = 0, ub = 3000;
	while(ub - lb > 1){
		int mid = (ub + lb) / 2;
		int sum = 0;
		for(int i = 0; i < tmp.size(); ++i){
			vector<int> &vec = tmp[i];
			int id = lower_bound(vec.begin(), vec.end(), mid) - vec.begin();
//			if(mid == 1) printf("one %d\n", id);
			if(id == vec.size()) sum = inf;
			sum += id;
		}
		if(mid == 1) printf("one %d\n", sum);
		if(sum <= y){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	dp[u][v][x][y] = lb + dis[u][v];
	printf("%d %d %d %d %d %d\n", u, v, x, y, lb, lb + dis[u][v]);
	return lb + dis[u][v];*/
	int dp[55][55] = {};
	dp[0][0] = inf;
	int i = 0;
	for(int id = 0; id < G[v].size(); ++id){
		int w = G[v][id];
		if(w == u) continue;
		for(int j = 0; j <= y; ++j){
			int k = x + y - j;
			int cur = rec(v, w, k, j);
			for(int a = 0; a <= y - j; ++a){
				dp[i + 1][a + j] = max(dp[i + 1][a + j], min(dp[i][a], cur));
			}
		}
		i++;
	}/*
	if(u == 1 && v == 0 && x == 0 && y == 1){
		for(int i = 0; i < G[v].size(); ++i){
			for(int j = 0; j <= 5; ++j){
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}
	}*/
	int ans = dp[G[v].size() - 1][y];
	ans += dis[u][v];
	::dp[u][v][x][y] = ans;
	//printf("%d %d %d %d %d\n", u, v, x, y, ans);
	return ans;
}

void dfs(int v, int p){
	for(int i = 0; i < G[v].size(); ++i){
		int u = G[v][i];
		if(u == p) continue;
		dfs(u, v);
		cnt[v] += cnt[u];
	}
}

void init(){
	for(int u = 0; u < N; ++u){
		for(int v = 0; v < N; ++v){
			for(int x = 0; x <= M; ++x){
				for(int y = 0; y <= M; ++y){
					if(y == 0){
						dp[u][v][x][y] = -1;
					}else{
						dp[u][v][x][y] = -1;
					}
				}
			}
		}
	}
}

int solve(){
	init();
	dfs(S, -1);
	int ans = inf;
	for(int i = 0; i < G[S].size(); ++i){
		int v = G[S][i];
		int y = cnt[v];
		int x = M - y;
		int cur = rec(S, v, x, y);
	//	printf("solve %d %d %d %d %d\n", S, v, x, y, cur);
		if(ans > cur) ans = cur;
	}
	return ans;
}

int main(){
	input();
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}