#include<stdio.h>
#include<vector>
using namespace std;
struct e {
	int t, i;
};
vector<e> map[300001];
int d[300001];
int v[300001];
int chk[300001];
int ans[300001];
int dfs(int x) {
	v[x] = 1;
	int R = chk[x];
	for (auto e : map[x]) {
		if (v[e.t]) continue;
		int r = dfs(e.t);
		R ^= r;
		if (r) ans[e.i] = 1;
	}
	return R;
}
int main()
{
	int n, m, c1=0, c2=0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", d + i);
		if (d[i] == -1) c1=i;
		else if (d[i] == 1) {
			c2++;
			chk[i] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a].push_back({ b, i });
		map[b].push_back({ a, i });
	}
	if (c2 % 2 == 1) {
		if (c1 == 0) {
			printf("-1");
			return 0;
		}
		chk[c1] = 1;
	}
	dfs(1);
	int c = 0;
	for (int i = 1; i <= m; i++) c += ans[i];
	printf("%d\n", c);
	for (int i = 1; i <= m; i++) if (ans[i]) printf("%d\n", i);
	return 0;
}