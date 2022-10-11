#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <set>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const long long INF = 1e12;

std::vector<int> edges[ms];
bool rem[ms];
long long curDist[ms];
int maxDist[ms];
long long w[ms];
int ori[ms];
std::vector<int> wut[ms];

int dfs(int on, int d = 0, int par = -1) {
	int ans = on;
	curDist[on] = d;
	maxDist[on] = std::max(maxDist[on], d);
	for(auto to : edges[on]) {
		if(!rem[to] && to != par) {
			int cand = dfs(to, d + 1, on);
			if(curDist[cand] > curDist[ans]) {
				ans = cand;
			}
		}
	}
	return ans;
}

int dfs2(int on, long long d = 0, int par = -1) {
	int ans = on;
	curDist[on] = d + w[on];
	for(auto to : edges[on]) {
		if(!rem[to] && to != par) {
			int cand = dfs2(to, d + INF, on);
			if(curDist[cand] > curDist[ans]) {
				ans = cand;
			}
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::vector<int> st;
	std::set<int> leaf;
	for(int i = 0; i < n; i++) {
		ori[i] = i;
		if(edges[i].size() == 1) {
			st.push_back(i);
		}
	}
	while(!st.empty()) {
		int on = st.back();
		st.pop_back();
		rem[on] = true;
		assert(edges[on].size() == 1);
		if(edges[edges[on][0]].size() == 2) {
			//std::cout << "bad delete on " << on << "\n";
			if(edges[edges[on][0]][0] == on) {
				edges[edges[on][0]][0] = edges[edges[on][0]][1];
			}
			edges[edges[on][0]].pop_back();
			st.push_back(edges[on][0]);
			w[edges[on][0]] = w[on] + 1;
			ori[edges[on][0]] = ori[on];
		} else {
			//std::cout << "good delete on " << on << "\n";
			leaf.insert(on);
			wut[edges[on][0]].push_back(on);
			std::sort(wut[edges[on][0]].begin(), wut[edges[on][0]].end(), [&](int a, int b) {
				return w[a] > w[b];
			});
			while(wut[edges[on][0]].size() > 2) {
				wut[edges[on][0]].pop_back();
			}
		}
	}
	int root = -1;
	for(int i = 0; i < n; i++) {
		if(!rem[i] && wut[i].size() == 2) {
			root = i;
			w[i] = w[wut[i][0]] + w[wut[i][1]] + 2;
		} else if(!rem[i]) {
			w[i] = 0;
		}
	}
	assert(root != -1);
	dfs(dfs(dfs(root)));
	//std::cout << "root is " << root << "\n";
	for(int i = 0; i < n; i++) {
		if(!rem[i] && maxDist[i] < maxDist[root]) {
			root = i;
		}
	}
	std::vector<int> hmm;
	hmm.push_back(root);
	curDist[root] = w[root];
	for(auto to : edges[root]) {
		if(rem[to]) continue;
		hmm.push_back(dfs2(to, INF, root));
		std::sort(hmm.begin(), hmm.end(), [&](int a, int b) {
			return curDist[a] > curDist[b];
		});
		while(hmm.size() > 2) {
			hmm.pop_back();
		}
	}
	int u = hmm[0], v = hmm[1];
	std::vector<int> v1, v2;
	assert(wut[u].size() == 2 && wut[v].size() == 2);
	for(auto to : wut[u]) {
		v1.push_back(ori[to] + 1);
	}
	for(auto to : wut[v]) {
		v2.push_back(ori[to] + 1);
	}
	std::cout << v1[0] << ' ' << v2[0] << std::endl;
	std::cout << v1[1] << ' ' << v2[1] << std::endl;
}