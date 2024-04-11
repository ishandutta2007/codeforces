#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int S[N], n, tmp[N];

void prework(int n = 50) {
	S[1] = 0;
	for(int i = 2; i <= n; ++ i) {
		memset(tmp, 0, sizeof(tmp));
		for(int j = 1; j < i; ++ j) {
			tmp[S[i - j] ^ S[j]] = 1;
		}
		for(S[i] = 0; tmp[S[i]]; ++ S[i]);
	}
}

int A[N];

void rmain() {
	scanf("%d", &n);
	bool ok = 1;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), ok &= (A[i] == A[1]);
	if(ok) {
		if(n == 3) {
			puts("1");
			return;
		}
		printf("%d\n", max(n - 3, 0));
		return;
	} else {
		int L = n + 1, R = 0;
		for(int i = 1; i < n; ++ i) {
			if(A[i] == A[i + 1]) {
				L = min(L, i);
				R = max(R, i);
			} 
		}
		if(L == n + 1 || (L == R)) {
			puts("0");
			return;
		}
		printf("%d\n", max(1, R - L - 1));
	}
}

int main() {
	prework();
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}