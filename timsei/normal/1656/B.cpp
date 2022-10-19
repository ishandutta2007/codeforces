#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, k, A[N];

map <int, int> Map;

void rmain() {
	scanf("%d%d", &n, &k); Map.clear();
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), Map[A[i]] = 1;
	for(int i = 1; i <= n; ++ i) {
		if(Map.count(A[i] - k)) {
			puts("YES");
			return;
			break;
		}
	}
	puts("NO");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}