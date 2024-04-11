#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
int n;
vector <int> e[N];
int dep[N], l[N];

bool cmp(int x, int y) {
	return l[x] < l[y];
}

void dfs(int x) {
	l[x] = 1;
	for (auto y: e[x]) {
		dep[y] = dep[x] + 1;
		dfs(y);
		l[x] = max(l[x], l[y] + 1);
	}
}

void solve1(int x) {
	// vector <int> V;
	// vector <int> S;
	if (e[x].size() == 0) {
		printf("%d ", x);
		return ;
		// V.push_back(x);
		// return make_pair(V, S);
	}
	printf("%d ", x);
	// V.push_back(x);

	vector <int> last;
	for (int i = 0; i < (int) e[x].size(); i++) {
		// vector <int> V1, S1;
		solve1(e[x][i]);
		// tie(V1, S1) = solve(e[x][i]);
		// for (auto y: V1)
		// 	V.push_back(y);
		// for (auto y: S1)
		// 	S.push_back(y);
		// last.push_back(V.back());
	}

	// for (int i = 1; i < (int) e[x].size(); i++) {
	// 	for (int j = 1; j <= dep[last[i - 1]] - dep[e[x][i - 1]] + 1; j++)
	// 		S.push_back(e[x][i]);
	// }
	// return make_pair(V, S);
}

int solve2(int x) {
	// vector <int> V;
	// vector <int> S;
	if (e[x].size() == 0) {
		return x;
		// printf("%d ", x);
		// V.push_back(x);
		// return make_pair(V, S);
	}
	// printf("%d ", x);
	// V.push_back(x);

	vector <int> last;
	for (int i = 0; i < (int) e[x].size(); i++) {
		// vector <int> V1, S1;
		last.push_back(solve2(e[x][i]));
		// tie(V1, S1) = solve(e[x][i]);
		// for (auto y: V1)
		// 	V.push_back(y);
		// for (auto y: S1)
		// 	S.push_back(y);
		// last.push_back(V.back());
	}

	for (int i = 1; i < (int) e[x].size(); i++) {
		for (int j = 1; j <= dep[last[i - 1]] - dep[e[x][i - 1]] + 1; j++)
			printf("%d ", e[x][i]);
	}
	return last.back();
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		e[x].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		sort(e[i].begin(), e[i].end(), cmp);

	solve1(0);
	printf("\n%d\n", n - l[0]);
	solve2(0);

	// vector <int> V, S;

	// // tie(V, S) = solve(0);
	// for (auto y: V)
	// 	printf("%d ", y);
	// printf("\n");
	// printf("%d\n", (int) S.size());
	// for (auto y: S)
	// 	printf("%d ", y);
	// printf("\n");
}