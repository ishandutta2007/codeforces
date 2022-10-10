#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	if(n == 4 || k <= n) {
		std::cout << "-1\n";
	} else {
		int verts[4];
		std::vector<bool> wtf(n, false);
		for(int i = 0; i < 4; i++) {
			std::cin >> verts[i];
			verts[i]--;
			wtf[verts[i]] = true;
		}
		std::vector<int> path(n, -1);
		for(int i = 0, j = 2; i < n; i++) {
			if(!wtf[i]) {
				path[j++] = i;
			}
		}
		for(int rep = 0; rep < 2; rep++) {
			path[0] = verts[rep*2];
			path[n-1] = verts[rep*2+1];
			path[1] = verts[(rep^1)*2];
			path[n-2] = verts[(rep^1)*2+1];
			for(int i = 0; i < n; i++) {
				std::cout << path[i]+1 << (i + 1 == n ? '\n' : ' ');
			}
		}
	}
}