#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int A[N], n, k;

bool B[N];

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

main(void) {
	cin >> n >> k;
	int now = k;
	int tot = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%I64d", &A[i]);
		now = gcd(now, A[i]);
	}
	printf("%I64d\n", k / now);
	for(int i = 0; i < k; i += now) printf("%I64d ", i);
}