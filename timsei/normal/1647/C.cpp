#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, x, y, A[N * N], B[N * N], C[N * N], D[N * N];

char s[N][N];

void rmain() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; ++ j) cnt += (s[i][j] == '1');
	}
	if(s[1][1] =='1') {
		puts("-1");
		return;
	}
	printf("%d\n", cnt);
	for(int i = n; i >= 1; -- i) {
		for(int j = m; j >= 1; -- j) if(s[i][j] == '1') {
			if(i == 1) {
				printf("%d %d %d %d\n", i, j - 1, i, j);
			} else {
				printf("%d %d %d %d\n", i - 1, j, i, j);
			}
		}
	}
	
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}