#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, n, m, x, y, A[N];
char s[N];

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
		int L = 0, Min = 1e9, ok = 0;
		long long S = 0, ans = 0;
		for(int i = 1; i <= n; ++ i) {
			if(s[i] == '1') {
				if(!L) {
					ok = 0;
					L = i;
					if(i != 1) Min = min(A[i], A[i - 1]), S = A[i] + A[i - 1];
					else Min = A[i], S = A[i], ok = 1;
				} else {
					Min = min(Min, A[i]);
					S += A[i];
				}
			} else {
				if(L) {
					// L, i
					ans += S - Min;
					if(ok) ans += Min;
					L = 0;
				}
			}
		}
		if(L) {
			ans += S - Min;
			if(ok) ans += Min;
		}
		cout << ans << endl;
	}
}