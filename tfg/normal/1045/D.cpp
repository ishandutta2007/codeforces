#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef double ld;

const int ms = 100100;

std::vector<int> edges[ms];
int up[ms];
void pre(int on, int par = -1) {
	up[on] = par;
	//std::cout << "on (" << on << ", " << par << ")\n";
	for(auto to : edges[on]) {
		if(to == par) continue;
		pre(to, on);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::cout << std::fixed << std::setprecision(12);
	std::vector<ld> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		//other += p[u] * p[v];
		//sum += p[u] + p[v];
	}
	std::vector<ld> down(n, 0);
	pre(0);
	for(int i = 1; i < n; i++) {
		down[up[i]] += 1 - p[i];
	}
	ld ans = 0;
	for(int i = 1; i < n; i++) {
		ans += (1 - p[i]) * p[up[i]];
	}
	ans += 1 - p[0];
	//std::cout << "at first, it is " << ans << "\n";
	int q;
	std::cin >> q;
	while(q--) {
		int x;
		ld newP;
		std::cin >> x >> newP;
		// solve for down
		ans += down[x] * (newP - p[x]);
		// solve for up
		if(x > 0) {
			ld hmm = p[up[x]];
			ans -= hmm * (newP - p[x]);
			down[up[x]] -= newP - p[x];
		} else {
			ans -= newP - p[x];
		}
		p[x] = newP;
		std::cout << ans << '\n';
	}
}