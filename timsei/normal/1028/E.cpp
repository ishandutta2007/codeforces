#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

#define int long long

int A[N], n, m, x, y, B[N];

int pre(int x) {
	if(x == 1) return n;
	return x - 1; 
}

int nxt(int x) {
	return (x % n + 1);
}

void solve(int x) {
	A[x] = B[x];
	for(int i = pre(x); i != x; i = pre(i)) {
		A[i] = B[i];
		while(A[i] <= B[pre(i)]) A[i] += A[nxt(i)];
	}
	puts("yeS");
	for(int i = 1; i <= n; ++ i) printf("%lld ", A[i]);
	puts("");
}

main(void) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%lld", &B[i]);
	int ok = 0;
	for(int i = 1; i <= n; ++ i) {
		ok += B[i];
	}
	if(!ok) {
		puts("yEs");
		for(int i = 1; i <= n; ++ i) printf("%lld ", 1ll);
		puts("");
		return 0;
	}
	for(int i = 1; i <= n; ++ i) {
		if(B[i] > B[pre(i)]) {
			solve(i);
			return 0;
		}
	}
	puts("nO");
}