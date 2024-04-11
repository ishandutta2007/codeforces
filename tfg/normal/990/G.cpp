#include <iostream>
#include <vector>

const int ms = 200200;

struct Edge {
	int u, v;
};

int gcd(int a, int b) {
	if(!b) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int step[ms], cur_step = 0;
long long paths = 0;
int size[ms], par[ms];

int getPar(int x) {
	if(step[x] != cur_step) {
		step[x] = cur_step;
		paths++;
		size[x] = 1;
		par[x] = x;
		//std::cout << "fixing " << x << std::endl;
	}
	if(x == par[x]) {
		return x;
	} else {
		return par[x] = getPar(par[x]);
	}
}

void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) {
		return;
	}
	paths += (long long) size[a] * size[b];
	if(size[a] < size[b]) {
		std::swap(a, b);
	}
	size[a] += size[b];
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::vector<int>> verts(ms);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		verts[a[i]].push_back(i);
		//std::cout << "got vert " << i << " with num " << a[i] << std::endl;
	}
	std::vector<std::vector<Edge>> edges(ms);
	for(int i = 1; i < n; i++) {
		Edge cur;
		std::cin >> cur.u >> cur.v;
		cur.u--;cur.v--;
		edges[gcd(a[cur.u], a[cur.v])].push_back(cur);
		//std::cout << "adding edge " << cur.v << ", " << cur.u << " with gcd " << gcd(a[cur.u], a[cur.v]) << std::endl;
	}
	std::vector<long long> dp(ms);
	for(int i = 1; i < ms; i++) {
		paths = 0;
		cur_step++;
		//std::cout << "on " << i << std::endl;
		for(int j = i; j < ms; j += i) {
			for(auto v : verts[j]) {
				//std::cout << "num " << j << " got vert " << v << std::endl;
				getPar(v);
			}
			for(auto e : edges[j]) {
				//std::cout << "got edge (" << e.u << ", " << e.v << ")\n";
				makeUnion(e.u, e.v);
			}
		}
		dp[i] = paths;
	}
	for(int i = ms - 1; i > 0; i--) {
		for(int j = i + i; j < ms; j += i) {
			dp[i] -= dp[j];
		}
	}
	for(int i = 0; i < ms; i++) {
		if(dp[i]) {
			std::cout << i << ' ' << dp[i] << std::endl;
		}
	}
}