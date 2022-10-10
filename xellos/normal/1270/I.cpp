#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <int K, typename T>
inline __attribute__((optimize("Ofast"))) __attribute__((target("arch=core-avx2")))
void XOR(T * __restrict A, const T B[1<<K]) {
	for(int i = 0; i < (1<<K); i++) A[i] ^= B[i];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int K;
	cin >> K;
	int N = 1<<K;
	vector< vector<cat> > A(N, vector<cat>(1<<9));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> A[i][j];
	int C;
	cin >> C;
	vector<int> X(C), Y(C);
	for(int i = 0; i < C; i++) {
		int x, y;
		cin >> x >> y;
		X[i] = x-1, Y[i] = y-1;
	}
	for(int i = 0; i < K; i++) { // * D**(2**i)
		vector< vector<cat> > A_nw(2*N, vector<cat>(1<<10, 0));
		for(int j = 0; j < C; j++)
			for(int k = 0; k < N; k++)
				XOR<9>(&(A_nw[X[j]+k][Y[j]]), A[k].data());
		for(int k = 0; k < N; k++) for(int l = 0; l < N; l++)
			A[k][l] = A_nw[k][l] ^ A_nw[k+N][l] ^ A_nw[k][l+N] ^ A_nw[k+N][l+N];
		for(int j = 0; j < C; j++)
			X[j] = (2*X[j]) & (N-1), Y[j] = (2*Y[j]) & (N-1);
	}
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		if(A[i][j] != 0) ans++;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing