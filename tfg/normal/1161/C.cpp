#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::map<std::vector<int>, int> memo;

int curStep = 0, step[ms];

int dp(std::vector<int> a) {
	int n = (int) a.size();
	std::sort(a.begin(), a.end());
	if(a[n/2] == 0) {
		return 0;
	}
	if(memo.count(a)) return memo[a];
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) continue;
		for(int j = i + 1; j < n; j++) {
			auto b = a;
			for(int v1 = 0; v1 < a[i]; v1++) {
				for(int v2 = 0; v2 < a[i]; v2++) {
					b[i] = v1;
					b[j] = v2;
					dp(b);
				}
			}
		}
	}
	curStep++;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) continue;
		for(int j = i + 1; j < n; j++) {
			auto b = a;
			for(int v1 = 0; v1 < a[i]; v1++) {
				for(int v2 = 0; v2 < a[i]; v2++) {
					b[i] = v1;
					b[j] = v2;
					step[dp(b)] = curStep;
				}
			}
		}
	}
	int ans = 0;
	while(step[ans] == curStep) ans++;
	if(ans == 0) {
		for(auto i : a) {
			std::cout << i << ' ';
		}
		std::cout << " is losing" << std::endl;
	}
	return memo[a] = ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	while(std::cin >> n) {
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		std::cout << (a[n/2] == a[0] ? "Bob\n" : "Alice\n");
	}
}