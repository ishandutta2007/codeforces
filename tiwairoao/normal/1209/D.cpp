#include<cstdio>
const int MAXN = 100000;
int fa[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
int main() {
	int n, k; scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) fa[i] = i;
	int ans = 0;
	for(int i=1;i<=k;i++) {
		int x, y; scanf("%d%d", &x, &y);
		int fx = find(x), fy = find(y);
		if( fx == fy ) ans++;
		else fa[fx] = fy;
	}
	printf("%d\n", ans);
}