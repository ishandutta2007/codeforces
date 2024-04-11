#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, A[N], B[N], dp[N][N], who[N];

long long calc(int x) {
	return 1LL * x * (x + 1) / 2;
}

int main() {
	long long ans = 0;
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		ans = 0;
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
		memset(B, 0, sizeof(B));
		for(int i = 1; i <= n; ++ i) scanf("%d", &B[i]), who[i] = A[i] - B[i];
		
		int cur = 0;
		
		for(int i = 1; i <= n; ++ i) {
			int mx = 1e9;
			for(int j = i; j <= n; ++ j) {
				mx = min(mx, who[j]);
			}
			
			// A[i - 1], now
			if(mx >= A[i - 1]) {
				ans += calc(A[i] - mx);
				cur = A[i] - mx;
			} else {
				ans += calc(cur + A[i] - A[i - 1]) - calc(cur);
				cur += A[i] - A[i - 1];
			}
			
		}
		cout << ans << endl;
	}
}