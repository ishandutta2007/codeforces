#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int A[N], n;

void rmain() {
	scanf("%d", &n); int cnt = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), cnt += (A[i] < 0);
	for(int i = 1; i <= cnt; ++ i) A[i] = - abs(A[i]);
	for(int i = cnt + 1; i <= n; ++ i) A[i] = abs(A[i]);
	bool ok = 1;
	for(int i = 1; i < n; ++ i)
	ok &= (A[i] <= A[i + 1]);
	if(ok) puts("Yes");
	else puts("No");
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}