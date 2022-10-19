#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t, n, r, b;

void rmain() {
	scanf("%d%d%d", &n, &r, &b);
	int now = (r - 1) / (b + 1) + 1;
	if(now == 1) {
		int cur = 0;
		for(int i = 1; i <= n; ++ i) {
			if(cur < now && r) {
				putchar('R');
				-- r; ++ cur;
			} else {
				putchar('B');
				cur = 0;
			}
		}
		puts("");
		return;
	}
	int it = r - r / (b + 1) * (b + 1);
	int cur = 0;
	for(int i = 1; i <= n; ++ i) {
		if(cur < now && r) {
			putchar('R');
			-- r; ++ cur;
		} else {
			putchar('B');
			cur = 0;
			-- it;
			if(!it) -- now;
		}
	}
	puts("");
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}