#include <bits/stdc++.h>
using namespace std;

const int N = 5555;

#define int long long

int A[N], n, ans[N], num[N], col;

bool cmp(int x, int y) {
	if(!y) return 1;
	return (num[x] > num[y]) || ((num[x] == num[y]) && x < y);
}

main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> A[i];
	for(int l = 1; l <= n; ++ l) {
		memset(num, 0, sizeof(num));
		col = 0;
		for(int r = l; r <= n; ++ r) {
			++ num[A[r]];
			if(cmp(A[r], col)) col = A[r];
			++ ans[col];
		}
	}
	for(int i = 1; i <= n; ++ i) cout << ans[i] << " ";
	puts("");
}