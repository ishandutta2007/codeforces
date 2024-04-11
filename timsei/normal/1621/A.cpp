#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int main() {
	int t;
	for(cin >> t; t --;) {
		int n, k;
		cin >> n >> k;
		if(k > (n + 1) / 2) {
			puts("-1");
			continue;
		}
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= n; ++ j) {
				if(i == j) {
					if(i & 1) {
						if((i + 1) / 2 <= k) putchar('R');
						else putchar('.');
					} else putchar('.');
				} else putchar('.');
			}
			puts("");
		}
	}
}