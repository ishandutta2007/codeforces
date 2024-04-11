#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

long long S[N];
int n, m, A[N], x;
long long ans = 1e18;

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) A[i] = 0;
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &x);
			++ A[x];
		}
		for(int i = 1; i <= n; ++ i) S[i] = S[i - 1] + A[i];
		ans = 1e18;
		
		for(int i = 0; i < 20; ++ i) {
			for(int j = 0; j < 20; ++ j) {
				long long res = 0, Sum = 0;
				int l = 0, r = 0;
				while(A[l + 1] + Sum <= (1ll << i) && l < n) ++ l, Sum += A[l];
				res += (1ll << i) - Sum; Sum = 0;
				while(A[l + 1] + Sum <= (1ll << j) && l < n) ++ l, Sum += A[l];
				res += (1ll << j) - Sum; 
				Sum = S[n] - S[l];
				int up = 0;
				while((1ll << up) < Sum) ++ up;
				res += (1ll << up) - Sum;
				ans = min(res, ans);
			}
		}
		cout << ans << endl;
	}
}