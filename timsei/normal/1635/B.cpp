#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, t, x, ans = 0, A[N], B[N], ok[N];

void solve(int x) {
	int r = x;
	while(B[r + 2]) r += 2;
	if(x == r) {
		++ ans;
		A[x] = A[x - 1];
		return;
	}
}

int main() {
	for(cin >> t; t --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
		for(int i = 1; i <= n + 2; ++ i) B[i] = 0;
		ans = 0;
		int len = 0;
		for(int i = 2; i < n; ++ i) {
			if(A[i] > A[i - 1] && A[i] > A[i + 1]) {
				B[i] = 1;
			}
		}
		for(int i = 2; i < n; ++ i) {
			if(A[i] > A[i - 1] && A[i] > A[i + 1]) {
				++ ans; A[i + 1] = max(A[i], A[i + 2]);
			}
		}
		
		cout << ans << endl;
		for(int i = 1; i <= n; ++ i) printf("%d ", A[i]);
		puts("");
	}
}