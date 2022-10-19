#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n, w, h, l, r, x, k;

int main() {
	for(cin >> T; T --;) {
		scanf("%d%d", &w, &h);
		scanf("%d", &k);
		long long ans = 0;
		scanf("%d", &l);
		for(int i = 1; i < k - 1; ++ i) scanf("%d", &x);
		scanf("%d", &r);
		ans = max(ans, 1LL * (r - l) * h);
		scanf("%d", &k);
		scanf("%d", &l);
		for(int i = 1; i < k - 1; ++ i) scanf("%d", &x);
		scanf("%d", &r);
		ans = max(ans, 1LL * (r - l) * h);	
		scanf("%d", &k);
		scanf("%d", &l);
		for(int i = 1; i < k - 1; ++ i) scanf("%d", &x);
		scanf("%d", &r);
		ans = max(ans, 1LL * (r - l) * w);	
		scanf("%d", &k);
		scanf("%d", &l);
		for(int i = 1; i < k - 1; ++ i) scanf("%d", &x);
		scanf("%d", &r);
		ans = max(ans, 1LL * (r - l) * w);
		printf("%lld\n", ans);		
	}
}