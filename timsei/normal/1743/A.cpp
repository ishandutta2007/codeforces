#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, n, m, x, y;

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		bool ok = 0;
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &x);
			if(x == 0) ok = 1;
		}
		if(ok) {
			printf("%d\n", 6 * (10 - n) * (10 - n - 1) / 2);
		} else {
			printf("%d\n", 6 * (10 - n) * (10 - n - 1) / 2);
		}
	}
}