#include <bits/stdc++.h>
using namespace std;

const int N = 123123;

int A[N], B[N], n;

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &A[i]);
		}
		int tot = 0, ans = 1e9;
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &B[i]);
			tot += (A[i] ^ B[i]);
		}
		
		ans = tot;
		
		tot = 0;
		
		sort(A + 1, A + n + 1);
		sort(B + 1, B + n + 1);
		
		for(int i = 1; i <= n; ++ i) tot += (A[i] ^ B[i]);
		ans = min(ans, tot + 1);
		cout << ans << endl;
	}
}