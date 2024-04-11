#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int n;
int ans[ms];
int a[ms];
bool visit[ms][5];

void dfs(int on, int v) {
	if(on == n) {
		for(int i = 0; i < n; i++) {
			std::cout << ans[i]+1 << (i + 1 == n ? '\n' : ' ');
		}
		exit(0);
	}
	if(visit[on][v]) return;
	visit[on][v] = true;
	ans[on] = v;
	if(a[on] > a[on+1]) {
		for(int i = 0; i < v; i++) {
			dfs(on+1, i);
		}
	} else if(a[on] < a[on+1]) {
		for(int i = v+1; i < 5; i++) {
			dfs(on+1, i);
		}
	} else {
		for(int i = 0; i < 5; i++) {
			if(i != v) {
				dfs(on+1, i);
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < 5; i++) {
		dfs(0, i);
	}
	std::cout << "-1\n";
}