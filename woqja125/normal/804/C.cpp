#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
vector<int> s[300001];
vector<int> r[300001];
int v[300001];
int c[300001];
void dfs(int x) {
	v[x] = 1;
	vector<int> tmp;
	set<int> cs;
	for (auto t : s[x]) {
		if (c[t] == 0) tmp.push_back(t);
		else cs.emplace(c[t]);
	}
	int col = 1;
	for (auto t : tmp) {
		while (cs.count(col) > 0) col++;
		c[t] = col++;
	}
	//
	for (auto t : tmp) for(auto k: r[t]){
		if (!v[k]) dfs(k);
	}
	return;
}
int main() {
	int n, m, t, k;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) {
			scanf("%d", &k);
			s[i].push_back(k);
			r[k].push_back(i);
		}
	}
	for (int i = 1; i < n; i++) scanf("%*d%*d");
	for (int i = 1; i <= n; i++) {
		if (!v[i]) dfs(i);
	}
	for (int i = 1; i <= m; i++) if (c[i] == 0) c[i] = 1;
	int max = 0;
	for (int i = 1; i <= m; i++)if (max < c[i]) max = c[i];
	printf("%d\n", max);
	for (int i = 1; i <= m; i++) printf("%d ", c[i]);
	//while (1);
	return 0;
}