#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n, m;

#define ll long long

struct Node {
	int y, z;
	ll w;
	friend bool operator < (Node a, Node b) {
		return a.w > b.w;
	}
};

ll A[N];

set < Node > S;

int Y[N], Z[N], ans = 0;

void rmain() {
	scanf("%d", &n); S.clear();
	for(int i = 1; i <= n; ++ i) scanf("%lld", &A[i]), Y[i] = Z[i] = 0;
	if(A[n - 1] > A[n]) {
		puts("-1");
		return;
	}

	if(A[n] >= 0) {
		printf("%d\n", n - 2);
		for(int i = 1; i <= n - 2; ++ i) {
			printf("%d %d %d\n", i, n - 1, n);
		}
		puts("");
		return;
	} else {
		for(int i = 1; i< n;  ++ i) {
			if(A[i] > A[i + 1]) {
				puts("-1"); return;
			}
		}
		puts("0");
	}
	
	
	
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}