#include <bits/stdc++.h>
using namespace std;

const int N = 1123123;

int A[N], B[N], n;

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		int r = 0;
		long long ans = 0;
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &A[i]);
			A[i] = max(i - A[i] + 1, 1);
		}
		
		for(int i = 1; i <= n; ++ i) {
			while(r <= n && A[r] <= i) {
				++ r;
			}
			ans += r - i;
		}
		printf("%lld\n", ans);
	}
}