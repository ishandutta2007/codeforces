#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, n, m, x, y, A[N];
long long Sum = 0;

long long calc(long long x, int y) {
	if(x < 0) return 0;
	return (x - 1) / y + 1;
}

void rmain() {
	scanf("%d%lld", &n, &Sum);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), Sum -= A[i];
	sort(A + 1, A + n + 1);
	if(Sum >= 0) {
		puts("0");
		return;
	}
	long long ans = -Sum;
	long long now = ans;
	for(int i = n; i >= 2; -- i) {
		long long res = n - i + 1;
		now -= (A[i] - A[1]);
		if(now <= 0) {
			ans = min(ans, res);
			break;
		}
		ans = min(ans, res + calc(now, res + 1));
	}
	cout << ans << endl;
} 

int main() {
	for(cin >> T; T --;) rmain();
}