#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n;

struct P {
	int x, y;
	void input() {
		scanf("%d%d", &x, &y);
	}
}T[N];

bool cmpx(P a, P b) {
	return a.x < b.x;
}

bool cmpy(P a, P b) {
	return a.y < b.y;
}

int coe[3][2], All[3][N];

int calc(int x) {
	if(x == 1) return 1;
	else return -1;
}

int calc(int x, int y) {
	return coe[y][0] * T[x].x + coe[y][1] * T[x].y;
}

int dp[8], tmp[3][4], t[8];

int calc() {
	for(int i = 0; i < 3; ++ i) {
		for(int j = 0; j < 4; ++ j) {
			if(i == 0) tmp[i][j] = (j << 1);
			else if(i == 2) tmp[i][j] = j;
			else {
				tmp[i][j] = (j & 1) + ((j & 2) << 1);
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i < 8; ++ i) dp[i] = -1e9;
	memset(t, 0, sizeof(t));
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 8; ++ j) t[j] = dp[j];
		for(int j = 0; j < 3; ++ j) {
			int who = calc(i, j);
			for(int k = 0; k < 4; ++ k) {
				int A = tmp[j][k];
				t[A | (1 << j)] = max(t[A | (1 << j)], who + dp[A]);
			}
		}
		for(int j = 0; j < 8; ++ j) dp[j] = t[j];
	}
	return dp[7];
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i)
	T[i].input();
	sort(T + 1, T + n + 1, cmpx);
	int ans = 0;
	ans = T[n].x - T[1].x;
	sort(T + 1, T + n + 1, cmpy);
	ans += (T[n].y - T[1].y);
	ans *= 2;
	int res = 0;
	for(int i = 0; i < (1 << 6); ++ i) {
		memset(coe, 0, sizeof(coe));
		coe[0][0] += calc(i & 1);        coe[1][0] -= calc(i & 1);
		coe[0][1] += calc((i >> 1) & 1); coe[1][1] -= calc((i >> 1) & 1);
		
		coe[1][0] += calc((i >> 2) & 1); coe[2][0] -= calc((i >> 2) & 1);
		coe[1][1] += calc((i >> 3) & 1); coe[2][1] -= calc((i >> 3) & 1);
		
		coe[0][0] += calc((i >> 4) & 1); coe[2][0] -= calc((i >> 4) & 1);
		coe[0][1] += calc((i >> 5) & 1); coe[2][1] -= calc((i >> 5) & 1);
		res = max(res, calc());
	}
	cout << res <<" ";
	for(int i = 4; i <= n; ++ i) printf("%d ", ans);
	puts("");
}