#include<cstdio>
#include<vector>
#include<utility>
#include<queue>	
#include<algorithm>

using namespace std;


template<class T> struct Dinic{
	static const int MAX_N = 100100;
	const T inf = 1e9;
	struct Edge{
		int to;
		int rev;
		T cap;
		Edge(){}
		Edge(int a, int b, T c):to(a), rev(b), cap(c){}
	};
	vector<Edge> G[MAX_N];
	int N;
	void add_edge(int from, int to, T cap){
		if(from == to) return;
		G[from].push_back(Edge(to, G[to].size(), cap));
		G[to].push_back(Edge(from, (int)G[from].size() - 1, 0));
	}
	void add_uedge(int from, int to, T cap){
		if(from == to) return;
		G[from].push_back(Edge(to, G[to].size(), cap));
		G[to].push_back(Edge(from, (int)G[from].size() - 1, cap));
	}
	int level[MAX_N];
	int iter[MAX_N];
	T dfs(int s, int u, T c){
		if(s == u || c == 0) return c;
		T res = 0;
		for(int &i = iter[u]; i < G[u].size(); ++i){
			Edge &e = G[u][i];
			int v = e.to;
			Edge &re = G[v][e.rev];
			if(level[u] != level[v] + 1 || re.cap <= 0) continue;
			T f = dfs(s, v, min(c - res, re.cap));
			if(f <= 0) continue;
			re.cap -= f;
			e.cap += f;
			res += f;
			if(res == c) break;
		}
		return res;
	}
	T max_flow(int s, int t){
		T res = 0;
		if(N == 0){
			fprintf(stderr, "N = 0\n");
			return 0;
		}
		while(true){
			queue<int> que;
			for(int i = 0; i < N; ++i){
				level[i] = -1;
			}
			level[s] = 0;
			que.push(s);
			while(!que.empty()){
				int v = que.front();
				int d = level[v];
				que.pop();
				for(int i = 0; i < G[v].size(); ++i){
					if(G[v][i].cap <= 0) continue;
					int nv = G[v][i].to;
					if(level[nv] == -1){
						level[nv] = d + 1;
						que.push(nv);
					}
				}
			}
			if(level[t] == -1) return res;
			for(int i = 0; i < N; ++i) iter[i] = 0;
			res += dfs(s, t, inf);
		}
		return res;
	}
};

Dinic<int> fl;

int cnt[10100];
int nxt[10100];
int ids[10100];

int upto[10100];
int quan[10100];

int N, B, Q;

void input(){
	scanf("%d%d%d", &N, &B, &Q);
	for(int i = 0; i < Q; ++i){
		scanf("%d%d", upto + i, quan + i);
	}
}

bool solve(){
	for(int i = 0; i <= B; ++i){
		cnt[i] = -1;
		nxt[i] = -1;
	}
	for(int i = 0; i < Q; ++i){
		int u = upto[i], q = quan[i];
		if(cnt[u] != -1 && cnt[u] != q){
			return false;
		}
		cnt[u] = q;
	}
	if(cnt[B] != -1 && cnt[B] != N) return false;
	cnt[B] = N;
	int prv = B;
	for(int i = B; i >= 1; --i){
		if(cnt[i] != -1) prv = i;
		nxt[i] = prv;
	}
	prv = 0;
	for(int i = 1; i <= B; ++i){
		if(cnt[i] != -1){
			if(cnt[i] < prv) return false;
			int tmp = cnt[i];
			cnt[i] -= prv;
			prv = tmp;
		}
	}
	Q = 0;
	for(int i = 0; i <= B; ++i){
		if(cnt[i] != -1){
			ids[i] = Q++;
		}
	}
	fl.N = B + Q + 7;
	for(int i = 0; i < 5; ++i){
		fl.add_edge(0, B + Q + i + 1, N / 5);
	}
	for(int i = 1; i <= B; ++i){
		int id = i % 5;
		int u = B + Q + 1 + id;
		fl.add_edge(u, i, 1);
	}
	for(int i = 1; i <= B; ++i){
		int id = B + 1 + ids[nxt[i]];
		fl.add_edge(i, id, 1);
	}
	for(int i = 1; i <= B; ++i){
		if(ids[i] != -1){
			int c = cnt[i];
			fl.add_edge(B + ids[i] + 1, B + Q + 6, c);
		}
	}
	int f = fl.max_flow(0, B + Q + 6);
	return f == N;
}

int main(){
	input();
	bool flg = solve();
	if(flg){
		printf("fair\n");
	}else{
		printf("unfair\n");
	}
	return 0;
}