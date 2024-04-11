#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, t, A[N];

void rmain() {
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	
	long long ans = 0;
	
	bool ok = 1, ok2 = 0, ok3 = 1;
	for(int i = 2; i < n; ++ i) ok &= (A[i] <= 1), ok2 ^= (A[i] & 1), ok3 &= (A[i] == 0);
	int cnt = 0, who = 0;
	for(int i = 2; i < n; ++ i) if(A[i]) ++ cnt, who = A[i];
	if(cnt == 0) {
		puts("0");
		return;
	}
	if(cnt == 1 && who == 3) {
		puts("-1");
		return;
	} else if(cnt == 1 && (who & 1)) {
		if(n == 3) {
			puts("-1");
			return;
		} else 
		++ ans;
	}
	if(ok) {
		puts("-1");
		return;
	} else {
		for(int i = 2; i < n; ++ i) 
		ans += (A[i] + 1) / 2;
	}
	
	cout << ans << endl;
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}