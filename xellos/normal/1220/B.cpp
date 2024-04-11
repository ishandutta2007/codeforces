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
	int N;
	cin >> N;
	vector< vector<int> > M(N, vector<int>(N));
	for(int i = 0; i < N*N; i++) cin >> M[i/N][i%N];
	vector<int> A(N);
	A[0] = sqrt(M[0][1]*1LL*M[0][2]/M[1][2]);
	while(A[0] > 0 && 1LL*A[0]*A[0] > M[0][1]*1LL*M[0][2]/M[1][2]) A[0]--;
	while(1LL*A[0]*A[0] < M[0][1]*1LL*M[0][2]/M[1][2]) A[0]++;
	for(int i = 1; i < N; i++) A[i] = M[0][i]/A[0];
	for(int i = 0; i < N; i++) cout << A[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing