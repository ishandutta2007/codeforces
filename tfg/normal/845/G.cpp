#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;

template<const int N, class T = unsigned int>
class XorGauss {
public:
	XorGauss() {
		for(int i = 0; i < N; i++) { a[i] = 0; }
	}
	T reduce(T x) {
		for(int i = N-1; i >= 0; i--) {
			x = std::min(x, x ^ a[i]);
		}
		return x;
	}

	T augment(T x) { return ~reduce(~x); }

	bool add(T x) {
		for(int i = N-1; i >= 0; i--) {
			if((x & (1 << i)) == 0) { continue; }
			if(a[i]) {
				x ^= a[i];
			} else {
				a[i] = x;
				return true;
			}
		}
		return false;
	}
private:
	T a[N];
};

std::vector<std::pair<int, int>> edges[ms];
int h[ms];
bool visit[ms];

XorGauss<31> gauss;

void dfs(int on) {
	assert(!visit[on]);
	visit[on] = true;
	for(auto e : edges[on]) {
		if(!visit[e.first]) {
			h[e.first] = h[on] ^ e.second;
			dfs(e.first);
		} else {
			gauss.add(h[on] ^ h[e.first] ^ e.second);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	while(m--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		edges[a].emplace_back(b, c);
		edges[b].emplace_back(a, c);
	}
	dfs(0);
	std::cout << gauss.reduce(h[n-1]) << '\n';
}