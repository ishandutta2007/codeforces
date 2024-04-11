#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int t, n, m, A[N], B[N], mm[N];

bool vis[N];

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

int main() {
	for(cin >> t; t --;) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
		int Min = 1e9;
		for(int i = 1; i <= m; ++ i) scanf("%d", &B[i]), Min = min(Min, B[i]);
		for(int i = 1; i <= m; ++ i) Min = gcd(Min, B[i]);
		long long ans = 0;
		if(Min == 1) {
			for(int i = 1; i <= n; ++ i) ans += abs(A[i]);
			printf("%lld\n", ans);
			continue;
		}
		
		long long res1 = 0, res2 = 0;
		
		for(int i = 1; i <= Min; ++ i) {
			mm[i] = 1e9 + 1; vis[i] = 0;
			for(int j = i; j <= n; j += Min) {
				if(A[j] < 0) vis[i] ^= 1;
				mm[i] = min(mm[i], abs(A[j]));
				ans += abs(A[j]);
			}
			if(vis[i]) res1 += mm[i] * 2;
			else res2 += mm[i] * 2;
		}
		printf("%lld\n", ans - min(res1, res2));
	}
}