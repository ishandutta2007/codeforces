#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int t, n, m, r, c, x, y, cnt;
char s[N];

int main() {
	cin >> t;
	for(; t --;) {
		scanf("%d%d%d%d", &n, &m, &r, &c);
		int ans = 1e9;
		for(int i = 1; i <= n; ++ i) {
			scanf("%s", s + 1);
			for(int j = 1; j <= m; ++ j) {
				if(s[j] == 'B') {
					ans = min(ans, (i != r) + (j != c));
				}
			}
		}
		if(ans > 2) {
			puts("-1");
		} else printf("%d\n", ans);
	}
}