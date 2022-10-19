#include <bits/stdc++.h>
using namespace std;

/*1 5 9
2 3 6
4 8 7*/
/* 
9 5 1
6 3 2
7 8 4 */
const int N = 505;

int n, A[N][N];

int main() {
	cin >> n;
	if(n <= 2) {
		puts("-1");
		return 0;
	}
	int now = n * n - 9;
	A[n - 2][n - 2] = now + 9; A[n - 2][n - 1] = now + 5; A[n - 2][n] = now + 1;
	A[n - 1][n - 2] = now + 6;  A[n - 1][n - 1] = now + 3; A[n - 1][n] = now + 2;
	A[n][n - 2] = now + 7; A[n][n - 1] = now + 8; A[n][n] = now + 4;
	for(int i = n - 3; i >= 1; -- i) {
		if(i % 2 == (n - 3) % 2) {
			for(int j = n; j >= i; -- j) {
				A[i][j] = now; now --;
			}
			for(int j = i + 1; j <= n; ++ j)
			A[j][i] = now, -- now;
		} else {
			for(int j = n; j >= i; -- j) {
				A[j][i] = now; now --;
			}
			for(int j = i + 1; j <= n; ++ j)
			A[i][j] = now, -- now;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) printf("%d ", A[i][j]);
		puts("");
	}
	puts("");
}