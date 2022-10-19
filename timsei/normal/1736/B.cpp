#include <bits/stdc++.h>
using namespace std;

const int N = 123123;

int A[N], B[N], n;

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &A[i]);
		}
		
		B[1] = A[1];
				
		for(int i = 1; i < n; ++ i) {
			B[i + 1] = A[i] * A[i + 1] / gcd(A[i], A[i + 1]);
		}
		
		B[n + 1] = A[n];
		bool ok = 1;
		for(int i = 1; i <= n; ++ i) {
			if(A[i] != gcd(B[i], B[i + 1])) {
				ok = 0;
				puts("NO");break;
			}
		}
		if(ok)puts("YES");
	}
}