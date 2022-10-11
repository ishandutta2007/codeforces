#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <set>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

bool visit[ms];
std::vector<int> edges[ms];

void pre(int on) {
	if(visit[on]) return;
	visit[on] = true;
	for(auto to : edges[on]) {
		pre(to);
	}
}

std::vector<int> cycle;
std::multiset<int> bad[ms];

void fix(int on) {
	while(!edges[on].empty() && bad[on].find(edges[on].back()) != bad[on].end()) {
		bad[on].erase(bad[on].find(edges[on].back()));
		edges[on].pop_back();
	}
}

void eulerCycle(int on) {
	fix(on);
	if(edges[on].empty()) {
		cycle.push_back(on);
		return;
	}
	//std::cout << "starting path from " << on << std::endl;
	std::vector<int> curPath(1, on);
	do {
		fix(curPath.back());
		assert(!edges[curPath.back()].empty());
		int u = curPath.back();
		int v = edges[u].back();
		//std::cout << "to " << v << std::endl;
		edges[u].pop_back();
		curPath.push_back(v);
		bad[v].insert(u);
	} while(curPath.back() != on);
	/*for(auto u : curPath) {
		std::cout << u << ' ';
	}std::cout << std::endl;*/
	for(auto u : curPath) {
		eulerCycle(u);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> uni;
	{
		std::vector< std::pair<int, int> > ed(n-1);
		for(int i = 0; i < n-1; i++) {
			std::cin >> ed[i].first;
			uni.push_back(ed[i].first);
		}
		for(int i = 0; i < n-1; i++) {
			std::cin >> ed[i].second;
			uni.push_back(ed[i].second);
			if(ed[i].first > ed[i].second) {
				std::cout << "-1\n";
				return 0;
			}
		}
		std::sort(uni.begin(), uni.end());
		uni.resize(std::unique(uni.begin(), uni.end()) - uni.begin());
		for(auto &e : ed) {
			e.first = std::lower_bound(uni.begin(), uni.end(), e.first) - uni.begin();
			e.second = std::lower_bound(uni.begin(), uni.end(), e.second) - uni.begin();
			edges[e.first].push_back(e.second);
			edges[e.second].push_back(e.first);
			//std::cout << "(" << e.first << ", " << e.second << ")\n";
		}
	}
	bool valid = true;
	int m = (int) uni.size();
	pre(0);
	std::vector<int> wtf;
	for(int i = 0; i < m; i++) {
		valid = valid && visit[i];
		if(edges[i].size() % 2 == 1) {
			wtf.push_back(i);
		}
	}
	valid = valid && wtf.size() <= 2;
	if(!valid) {
		std::cout << "-1\n";
		return 0;
	}
	//std::cout << "it's valid!" << std::endl;
	//std::cout << wtf.size() << std::endl;
	int r[2] = {-1, -1};
	if(wtf.size() > 0) {
		r[0] = wtf[0];
		r[1] = wtf[1];
		edges[r[0]].push_back(r[1]);
		edges[r[1]].push_back(r[0]);
		//std::cout << "added edge (" << r[0] << ", " << r[1] << ")" << std::endl;
		n++;
	}
	eulerCycle(0);
	//std::cout << "got here!" << std::endl;
	assert(cycle.size() == n);
	int s = 0;
	if(wtf.size() > 0) {
		cycle.pop_back();
		n--;
		while(s < n) {
			if(cycle[s%n] == r[0] && cycle[(s-1+n)%n] == r[1]) break;
			if(cycle[s%n] == r[1] && cycle[(s-1+n)%n] == r[0]) break;
			s++;
		}
	}
	//std::cout << "s is " << s << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << uni[cycle[(s+i)%int(cycle.size())]] << (i + 1 == n ? '\n' : ' ');
	}
}