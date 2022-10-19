#include <bits/stdc++.h>
using namespace std;

const int N = 25;

char T[N][N];
int dp[N * 2][(1 << 21) + 5], n, m, x, y;

bool vis[N * 2][(1 << 21) + 5];

int calc(char c) {
	if(c == 'a') return 1;
	if(c == 'b') return -1;
	return 0;
}

int ind(int it) {
	if(it == 0) return 1;
	else return -1;
}

int solve(int x, int y) {
	if(vis[x][y]) return dp[x][y];
	if(x == 2 * n && y == (1 << n - 1)) {
		return - calc(T[n][n]);
	}
	vis[x][y] = 1;
	int &ans = dp[x][y];
	ans = -1000000000;
	
	vector <int> all;
	
	for(int i = 0; i < n; ++ i) 
	if((y >> i) & 1)
	all.push_back(i + 1);
	
	char c = 0;
	
	for(int i = 'a'; i <= 'z'; ++ i) {
		int mask = 0;
		for(int j = 0; j < (int) all.size(); ++ j) {
			int X = all[j], Y = x - X;
			c = T[X][Y];
			if(X < n && T[X + 1][Y] == i) mask |= (1 << X);
			if(Y < n && T[X][Y + 1] == i) mask |= (1 << (X - 1));
		}
		if(!mask) continue; 
		ans = max(ans, -solve(x + 1, mask));
	}
	
	ans += calc(c) * ind((x + 1) % 2);
	
	return ans;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", T[i] + 1);
	}
	
	int ans = solve(2, 1);
	if(ans < 0) puts("FIRST");
	else if(ans == 0) puts("DRAW");
	else puts("SECOND");
}