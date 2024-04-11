#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100020];
int b[100020];
int c[2][100020];
pair<int, int> f[100020];
int main() {
	scanf("%d%s%d", &n, s + 1, &m);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + (s[i] == '?');
		if (s[i] != 'a') {
			c[0][i] = c[1][i - 1] + 1;
		}
		if (s[i] != 'b') {
			c[1][i] = c[0][i - 1] + 1;
		}
		if (c[m & 1][i] >= m) {
			f[i] = make_pair(f[i - m].first + 1, f[i - m].second - b[i] + b[i - m]);
		}
		f[i] = max(f[i], f[i - 1]);
	}
	printf("%d\n", -f[n].second);
	return 0;
}