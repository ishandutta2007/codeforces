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
#include <cstdlib>

int n, d, k;
std::vector<std::pair<int, int> > edges;

std::vector<int> ava;
std::vector<int> deg;
std::vector<int> parent;

std::vector<std::vector<int> > g;

void fail(){
	std::printf("NO\n");
	std::exit(0);
}

void add_edge(int a, int b){
	edges.push_back(std::make_pair(a, b));
	g[a].push_back(b);
	g[b].push_back(a);
	parent[b] = a;
}

void answer(){	
	if(d >= n) fail();
	ava.resize(n);
	parent.resize(n);
	g.resize(n);
	parent[0] = -1;
	for(int i = 0; i < d; ++i){
		add_edge(i, i+1);
		if(g[i].size() > k) fail();
	}
	for(int i = d; i >= 0; --i){
		ava[i] = std::min(d-i, i);
	}
	int need = n - d - 1;
	int cur = d;
	int cur_free = d+1;
	while(need > 0 && cur != -1){
		if(ava[cur] == 0 || g[cur].size() >= k){
			cur = parent[cur];
			continue;
		}
		add_edge(cur, cur_free);
		ava[cur_free] = ava[cur] - 1;
		cur = cur_free;
		cur_free++;
		need--;
	}
	if(cur == -1) fail();
	std::printf("YES\n");
	for(auto &p : edges){
		std::printf("%d %d\n", p.first+1, p.second+1);
	}
}

void read(){
	std::scanf("%d%d%d", &n, &d, &k);
}

int main(){
	read();
	answer();
	return 0;
}