#include<cstdio>
#include<vector>

std::vector<int> map[100001];
int v[100001][2];
std::vector<int> ans;
int max(int x, int y) { return x > y ? x : y; }
int dfs(int x, int s) {
	int re = -10;
	v[x][s] = -2;
	for (auto e : map[x]) {
		if (v[e][s^1] == -2) re = 0;
		else if (v[e][s^1] == 0) {
			int t = dfs(e, s ^ 1);
			if (t == 1) {
				ans.push_back(x);
				return 1;
			}
			if (t == 0) re = 0;
			else re = max(re, -1);
		}
		else re = max(re, -1);
	}
	if (re == -10) {
		if (s == 1) {
			ans.push_back(x);
			return 1;
		}
		else re = -1;
	}
	v[x][s] = -1;
	return re;
}
int main() {
	int n, s, t;
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) {
			scanf("%d", &s);
			map[i].push_back(s);
		}
	}
	scanf("%d", &s);
	int re = dfs(s, 0);
	if (re == -1) printf("Lose\n");
	else if (re == 0) printf("Draw\n");
	else {
		printf("Win\n");
		for (int i = ans.size() - 1; i >= 0; i--) {
			printf("%d ", ans[i]);
		}
	}
	return 0;
}