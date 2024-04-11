#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int t, n, m, r, c, x, y, cnt, ans[N];

int main() {
	cin >> t;
	for(; t --;) {
		scanf("%d%d", &n, &m);
		for(int j = 1; j <= n * m; ++ j) ans[j] = 0;
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j) {
				++ ans[max(i - 1, n - i) + max(j - 1, m - j)];
			}
		}
		for(int i = 1; i <= n * m; ++ i) {
			if(ans[i]) {
				for(int j = 1; j <= ans[i]; ++ j) printf("%d ", i);
			}
		}
		puts("");
	}
}