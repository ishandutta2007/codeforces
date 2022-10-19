#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int t, n, k, A[N], S[N];

int main() {
	for(cin >> t; t --;) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), S[i] = 0;
		for(int i = 1; i <= n; ++ i) ++ S[A[i]];
		for(int i = 1; i <= n; ++ i) S[i] += S[i - 1];
		int now = (n + k + 1) / 2;
		int r = 1, L = 0, R = n + 1;
		
		for(int i = 1; i <= n; ++ i) {
			while(r <= n && S[r] - S[i - 1] < now) ++ r;
			if(r == n + 1) break;
			if(r - i + 1 < R - L + 1) {
				L = i, R = r;
			}
		}
		printf("%d %d\n", L, R);
		int tot = 0, l = 1;
		for(int i = 1; i <= n; ++ i) {
			if(k == 1) {
				printf("%d %d\n", i, n);
				break;
			}
			if(A[i] >= L && A[i] <= R) ++ tot;
			else -- tot;
			if(tot == 1) {
				printf("%d %d\n", l, i);
				tot = 0; l = i + 1;
				-- k;
			}
		}
	}
}