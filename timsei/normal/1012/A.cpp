#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;

int A[N], B[N], n, m, x, y;

main(void) {
	cin >> n;
	for(int i = 1; i <= n * 2; ++ i) scanf("%lld", &A[i]);
	sort(A + 1, A + 2 * n + 1);
	int ans = (A[n] - A[1]) * (A[n * 2] - A[n + 1]);
	for(int i = 2; i <= n; ++ i) {
		ans = min(ans, (A[i + n - 1] - A[i]) * (A[n * 2] - A[1]));
	}
	cout << ans << endl;
}