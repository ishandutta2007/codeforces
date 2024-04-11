#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, x, y, A[N];

int main() {
	int t;
	A[1] = 1;
	int cnt = 1;
	while(1LL * A[cnt] * 3 <= (int)1e9) {
		A[cnt + 1] = A[cnt] * 3;
		++ cnt;
	}
	for(cin >> t; t --;) {
		cin >> n;
		if(n <= cnt) {
			puts("YES");
			for(int i = 1; i <= n; ++ i) printf("%d ", A[i]);
			puts("");
		} else puts("NO");
	}
}