#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <utility>
#include <algorithm>
#include <bitset>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1e5;

std::pair<int, int> pairs[6];
std::vector<std::pair<int, int>> to[4];
int pmask[7], maskCost[1 << 4];
int size[6];
int skip[6];
int cur[6];
int extra[6][3];
std::vector<int> costs[6];
std::bitset<4 * ms> got;

int ans = 0;

void genStates(int id = 0, int on = 0, int curAns = 0, int curMask = 0) {
	if(on == 6) {
		id *= 4;
		assert(id < 4 * ms);
		curAns += maskCost[curMask];
		for(int i = 0; i < 4; i++) {
			if(got[id]) {
				ans = std::max(ans, curAns);
				for(auto e : to[i]) {
					if(cur[e.second] < size[e.second]) {
						got[id + skip[e.second] - i + e.first] = true;
					}
				}
			}
			id++;
		}
	} else {
		id *= (1 + size[on]);
		cur[on] = 0;
		genStates(id, on + 1, curAns, curMask);
		curMask |= pmask[on];
		for(int i = 1; i <= size[on]; i++) {
			cur[on] = i;
			curAns += costs[on][i];
			id++;
			genStates(id, on + 1, curAns + extra[on][i], curMask);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int c = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = i + 1; j < 4; j++) {
			pairs[c] = {i, j};
			size[c] = 0;
			pmask[c] = (1 << i) | (1 << j);
			to[i].emplace_back(j, c);
			to[j].emplace_back(i, c);
			c++;
		}
	}
	int value[4] = {0, 0, 0, 0};
	int n;
	std::cin >> n;
	while(n--) {
		int u, v;
		std::cin >> u >> c >> v;
		if(u > v) {
			std::swap(u, v);
		}
		u--;v--;
		if(u == v) {
			value[u] += c;
			continue;
		}
		int id = 0;
		while(pairs[id] != std::pair<int, int>(u, v)) {
			id++;
		}
		size[id]++;
		costs[id].push_back(c);
	}
	for(int i = 0; i < 4; i++) {
		ans = std::max(ans, value[i]);
	}
	for(int i = 0; i < (1 << 4); i++) {
		for(int j = 0; j < 4; j++) {
			if(i & (1 << j)) {
				maskCost[i] += value[j];
			}
		}
	}
	for(int i = 0; i < 6; i++) {
		costs[i].push_back((int) 1e7);
		std::sort(costs[i].begin(), costs[i].end(), std::greater<int>());
		for(int j = 1; j <= 2; j++) {
			for(int k = j + 1; k + 1 < (int) costs[i].size(); k += 2) {
				extra[i][j] += costs[i][k] + costs[i][k + 1];
			}
		}
		while((int) costs[i].size() > 3) {
			size[i]--;
			costs[i].pop_back();
		}
	}
	skip[5] = 4;
	for(int i = 4; i >= 0; i--) {
		skip[i] = skip[i + 1] * (size[i + 1] + 1);
	}
	for(int i = 0; i < 4; i++) {
		got[i] = true;
	}
	genStates();
	std::cout << ans << std::endl;
}