#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int A[N], n, m, x, y;

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d%d%d%d", &n, &m, &x, &y);
		long long ans = 0, cur = 0;
		for(int i = 1; i <= n; ++ i) {
			if(cur + x > m) {
				cur -= y;
			} else cur += x;
			ans += cur;
		}
		printf("%lld\n", ans);
	}
}