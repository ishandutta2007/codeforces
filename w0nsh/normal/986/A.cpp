#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>

const int NMAX = 100000;
const int KMAX = 100;
int n, m;
int k, s;
int type[NMAX+5];
std::vector<std::vector<int> > dist(NMAX+5);
std::vector<std::vector<int> > g(NMAX+5);
std::vector<std::vector<int> > in_type(KMAX+5);
int visited[NMAX+5];

void run_bfs(int t){
	for(int i = 0; i < n; ++i) visited[i] = false;
	std::queue<int> que;
	for(auto ch : in_type[t]){
		que.push(ch);
		visited[ch] = true;
	}
	int to_process = que.size();
	int next = 0;
	int tick = 0;
	while(!que.empty()){
		int cur = que.front();
		que.pop();
		dist[cur].push_back(tick);
		for(auto ch : g[cur]){
			if(visited[ch]) continue;
			next++;
			visited[ch] = true;
			que.push(ch);
		}
		to_process--;
		if(to_process == 0){
			to_process = next;
			next = 0;
			tick++;
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	std::cin >> k >> s;
	for(int i= 0; i < n; ++i){
		std::cin >> type[i];
		type[i]--;
		in_type[type[i]].push_back(i);
	}
	for(int i = 0; i < m; ++i){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0; i < k; ++i) run_bfs(i);
	for(int i = 0; i < n; ++i){
		std::sort(dist[i].begin(), dist[i].end());
		int odp = 0;
		for(int j = 0; j < s; ++j){
			odp += dist[i][j];
		}
		std::cout << odp << " ";
	}
	std::cout << "\n";
	return 0;
}