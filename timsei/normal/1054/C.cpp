#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int L[N], R[N], id[N], n, A[N], P[N];

bool cmp(int x, int y) {
	return id[x] < id[y];
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) cin >> L[i];
	for(int i = 1; i <= n; ++ i) cin >> R[i], P[i] = i, id[i] = L[i] + R[i] + 1, A[i] = n - L[i] - R[i];
	for(int i = 1; i <= n; ++ i) {
		int l = 0, r = 0;
		for(int j = 1; j < i; ++ j) 
		if(A[j] > A[i]) ++ l;
		for(int j = i + 1; j <= n; ++ j)  {
			if(A[j] > A[i]) ++ r;
		}
		if(l != L[i] || r != R[i]) return 0 * puts("NO");
	}
	puts("YES");
	for(int i = 1; i <= n; ++ i) printf("%d ", A[i]);
}