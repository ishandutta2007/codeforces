#include<bits/stdc++.h>

const int N = 2010;
const int INF = 0x7f7f7f7f;

struct edge{
	int next, to;
};

edge e[N * N];
int e_cnt = 0, first[N], n, k, cnt[N];
bool arr[N];

void addedge(int u, int v){
	if (v < 0 || v >= N){
		return;
	}
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	if (v == N >> 1){
		arr[u] = true;
	}
}

std::queue <int> q;
bool inque[N];
int dis[N];

void spfa(int s){
	memset(dis, 0x7f, sizeof(dis));
	inque[s] = true;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = first[u]; i; i = e[i].next){
			int v = e[i].to;
			if (dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				if (!inque[v]){
					inque[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0, x; i < k; ++ i){
		scanf("%d", &x);
		if (x == n){
			return printf("1\n"), 0;
		}
		++ cnt[x];
	}
	for (int i = 0; i < N; ++ i){
		for (int j = 0; j < N >> 1; ++ j){
			if (cnt[j]){
				addedge(i, i + j - n);
			}
		}
	}
	spfa(N >> 1);
	int min = INT_MAX;
	for (int i = 0; i < N; ++ i){
		if (arr[i]){
			min = std::min(dis[i] + 1, min);
		}
	}
	if (min >= INF + 1){
		min = -1;
	}
	return printf("%d\n", min), 0;
}