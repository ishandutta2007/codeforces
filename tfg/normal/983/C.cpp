#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

int dp[2][10][10][10][10][10];
// 2e3 * 1e4 = 2e7

int from[2020], to[2020];
int p[20], b[20];
int freq[20];
long long cnt = 0;

void rem(int v) {
	int off = 0;
	for(int i = 0; i < 4; i++) {
		if(p[i] == v && off == 0) {
			off++;
			//std::cout << "found on pos " << i << std::endl;
		}
		b[i] = p[i + off];
	}
}

void add(int v) {
	int off = 0;
	for(int i = 0; i < 4; i++) {
		b[i] = p[i - off];
		if(off == 0 && p[i] < v) {
			off++;
			b[i] = v;
		}
	}
}
int lst, cur;
void make_transition(int on = 0, int l = 9) {
	if(on == 4) {
		
		#define curdp dp[cur&1][p[0]][p[1]][p[2]][p[3]]
		for(int i = 1; i < 10; i++) {
			curdp[i] = 1e9;
		}
		if(freq[to[cur]]) {
			rem(to[cur]);
			curdp[from[cur]] = dp[lst&1][b[0]][b[1]][b[2]][b[3]][from[cur]];
		}
		if(l == 0) {
			for(int i = 1; i < 10; i++) {
				add(i);
				curdp[i] = std::min(curdp[i], dp[cur&1][b[0]][b[1]][b[2]][b[3]][i]);
			}
		}
		for(int i = 2; i < 10; i++) {
			curdp[i] = std::min(curdp[i], curdp[i - 1] + 1);
		}
		for(int i = 8; i > 0; i--) {
			curdp[i] = std::min(curdp[i], curdp[i + 1] + 1);
		}
	} else {
		for(int i = l; i >= 0; i--) {
			p[on] = i;
			freq[i]++;
			make_transition(on + 1, i);
			//cnt++;
			freq[i]--;
		}
	}
}

int main() {
	srand(time(0));
	int n;
	std::cin >> n;
	//n = 2000;
	for(int i = 1; i <= n; i++) {
		std::cin >> from[i] >> to[i];
		//from[i] = rand() % 9 + 1;
		//to[i] = rand() % 9 + 1;
		//std::cout << "(" << from[i] << ", " << to[i] << ")\n";
	}
	memset(dp[0], 0x3f, sizeof dp[0]);
	for(int i = 1; i < 10; i++) {
		dp[0][0][0][0][0][i] = i - 1;
	}
	//std::cout << "got here\n";
	for(int i = 1; i <= n; i++) {
		lst = i - 1;
		cur = i;
		make_transition();
	}
	int ans = 1e9;
	for(int i = 1; i < 10; i++) {
		ans = std::min(ans, dp[n&1][0][0][0][0][i] + 2 * n);
	}
	std::cout << ans << std::endl;
}