#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	long long gap, sum, best;
	long long bestSum;

	Node(long long a, long long b, long long c, long long d) {
		gap = a, sum = b, best = c, bestSum = d;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, A;
	std::cin >> n >> A;
	std::vector<Node> nodes;
	nodes.emplace_back(1.1e9, -1e18, -1e18, -1e18);
	auto add = [&](Node node) {
		while(nodes.back().gap <= node.gap) {
			long long best = std::max(node.best, node.sum + nodes.back().best);
			node = Node(node.gap, node.sum + nodes.back().sum, best, -1);
			nodes.pop_back();
		}
		nodes.emplace_back(node.gap, node.sum, node.best, std::max(nodes.back().bestSum + node.sum, node.best - node.gap * node.gap));
	};
	int last = -1;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int d, c;
		std::cin >> d >> c;
		if(i) {
			auto node = nodes.back();
			nodes.pop_back();
			node.gap = std::max(node.gap, (long long) d-last);
			add(node);
		}
		add(Node(0, A-c, A-c, -1));
		ans = std::max(ans, nodes.back().bestSum);
		//std::cout << "at " << i << " got " << nodes.back().bestSum << '\n';
		last = d;
	}
	std::cout << ans << '\n';
}