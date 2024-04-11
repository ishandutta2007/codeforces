#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> G[1<<17];
bool col[1<<17];
int S[1<<17];
set<pair<int, int>> R;
int cnt;

int dst[1<<17], p[1<<17];

void dfs(int c) {
	if (col[c]) return;
	auto it = R.find({S[c], c});
	if (it != R.end()) R.erase(it);
	S[c] = dst[c];
	R.insert({S[c], c});
	for (int n : G[c]) if (n ^ p[c] && !col[n]) {
		dst[n] = dst[c] + 1;
		p[n] = c;
		dfs(n);
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N-1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b); G[b].push_back(a);
	}

	printf("1 ");
	if (N == 1) return printf("\n"), 0;
	if (N == 2) return printf("2\n"), 0;

	// dfs for diam
	dst[1] = 0;
	p[1] = -1;
	dfs(1);

	int a = 0;
	for (int i = 0; i++ < N; ) if (dst[i] > dst[a]) a = i;

	dst[a] = 0;
	p[a] = -1;
	dfs(a);
	col[a] = 1;
	cnt = 1;

	R.clear();
	for (int j : G[a]) dst[j] = 1, p[j] = -1, dfs(j);
	for (int k = 1; k < N; ++k) {
		if (cnt == N) { printf("%d ", cnt); continue; }
		int f = prev(R.end())->second;
		while (~f) {
			R.erase({S[f], f});
			col[f] = 1;
			for (int j : G[f]) if (j ^ p[f]) dst[j] = 1, p[j] = -1, dfs(j);
			f = p[f];
			cnt++;
		}
		printf("%d ", cnt);
	}

	printf("\n");
}