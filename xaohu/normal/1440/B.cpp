#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, a[1000005];

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n * k; ++i) scanf("%d", a + i);
	ll res = 0, mid = n - (n + 1) / 2 + 1;
	for (int i = 1; i <= k; ++i)
		res += a[n * k - mid * i];
	printf("%lld\n", res);
}

int main() {	
	int cases;
	scanf("%d", &cases);
	while(cases--)
		solve();
	return 0;
}