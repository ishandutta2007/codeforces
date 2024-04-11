#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, A[N], mi = 1, ma = 1;

void rmain() {
	scanf("%d", &n);
	for(int i = 1;  i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1;i <= n; ++ i) {
		if(A[i] > A[ma]) {
			ma = i;
		}
		if(A[i] < A[mi]) {
			mi = i;
		}
	}
	printf("%d %d\n", mi, ma);
}

int main() {
	int t;
	for(cin >> t; t --;) {
		mi = ma = 1;
		rmain();
	}
}