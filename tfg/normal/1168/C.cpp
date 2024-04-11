#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;
const int me = 19;

int dp[ms][me];
int nxt[me];
int a[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < me; i++) {
		nxt[i] = n;
	}
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < me; j++) {
			if(a[i] & (1 << j)) {
				dp[i][j] = nxt[j];
				nxt[j] = i;
			} else {
				dp[i][j] = n;
			}
		}
		int mask = 0;
		for(int rep = 0; rep < me; rep++) {
			int bst = -1;
			for(int j = 0; j < me; j++) {
				if(mask & (1 << j)) continue;
				if(bst == -1 || dp[i][j] < dp[i][bst]) {
					bst = j;
				}
			}
			mask |= 1 << bst;
			bst = dp[i][bst];
			if(bst == n) break;
			for(int j = 0; j < me; j++) {
				dp[i][j] = std::min(dp[i][j], dp[bst][j]);
			}
		}
	}
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		l--;r--;
		bool ans = false;
		for(int i = 0; i < me; i++) {
			if((a[r] & (1 << i)) && dp[l][i] <= r) {
				ans = true;
			}
		}
		if(ans) {
			std::cout << "Shi\n";
		} else {
			std::cout << "Fou\n";
		}
	}
}