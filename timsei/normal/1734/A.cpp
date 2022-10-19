#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

int A[N], B[4], n;

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &A[i]);
		}
		sort(A + 1, A + n + 1);
		int ans = 2e9;
		
		for(int a = 1; a <= n; ++ a) {
			for(int b = a + 1; b <= n; ++ b) {
				for(int c = b + 1; c <= n; ++ c) {
					ans = min(ans, A[b] - A[a] + A[c] - A[b]);
				}
			}
		}
		cout << ans << endl;
	}
}