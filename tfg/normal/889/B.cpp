#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> to(26, -1);
	std::vector<int> deg(26, 0);
	std::vector<bool> ha(26, false);
	int n;
	std::cin >> n;
	while(n--) {
		std::string str;
		std::cin >> str;
		for(int i = 0; i + 1 < (int) str.size(); i++) {
			int u = str[i] - 'a';
			int v = str[i+1] - 'a';
			ha[u] = ha[v] = true;
			if(to[u] != -1 && to[u] != v) {
				std::cout << "NO\n";
				return 0;
			}
			if(to[u] == -1) {
				to[u] = v;
				deg[v]++;
			}
		}
		ha[str[0]-'a'] = true;
	}
	std::string ans;
	for(int i = 0; i < 26; i++) {
		if(!ha[i]) continue;
		if(deg[i]) continue;
		for(int j = i; j != -1; j = to[j]) {
			if(!ha[j]) {
				std::cout << "NO\n";
				return 0;
			}
			ha[j] = false;
			ans += char(j + 'a');
		}
	}
	for(int i = 0; i < 26; i++) {
		if(ha[i]) {
			ans = "NO";
		}
	}
	std::cout << ans << '\n';
}