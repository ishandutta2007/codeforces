#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int n, k, A[N];

struct Node {
	int mx, sum;
};

vector < Node > L, R;

void rmain() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld", &k);
		for(int j = 1; j <= n; ++ j) 
		printf("%lld ", (k + (i - j + n) * i % n) % n);
		puts("");
	}
}

main() {
	int T;
	for(T = 1; T --;) {
		rmain();
	}
}