#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2010;
const int INF = 1e9;

/*int memo[ms][ms];
int to[ms][ms];
bool visit[ms][ms];
int dp(int n, int m) {
	if(n == (int) iso.size() && m == (int) duo.size()) {
		return 0;
	}
	int &ans = memo[n][m];
	if(visit[n][m]) return ans;
	visit[n][m] = true;
	ans = -INF;
	if(n < (int) iso.size()) {
		int curAns = iso[n] - dp(n + 1, m);
		if(curAns > ans) {
			ans = curAns;
			to[n][m] = 1;
		}
	}
	if(m < (int) duo.size()) {
		int curAns = duo[m] + dp(n, m + 1);
		if(curAns > ans) {
			ans = curAns;
			to[n][m] = 2;
		}
	}
}*/

int p[ms], d[ms];
bool got[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n + n; i++) {
		d[i] = -1;
		std::cin >> p[i];
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		d[u] = v;
		d[v] = u;
	}
	int t;
	std::cin >> t;
	t--;
	int k = 0;
	int last = -1;
	while(k < 2 * n) {
		if(t == 0) {
			// me
			if(last != -1 && d[last] != -1 && !got[d[last]]) {
				last = d[last];
				got[last] = true;
				std::cout << last + 1 << std::endl;
			} else {
				// try to get duo
				last = -1;
				for(int i = 0; i < n + n; i++) {
					if(d[i] != -1 && p[i] > p[d[i]] && !got[i]) {
						last = i;
					}
				}
				if(last == -1) {
					// get best
					for(int i = 0; i < n + n; i++) {
						if(got[i]) continue;
						if(last == -1 || p[i] > p[last]) {
							last = i;
						}
					}
				}
				std::cout << last + 1 << std::endl;
				got[last] = true;
			}
		} else {
			// him
			int x;
			std::cin >> x;
			x--;
			got[x] = true;
			last = x;
		}
		t ^= 1;
		k++;
	}
}