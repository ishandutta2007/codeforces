#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200600;
int n, S;
int a[N];
int b[N];
int xs[N];
int k;
vector<int> g[N];
int m;
vector<int> cycles[N];
int p[N];
bool used[N];

void dfs(int v) {
	while(!g[v].empty()) {
		int id = g[v].back();
		g[v].pop_back();
		dfs(a[id]);
		cycles[m].push_back(id);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &S);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		xs[k++] = b[i];
	k = unique(xs, xs + k) - xs;
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(xs, xs + k, a[i]) - xs;
		b[i] = lower_bound(xs, xs + k, b[i]) - xs;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		g[b[i]].push_back(i);
	}
	for (int i = 0; i < k; i++) {
		dfs(i);
		if (!cycles[m].empty()) m++;
	}
	for (int i = 0; i < m; i++)
		S -= (int)cycles[i].size();
	if (S < 0) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int id = 0; id < m; id++) {
		for (int i = 0; i < (int)cycles[id].size(); i++) {
			int v = cycles[id][i], u = cycles[id][(i + 1) % (int)cycles[id].size()];
			p[u] = v;
		}
	}
	S = min(S, m);
	if (S > 1) {
		printf("%d\n", 2 + m - S);
		printf("%d\n", S);
		for (int i = 0; i < S; i++)
			printf("%d ", cycles[i][0] + 1);
		printf("\n");
		for (int i = S - 1; i > 0; i--)
			swap(p[cycles[i][0]], p[cycles[i - 1][0]]);
	} else {
		printf("%d\n", m);
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		if (p[i] == i) {
			used[i] = 1;
			continue;
		}
		vector<int> cur;
		int x = i;
		while(!used[x]) {
			cur.push_back(x);
			used[x] = 1;
			x = p[x];
		}
		printf("%d\n", (int)cur.size());
		for (int z : cur)
			printf("%d ", z + 1);
		printf("\n");
	}

	return 0;
}