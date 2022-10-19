#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int t, n, a, b, cnt[N], x[N], S[N];
char s[N];

void rmain() {
	scanf("%lld%lld%lld", &n, &a, &b);
	for(int i = 1; i <= n; ++ i) scanf("%lld", &x[i]);
	long long S = 0, cur = 0, ans = 0;
	for(int i = 1; i <= n; ++ i) {
		S = S + (n - i) * (x[i] - x[i - 1]) * b - (x[i] - x[i - 1]) * a;
		cur = max(cur, S);
		ans += x[i] * b;
	}
	cout << ans - cur << endl;
}

main() {
	for(cin >> t; t --;) {
		rmain();
	}
}