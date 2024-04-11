#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

int n, m, x, y, k, A[N], du[N], dep[N], B[N], T[N];

void rmain() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
	sort(A + 1, A + n + 1);
	int S = 0;
	bool ok = 1;
	for(int i = 1; i <= n; ++ i) S += A[i], T[i] = T[i - 1] + A[i];
	if(S + (n - 2) * A[1] > 0 || S + (n - 2) * A[n] < 0) {
		puts("INF");
		return;
	}
	long long ans = -1e18;
	long long k = 0, b = 0;
	for(int i = 2; i <= n; ++ i) {
		k += A[1] * A[i];
		b += A[1] + A[i];
	}
	
	ans = max(ans, k + b * (-A[1]));
	k = b = 0;
	
	for(int i = 1; i < n; ++ i) {
		k += A[n] * A[i];
		b += A[n] + A[i];
	}
	
	ans = max(ans, k + b * (-A[n]));
	
	for(int i = 1; i < n; ++ i) {
		k = A[1] * (T[n] - T[i]) + A[n] * (T[i]);
		b = A[1] * (n - i) + A[n] * i + T[n];
		k -= 1LL * A[1] * A[n];
		b -= A[1] + A[n];
		int L = -A[i + 1], R = -A[i];
		ans = max(ans, k + max(b * L, b * R));
	}
	cout << ans << endl;
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}