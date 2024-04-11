#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[22][22];
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= n; i++) {
		for(int j(1); j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i(1); i <= m; i++) {
		for(int j(i); j <= m; j++) {
			function<void(void)> func = [&]() {
				for(int k(1); k <= n; k++) {
					swap(a[k][i], a[k][j]);
				}
			};
			func();
			bool flag(true);
			for(int k(1); k <= n; k++) {
				int cnt(0);
				for(int l(1); l <= m; l++) {
					if(a[k][l] != l) {
						cnt++;
					}
				}
				if(cnt > 2) {
					flag = false;
					break;
				}
			}
			if(flag) {
				printf("YES\n");
				return 0;
			}
			func();
		}
	}
	printf("NO\n");
	return 0;
}