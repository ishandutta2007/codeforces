#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 100100;

int p[ms];
bool visit[ms];
std::vector<int> cycles[ms];

int main() {
	int n;
	std::cin >> n;
	int cur = -1;
	for(int i = 1; i <= n; i++) {
		std::cin >> p[i];
		if(p[i] == i) {
			cur = i;
		}
	}
	if(cur != -1) {
		std::cout << "YES\n";
		for(int i = 1; i <= n; i++) {
			if(i != cur) {
				std::cout << i << " " << cur << "\n";
			}
		}
		return 0;
	}
	int min = n + 1;
	for(int i = 1; i <= n; i++) {
		if(visit[i]) {
			continue;
		}
		cur = i;
		int size = 0;
		while(!visit[cur]) {
			visit[cur] = true;
			size++;
			cur = p[cur];
		}
		cycles[size].push_back(i);
		min = std::min(size, min);
	}
	int got = 0;
	for(int i = min; i <= n; i += min) {
		got += cycles[i].size() * i;
	}
	if(got != n || min > 2) {
		std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n";
	int first = cycles[min].back();
	cur = first;
	cycles[min].pop_back();
	for(int i = 0; i + 1 < min; i++) {
		std::cout << cur << " " << p[cur] << '\n';
		cur = p[cur];
	}
	for(int i = min; i <= n; i += min) {
		for(auto v : cycles[i]) {
			cur = first;
			int second = v;
			for(int j = 0; j < i; j++) {
				std::cout << second << ' ' << cur << '\n';
				cur = p[cur];
				second = p[second];
			}
		}
	}
}