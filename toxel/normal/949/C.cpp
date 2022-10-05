#include<bits/stdc++.h>

const int N = 200010;

int x[N];

const int max_N = 200010;

std::vector <int> vec[max_N + 21];
int dfn[max_N + 21], low[max_N + 21], cnt;
int sccno[max_N + 21], scc_cnt;
std::stack <int> st;
int deg[max_N], ccnt[max_N];

void dfs(int x){
	st.push(x);
	dfn[x] = low[x] = ++ cnt;
	for(auto &y : vec[x]){
		if(!dfn[y]){
			dfs(y);
			low[x] = std::min(low[x], low[y]);
		}
		else if(!sccno[y]){
			low[x] = std::min(low[x], dfn[y]);	
		}
	}
	if(dfn[x] == low[x]){
		sccno[x] = ++ scc_cnt;
		while (st.top() != x){
			sccno[st.top()] = scc_cnt;
			st.pop();
		}
		st.pop();
	}
}

int main(){
	int n, m, h;
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &x[i]);
	}
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		if (x[u] == (x[v] + 1) % h){
			vec[v].push_back(u);
		}
		if ((x[u] + 1) % h == x[v]){
			vec[u].push_back(v);
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (!dfn[i]){
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (auto u : vec[i]){
			if (sccno[u] != sccno[i]){
				++ deg[sccno[i]];
			}
		}
		++ ccnt[sccno[i]];
	}
	int min = INT_MAX, sit;
	for (int i = 1; i <= scc_cnt; ++ i){
		if (!deg[i]){
			if (min > ccnt[i]){
				min = ccnt[i];
				sit = i;
			}
		}
	}
	printf("%d\n", min);
	for (int i = 1; i <= n; ++ i){
		if (sccno[i] == sit){
			printf("%d ", i);
		}
	}
	putchar('\n');
	return 0;
}