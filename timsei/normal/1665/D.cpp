#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n, x, y, vis[N];

void rmain() {
	int cur = 0;
	for(int i = 0; i < 30; ++ i) {
		long long a = (1 << (i + 1)) - cur, b = (1ll << (i + 2)) - cur;
		if(a <= (int)2e9 && b <= (int)2e9) {
			printf("? %d %lld\n", (1 << (i + 1)) - cur,  (1ll << (i + 2)) - cur);
			fflush(stdout);
			scanf("%d", &x);
			if(x == (1 << (i + 1))) {
				continue;
			} else {
				cur = cur + (1 << i);
			}
		} else {
			printf("? %d %lld\n", (1 << (i + 1)) - (1 << i) - cur,  (1ll << (i + 2)) - (1 << i) - cur);
			fflush(stdout);
			scanf("%d", &x);
			if(x == (1 << (i + 1))) {
				cur = cur + (1 << i);
			} else continue;
		}
	}
	printf("! %d\n", cur);
	fflush(stdout);
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}