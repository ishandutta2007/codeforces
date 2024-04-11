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

#define PR std::pair
#define X first
#define Y second

int n, m, k;
std::vector<std::vector<PR<int, int> > > g;
struct Node{
	int level;
	std::vector<int> in;
	Node(int lev=-1) : level(lev) {}
};
std::vector<Node> nodes;
// answer
std::vector<int> state;

void calc_nodes(){
	nodes.resize(n);
	nodes[0] = Node(1);
	std::queue<int> que;
	que.push(0);
	int tick = 1;
	int to_process = 1;
	int next = 0;
	while(!que.empty()){
		int cur = que.front();
		que.pop();
		to_process--;
		for(auto ch : g[cur]){
			if(nodes[ch.X].level == -1){
				que.push(ch.X);
//				std::cout << "push " << ch.X +1 << " level " << tick+1 << std::endl;
				next++;
				nodes[ch.X].in.push_back(ch.Y);
				nodes[ch.X].level = tick+1;
			}else if(nodes[ch.X].level > tick){
				nodes[ch.X].in.push_back(ch.Y);
			}
		}
		if(to_process == 0){
			to_process = next;
			next = 0;
			tick++;
		}
	}
}

std::vector<PR<std::vector<int>*, int> > change;
std::vector<std::string> odp;

void answer(){
	state.resize(m);
	for(int i = 1; i < n; ++i){
		if(nodes[i].in.size() == 1) state[nodes[i].in[0]] = 1;
		else{
			change.push_back({&(nodes[i].in), 0});
			state[nodes[i].in[0]] = 2;
			for(int j = 1; j < nodes[i].in.size(); ++j){
				state[nodes[i].in[j]] = 0;
			}
		}
	}
	odp.emplace_back();
	for(int i = 0; i < m; ++i){
		if(state[i] > 0) odp.back().push_back('1');
		else odp.back().push_back('0');
	}

	int pos = change.size()-1;
	if(pos < 0) return;
	for(int i = 3; i < k+2; ++i){
		while(++change[pos].Y >= change[pos].X->size()){
			change[pos].Y = 0;
			pos--;
			if(pos == -1) return;
		}
		pos = change.size()-1;
		odp.emplace_back();
		for(auto pr : change){
			state[(*pr.X)[pr.Y]] = i;
		}
		for(auto val : state){
			if(val == 1 || val == i) odp.back().push_back('1');
			else odp.back().push_back('0');
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	g.resize(n);
	for(int i = 0; i < m; ++i){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	calc_nodes();
	answer();
	std::cout << odp.size() << "\n";
	for(const auto &str : odp){
		std::cout << str << "\n";
	}
	return 0;
}