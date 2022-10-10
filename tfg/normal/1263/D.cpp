#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int par[26], size[26];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return;
	size[a] += size[b];
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int ans = n;
	for(int i = 0; i < 26; i++) {
		par[i] = i;
	}
	while(n--) {
		std::string str;
		std::cin >> str;
		for(int i = 0; i + 1 < (int) str.size(); i++) {
			makeUnion(str[i] - 'a', str[i+1] - 'a');
		}
		size[getPar(str[0] - 'a')]++;
	}
	ans = 0;
	for(int i = 0; i < 26; i++) {
		if(size[i] != 0 && par[i] == i) {
			//std::cout << "at " << char(i + 'a') << " got " << size[i] << '\n';
			ans++;
		}
	}
	std::cout << ans << '\n';
}