#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_set>

int n, m;
std::vector<std::vector<int> > g;
int pre_cur;
std::vector<int> low, pre;

int best_answer;

bool is_bridge(int v){
	return (pre[v] == low[v] && v != 0);
}

std::vector<bool> visited;
int answer_dfs(int v){
	visited[v] = true;
	int best[2];
	best[0] = best[1] = 0;
	for(auto &ch : g[v]){
		if(visited[ch]) continue;
		int cand = answer_dfs(ch);
		if(cand > best[0]){
			best[1] = best[0];
			best[0] = cand;
		}else if(cand > best[1]){
			best[1] = cand;
		}
	}
	best_answer = std::max(best[0] + best[1], best_answer);
	return best[0] + (is_bridge(v) ? 1 : 0);
}

void answer(){
	best_answer = 0;
	visited.resize(n);
	answer_dfs(0);
	std::printf("%d\n", best_answer);
}

void low_dfs(int v, int parent=-1){
	pre[v] = pre_cur;
	low[v] = pre_cur++;
	for(auto &ch : g[v]){
		if(ch == parent) continue;
		if(pre[ch] != -1){
			low[v] = std::min(low[v], pre[ch]);
		}else{
			low_dfs(ch, v);
			low[v] = std::min(low[v], low[ch]);
		}
	}
}


void find_bridges(){
	low.resize(n);
	pre.resize(n, -1);
	pre_cur = 0;
	low_dfs(0);
}

void read(){
	std::scanf("%d%d", &n, &m);
	g.resize(n);
	for(int i = 0; i < m; ++i){
		int a, b;
		std::scanf("%d%d", &a, &b);
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

int main(){
	read();
	find_bridges();
	answer();
	return 0;
}