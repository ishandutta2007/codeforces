#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 123123;

int gcd(int x, int y) {
	return (!y) ? x :gcd(y, x % y);
}

int n, m, x, y, G, A[N];

main(void) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> A[i];
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= n; ++ i) {
		G = gcd(G, A[i] - A[1]);
	}
	G = gcd(G, A[1]);
	int now = (A[n] - G) / G + 1;
	now -= n;
	if(now & 1) puts("Alice");
	else puts("Bob");
}