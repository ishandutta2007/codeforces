#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdio>
#include <queue>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

std::vector<int> edges[ms];
std::set<int> other[ms];

int n, k;
int par[ms];
int rep[ms];
int cost[ms];
int getPar(int x) {
	return x == rep[x] ? x : rep[x] = getPar(rep[x]);
}

void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	rep[a] = b;
}

int dp[ms];

void dfs(int on) {
	other[on].erase(on);
	for(auto to : other[on]) {
		dfs(to);
		//std::cout << "from " << on + 1 << " to " << to + 1 << std::endl;
		dp[on] = std::max(dp[on], dp[to]);
	}
	//std::cout << "base for " << on + 1 << " is " << dp[on] << std::endl;
	dp[on] += cost[on];
	//std::cout << "base for " << on + 1 << " is " << dp[on] << std::endl;
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> k;
	if(n == 1) {
		std::cout << "0\n";
		return 0;
	}
	par[0] = -1;
	for(int i = 1; i < n; i++) {
		int u;
		scanf("%d", &u);
		u--;
		edges[u].push_back(i);
		par[i] = u;
	}
	for(int i = 0; i < n; i++) {
		rep[i] = i;
	}
	{
		std::queue<int> q;
		q.push(0);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			//std::cout << "visiting " << on + 1 << std::endl;
			if(edges[on].size() == 0) {
				int ori = on;
				//std::cout << "is leaf\n";
				for(int i = 0; i < k; i++) {
					on = par[on];
					if(on == -1 || getPar(on) == getPar(ori)) break;
					//std::cout << "uniting with " << on + 1 << std::endl;
					makeUnion(on, ori);
				}
			} else {
				for(auto to : edges[on]) {
					q.push(to);
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		//std::cout << i + 1 << " got rep " << getPar(i) + 1 << std::endl;
		if(edges[i].size() == 0) {
			cost[getPar(i)]++;
		}
		for(auto to : edges[i]) {
			other[getPar(i)].insert(getPar(to));
		}
		other[getPar(i)].erase(getPar(i));
	}
	for(int i = 0; i < n; i++) {
		if(cost[i]) {
			//std::cout << "cost for " << i + 1 << " is " << cost[i] << std::endl;
		}
	}
	dfs(getPar(0));
	std::cout << dp[getPar(0)] << std::endl;
}