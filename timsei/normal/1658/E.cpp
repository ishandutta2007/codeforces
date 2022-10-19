#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 5;

int n, m, x, y, A[N / 2][N / 2], k, psx[N  * N / 4], psy[N * N / 4], S[N][N];

#define lb(x) (x & (-x))

void add(int l, int r, int x) {
	for(int i = l; i < N; i += lb(i))  {
		for(int j = r; j < N; j += lb(j))
		++ S[i][j];
	}
}

int Sum(int l, int r) {
	l = max(l, 0);
	r = max(r, 0);
	l = min(l, N - 1);
	r = min(r, N - 1);
	int res = 0;
	for(int i = l; i; i -= lb(i)) {
		for(int j = r; j; j -= lb(j))
		res += S[i][j];
	}
	return res;
}

int get(int a, int b, int c, int d) {
	a += n;
	c += n;
	return Sum(c, d) + Sum(a, b) - Sum(c, b) - Sum(a, d);
}

void rmain() {
	scanf("%d%d", &n, &k);
//	n = 1000, k = 5;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) scanf("%d", &A[i][j]), psx[A[i][j]] = i, psy[A[i][j]] = j;
	}
	
	int tot = 0;
	
	for(int i = n * n; i >= 1; -- i) {
		int x = psx[i], y = psy[i];
		int ans = get(x - y - k - 1, x + y - k - 1, x - y + k, x + y + k);
		if(ans != tot) {
			A[x][y] = 1;
		} else {
			A[x][y] = 0;
			++ tot;
			add(x - y + n, x + y, 1);
		}
	}
//	return;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) if(!A[i][j]) putchar('M'); else putchar('G');
		puts("");
	}
}

int main() {
	int t;
	for(t = 1; t --;) {
		rmain();
	}
}