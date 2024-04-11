#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

char s[N];


void rmain() {
	int n;
	scanf("%d", &n);
	vector <int> A(n);
	for(int i = 0; i < n; ++ i) scanf("%d", &A[i]);
	for(int i = A[0] - 1; i < A[0] + 2; ++ i) {
		if(1) {
			bool ok = 1;
			for(int j = 1; j < n; ++ j) {
				ok &= (abs(A[j] - j - i) <= 1);
			}
			if(ok) return (void)puts("YES");
		}
	}
	puts("NO");
}


int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}