#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, P[N], A[N];

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
	}
	int cnt = 0, who = 0;
	for(int i = 1; i <= n; ++ i) {
		cnt += (A[i] == 1);
		if(A[i] == 1) who = i;
	}
	if(cnt > 1 || cnt == 0) {
		puts("NO"); return;
	}
	
	int lst = 1;
	
	for(int i = who + 1; i <= who + n - 1; ++ i) {
		int cur = i;
		if(cur > n) {
			cur = cur - n;
		}
		if(A[cur] > lst + 1) {
			puts("NO");
			return;
		} else {
			lst = A[cur];
		}
	}
	puts("YES");
	return;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}