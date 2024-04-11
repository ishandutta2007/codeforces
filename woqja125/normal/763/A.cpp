#include<stdio.h>
#include<vector>
using namespace std;
int c[100001], ac[100001];
vector<int> map[100001];
void dfs1(int x, int p) {
	ac[x] = c[x];
	for (auto e:map[x]) {
		if (e==p) continue;
		dfs1(e, x);
		if (ac[x] != ac[e]) ac[x] = -1;
	}
}
int dfs2(int x, int p, int uac) {
	if (uac == -1) return -1;
	bool f=false;
	for (auto e:map[x]) {
		if (e==p) continue;
		if (ac[e] == -1) { f=true; break; }
	}
	if (!f) return x;
	if (uac != c[x]) return -1;
	int ne=-1;
	for (auto e:map[x]) {
		if (e==p) continue;
		if (ac[e] != uac) { 
			if (ne != -1) return -1;
			ne = e;
		}
	}
	if (ne == -1) {
		for (auto e:map[x]) {
			if (e==p) continue;
			int re = dfs2(e, x, uac);
			if (re!=-1) return re;
		}
		return -1;
	}
	else {
		return dfs2(ne, x, uac);
	}
}
int main()
{
	int n, i, a, b;
	scanf("%d", &n);
	for (int i=1; i<n; i++) {
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for (int i=1; i<=n; i++) scanf("%d", c+i);
	dfs1(1, -1);
	int ans = dfs2(1, -1, c[1]);
	if (ans == -1) {
		printf("NO");
	}
	else {
		printf("YES\n%d", ans);
	}
	return 0;
}