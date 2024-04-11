#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 3030;
const int bad[4] = {3, 5, 14, 15};

void add(int &a, int b) {
	a = a + b < MOD ? a + b : a + b - MOD;
}

int to[ms+ms][2];
int val[ms+ms];
int mn[ms+ms];
int h[ms+ms];
int dp[ms+ms][5];
int on[ms];
int ans[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	memset(h, -1, sizeof h);
	h[0] = 0;
	to[0][0] = to[0][1] = -1;
	dp[0][0] = 1;
	for(int len = 1; len <= n; len++) {
		for(int i = 0; i < ms+ms; i++) {
			if(h[i] != len-1) {
				h[i] = -1;
				to[i][0] = to[i][1] = -1;
				mn[i] = n;
			}
		}
		int c = 0;
		for(int i = 0; i + len <= n; i++) {
			int d = a[i+len-1];
			while(h[c] == len-1) c++;
			if(to[on[i]][d] == -1) {
				to[on[i]][d] = c++;
			}
			int nxt = to[on[i]][d];
			{
				// do dp transition
				val[nxt] = (val[on[i]] + val[on[i]] + d) & 15;
				mn[nxt] = std::min(mn[nxt], i);
				for(int j = 0; j <= 4; j++) {
					dp[nxt][j] = 0;
				}
				for(int j = 0; j <= 4; j++) {
					add(dp[nxt][1], dp[on[i]][j]);
					if(j > 1) {
						add(dp[nxt][j], dp[on[i]][j-1]);
					}
				}
				if(val[nxt] == bad[0] || val[nxt] == bad[1] || val[nxt] == bad[2] || val[nxt] == bad[3]) {
					dp[nxt][4] = 0;
				}
			}
			on[i] = nxt;
			h[nxt] = len;
		}
		for(int j = 0; j < c; j++) {
			if(h[j] == len) {
				for(int k = 0; k <= 4; k++) {
					add(ans[mn[j]+len], dp[j][k]);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		add(ans[i], ans[i-1]);
		std::cout << ans[i] << '\n';
	}
}