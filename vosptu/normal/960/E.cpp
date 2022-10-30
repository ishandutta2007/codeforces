#include <iostream>
// #include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
// #include <unordered_map>
#include <map>
#include <queue>

using namespace std;

#define P 1000000007
#define N 210000

int n, V[N], dep[N], s[N][2], ss[N][2];
vector <int> e[N];
int ans;

void dfs(int k, int f) {
	dep[k] = dep[f] + 1;
	s[k][dep[k] % 2] = 1;
	ss[k][dep[k] % 2] = V[k];
	
	for (int i = 0; i < (int) e[k].size(); i++)
		if (e[k][i] != f) {
			dfs(e[k][i], k);
			s[k][0] += s[e[k][i]][0];
			s[k][1] += s[e[k][i]][1];
			ss[k][0] = (ss[k][0] + ss[e[k][i]][0]) % P;
			ss[k][1] = (ss[k][1] + ss[e[k][i]][1]) % P;
			
		}
}

void dfs2(int k, int f) {
	ans = (ans + 1LL * n * V[k]) % P;
	int sign;
	if (dep[k] % 2 == 0)
		sign = 1;
	else
		sign = -1;
	ans = (ans + sign * 1LL * (s[1][0] - s[k][0]) * (s[k][0] + s[k][1]) % P * V[k]) % P;
	ans = (ans - sign * 1LL * (s[1][1] - s[k][1]) * (s[k][0] + s[k][1]) % P * V[k]) % P;
	for (int i = 0; i < (int) e[k].size(); i++)
		if (e[k][i] != f) {
			ans = (ans + sign * 1LL * s[e[k][i]][0] * (n - s[e[k][i]][0] - s[e[k][i]][1]) % P * V[k]) % P;
			ans = (ans - sign * 1LL * s[e[k][i]][1] * (n - s[e[k][i]][0] - s[e[k][i]][1]) % P * V[k]) % P;
		}
	for (int i = 0; i < (int) e[k].size(); i++)
		if (e[k][i] != f) {
			dfs2(e[k][i], k);
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &V[i]), V[i] = (V[i] + P) % P;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1, 0);
	dfs2(1, 0);
	ans = (ans + P) % P;
	printf("%d\n", ans);
}