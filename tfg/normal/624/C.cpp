#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const int ms = 500;

std::vector<int> edges[ms], check[ms];
char a[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int got = -1;
	for(int i = 0; i < n; i++) {
		edges[i].push_back(i);
		std::sort(edges[i].begin(), edges[i].end());
		if(edges[i].size() == n) {
			a[i] = 'b';
			continue;
		}
		if(got == -1) {
			got = i;
		}
		if(edges[i] == edges[got]) {
			a[i] = 'a';
		} else {
			a[i] = 'c';
		}
	}
	bool valid = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i] - a[j] == 0 || a[i] - a[j] == 1 || a[i] - a[j] == -1) {
				check[i].push_back(j);
			}
		}
		valid = valid && check[i] == edges[i];
	}
	if(valid) {
		std::cout << "Yes\n";
		for(int i = 0; i < n; i++) {
			std::cout << a[i];
		}
		std::cout << '\n';
	} else {
		std::cout << "No\n";
	}
}