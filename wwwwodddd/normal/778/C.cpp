#include <iostream>
#include <algorithm>
using namespace std;
int t[1200020][26], tt;
int d[300020];
int z[300020];
int n, x, y;
int merge(int x, int y) {
	if (!x || !y) {
		return x + y;
	}
	int rt = ++tt;
	for (int i = 0; i < 26; i++) {
		t[rt][i] = merge(t[x][i], t[y][i]);
	}
	return rt;
}
void dfs(int x, int d) {
	for (int i = 0; i < 26; i++) {
		if (t[x][i] > 0) {
			dfs(t[x][i], d + 1);
		}
	}
	int rt = 0;
	tt = n;
	for (int i = 0; i < 26; i++) {
		if (t[x][i] > 0) {
			rt = merge(rt, t[x][i]);
		}
	}
	if (rt > 0) {
		tt++;
	}
	z[d] += tt - n;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char c;
		scanf("%d%d %c", &x, &y, &c);
		t[x][c - 'a'] = y;
	}
	dfs(1, 1);
	printf("%d\n%d\n", n - *max_element(z, z + n), (int)(max_element(z, z + n) - z));
}