//http://codeforces.com/problemset/problem/645/D

#include <iostream>
#include <vector>
#include <utility>

std::vector<std::vector<int>> adjlist;
std::vector<int> topo_order;
std::vector<char> visited;

void topo_label (int node) {
	if (visited[node]) return;
	visited[node] = true;
	for (int child : adjlist[node]) topo_label(child);
	topo_order.push_back(node);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int nRobot, nBattle;
	std::cin >> nRobot >> nBattle;
	using battle_t = std::pair<int, int>;
	std::vector<battle_t> battles (nBattle);
	adjlist.assign(nRobot, {});
	for (auto& b : battles) {
		std::cin >> b.first >> b.second;
		--b.first; --b.second;
		adjlist[b.first] .push_back(b.second);
	}
	visited.assign(nRobot, false);
	topo_order.reserve(nRobot);
	for (int node = 0; node < nRobot; ++node) topo_label(node);
	std::vector<int> weaker (nRobot, -1);
	for (int i = 1; i < nRobot; ++i) weaker[topo_order[i]] = topo_order[i-1];
//	for (int i = 0; i < nRobot; ++i) {
//		std::cout << "weaker[" << i << "] = " << weaker[i] << '\n';
//	}
	int n_remaining_edge = nRobot - 1;
	for (int minbattle = 0; minbattle < nBattle; ++minbattle) {
		battle_t b = battles[minbattle];
		if (weaker[b.first] == b.second) --n_remaining_edge;
		if (n_remaining_edge == 0) {
			std::cout << 1+minbattle << '\n';
			goto _return;
		}
	}
	std::cout << "-1\n";
	_return:
	std::cout.flush();
}