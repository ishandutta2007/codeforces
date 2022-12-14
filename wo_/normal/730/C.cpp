#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> PP;

vector<int> G[5050];
int N;
vector<P> stores[5050]; //<price, num>

int dis[5050];

void bfs(int s){
	for(int i = 0; i < 5050; ++i) dis[i] = 5050;
	dis[s] = 0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v = que.front();
		que.pop();
		for(int i = 0; i < G[v].size(); ++i){
			int u = G[v][i];
			if(dis[u] <= dis[v] + 1) continue;
			dis[u] = dis[v] + 1;
			que.push(u);
		}
	}
}

//P ps[5050];

int W;
PP pps[5050];//<<price, num>, id>

bool check(int D, int num, long long budget){
	//int c = 0;
	/*for(int v = 0; v < N; ++v){
		if(dis[v] <= D){
			for(int j = 0; j < stores[v].size(); ++j){
				ps[c++] = stores[v][j];
			}
		}
	}
	sort(ps, ps + c);*/
	long long got = 0;
	long long money = 0;
	//for(int i = 0; i < c; ++i){
	for(int i = 0; i < W; ++i){
		if(dis[pps[i].second] > D) continue;
		long long cur_num = min(num - got, (long long)pps[i].first.second);
		money += cur_num * pps[i].first.first;
		got += cur_num;
	}
	return (got == num) && (money <= budget);
}

int solve(int g, int r, int a){
	bfs(g);
	bool flg = check(N, r, a);
	if(!flg){
		return -1;
	}
	int lb = -1, ub = N;
	while(ub - lb > 1){
		int mid = (ub + lb) / 2;
		bool flg = check(mid, r, a);
		if(flg) ub = mid;
		else lb = mid;
	}
	return ub;
}

int Q;
int gs[1010], rs[1010], as[1010];

void input(){
	int M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d", &W);
	for(int i = 0; i < W; ++i){
		int c, k, p;
		scanf("%d%d%d", &c, &k, &p);
		c--;
		stores[c].push_back(P(p, k));
		pps[i] = PP(P(p, k), c);
	}
	sort(pps, pps + W);
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		scanf("%d%d%d", gs + i, rs + i, as + i);
		gs[i]--;
	}
}

int main(){
	input();
	for(int i = 0; i < Q; ++i){
		int ans = solve(gs[i], rs[i], as[i]);
		printf("%d\n", ans);
	}
	return 0;
}