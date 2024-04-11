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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > A[2];
	for(int k = 0; k < 2; k++) {
		A[k].resize(N, vector<int>(M));
		for(int i = 0; i < N*M; i++) {
			cin >> A[k][i/M][i%M];
			if(k == 1 && A[1][i/M][i%M] > A[0][i/M][i%M]) swap(A[0][i/M][i%M], A[1][i/M][i%M]);
		}
	}
	for(int k = 0; k < 2; k++) {
		for(int i = 0; i < N; i++) for(int j = 0; j < M-1; j++) if(A[k][i][j] >= A[k][i][j+1]) {
			cout << "Impossible\n";
			return 0;
		}
		for(int i = 0; i < M; i++) for(int j = 0; j < N-1; j++) if(A[k][j][i] >= A[k][j+1][i]) {
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	return 0;
}

// look at my code
// my code is amazing