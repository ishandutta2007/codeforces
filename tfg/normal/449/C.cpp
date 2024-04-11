#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> primes[ms];
int group[ms];
bool got[ms];
std::queue<int> q[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> p;
	for(int i = 2; i <= n; i++) {
		p.push_back(i);
		if(!primes[i].empty()) {
			continue;
		}
		for(int j = i; j <= n; j += i) {
			primes[j].push_back(i);
			if(group[j] == 0) group[j] = i;
		}
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return group[v1] > group[v2]; });
	std::vector<std::pair<int, int>> ans;
	auto add = [&](int x) {
		std::reverse(primes[x].begin(), primes[x].end());
		for(auto pp : primes[x]) {
			while(!q[pp].empty() && got[q[pp].front()]) {
				q[pp].pop();
			}
			if(!q[pp].empty()) {
				int y = q[pp].front();
				got[y] = got[x] = true;
				q[pp].pop();
				ans.emplace_back(x, y);
				return;
			}
		}
		for(auto pp : primes[x]) {
			q[pp].push(x);
		}
	};
	for(auto x : p) {
		add(x);
	}
	std::cout << ans.size() << '\n';
	for(auto pp : ans) {
		std::cout << pp.first << ' ' << pp.second << '\n';
	}
}