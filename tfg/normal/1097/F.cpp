#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 7001;

std::bitset<ms> a[100001];
std::bitset<ms> base[ms], other[ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i <= ms; i++) {
		for(int j = i; j <= ms; j += i) {
			base[j][i] = true;
			bool valid = true;
			int x = j / i;
			for(int k = 2; k * k <= x; k++) {
				if(x % k == 0 && x / k % k == 0) {
					valid = false;
					break;
				}
			}
			other[i][j] = valid;
		}
	}
	int n, q;
	std::cin >> n >> q;
	std::string ans;
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			// set x to v
			int x, v;
			scanf("%d %d", &x, &v);
			a[x] = base[v];
		} else if(t == 2) {
			// xor
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			a[x] = a[y] ^ a[z];
		} else if(t == 3) {
			// and
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			a[x] = a[y] & a[z];
		} else if(t == 4) {
			// query for x v
			int x, v;
			scanf("%d %d", &x, &v);
			ans += (char)('0' + (other[v] & a[x]).count() % 2);
		}
	}
	printf("%s\n", ans.c_str());
}