#include <iostream>
#include <vector>

const int ms = 100100;

std::vector<int> edges[ms];
int size[ms];
int h[ms];

void dfs(int on, int par = -1) {
	size[on] = 1;
	for(auto to : edges[on]) {
		if(to != par) {
			h[to] = h[on] + 1;
			dfs(to, on);
			size[on] += size[to];
		}
	}
}

int u[ms], v[ms], c[ms];

void printFrac(long long up, long long down) {
	std::cout << up / down << '.';
	up %= down;
	for(int i = 0; i < 10; i++) {
		up *= 10;
		std::cout << up / down;
		up %= down;
	}
	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		std::cin >> u[i] >> v[i] >> c[i];
		edges[u[i]].push_back(v[i]);
		edges[v[i]].push_back(u[i]);
	}
	dfs(1);
	long long ans = 0;
	for(int i = 1; i < n; i++) {
		if(h[u[i]] < h[v[i]]) {
			std::swap(u[i], v[i]);
		}
		//std::cout << "edge (" << u[i] << ", " << v[i] << ") with cost " << c[i] << "\n";
		//std::cout << "has " << (n - size[u[i]]) * size[u[i]] << " paths\n";
		ans += (long long) size[u[i]] * (n - size[u[i]]) * c[i];
	}
	int m;
	std::cin >> m;
	while(m--) {
		int i, newC;
		std::cin >> i >> newC;
		ans -= (long long) size[u[i]] * (n - size[u[i]]) * c[i];
		c[i] = newC;
		ans += (long long) size[u[i]] * (n - size[u[i]]) * c[i];
		printFrac(ans * 6, (long long) n * (n - 1));
	}
}