#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, n, m, x, y;

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		printf("%d %d ", 1, n);
		for(int i = 2; i < n; ++ i) {
			printf("%d ", i);
		}
		puts("");
	}
}