#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int n, m, x, y, A[N], B[N];

int get(int *A, int x) {
	int ans = 1e9;
	for(int i = 1; i <= n; ++ i) {
		ans = min(ans, abs(x - A[i]));
	}
	return ans;
}

void rmain() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &B[i]);
	int al = get(B, A[1]), ar = get(B, A[n]), bl = get(A, B[1]), br = get(A, B[n]);
	int ans = al + ar + bl + br;
	ans = min(ans, min(al + bl, abs(A[1] - B[1])) + min(ar + br, abs(A[n] - B[n])));
	ans = min(ans, min(al + br, abs(A[1] - B[n])) + min(ar + bl, abs(A[n] - B[1])));
	cout << ans << endl;
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}