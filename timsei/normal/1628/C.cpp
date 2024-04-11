#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int t, n, m, x, y, A[N][N], B[N][N], E[N][N], F[N];

bitset < N > C[N][N], D[N];

void rmain() {
    //printf("HERE");
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) scanf("%d", &A[i][j]);
	}
	for(int i = 0; i <= n + 1; ++ i) {
		for(int j = 0; j <= n + 1; ++ j) C[i][j] = 0, B[i][j] = 0, E[i][j] = 0;
	}
	cerr << "HERE" << endl;
	for(int i = 0; i <= n + 1; ++ i) F[i] = 0, D[i] = 0;
	for(int i = 1; i <= n; ++ i) C[1][i][i] = 1;
	for(int i = 1; i < n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			C[i + 1][j] = C[i - 1][j] ^ C[i][j - 1] ^ C[i][j + 1];
			E[i + 1][j] = E[i - 1][j] ^ E[i][j - 1] ^ E[i][j + 1];
			E[i + 1][j] ^= A[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		D[i] = C[n - 1][i] ^ C[n][i + 1] ^ C[n][i - 1];
		F[i] = A[n][i] ^ E[n - 1][i] ^ E[n][i + 1] ^ E[n][i - 1];
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = i; j <= n; ++ j) {
			if(D[j][i]) swap(D[j], D[i]);
		}
		for(int j = 1; j <= n; ++ j) if(i != j) {
			if(D[j][i]) D[j] ^= D[i], F[j] ^= F[i];
		}
	}
	for(int i = 1; i <= n; ++ i) B[1][i] = F[i];
	for(int i = 1; i < n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			B[i + 1][j] = B[i - 1][j] ^ B[i][j - 1] ^ B[i][j + 1] ^ A[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
	for(int j = 1; j <= n; ++ j) 
	ans ^= B[i][j];
	/*for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) 
		printf("%d ", B[i][j]);
		puts("");
	} */
	cout << ans << endl;
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}