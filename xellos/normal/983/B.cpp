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
#define abs(x) ((x < 0)?-(x):x)
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

void solve(int l, int r, auto & cost, auto & mxcost, auto & A, auto & b) {
	if(r <= l) {
		mxcost[l][r] = cost[l][r] = 0;
		return;
	}
	if(r == l+1) {
		mxcost[l][r] = cost[l][r] = A[l];
		return;
	}
	if(cost[l][r] != -1) return;
	solve(l+1, r, cost, mxcost, A, b);
	solve(l, r-1, cost, mxcost, A, b);
	int d = r-l;
	cost[l][r] = cost[l][r-(1<<b[d-1])] ^ cost[l+(1<<b[d-1])][r];
	mxcost[l][r] = max(cost[l][r], max(mxcost[l][r-1], mxcost[l+1][r]));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> b(N+1, -1);
	for(int i = 1; i <= N; i++) for(int j = 0; j < 100; j++) if((i>>j)&1) b[i] = j;
	vector< vector<int> > cost(N+1, vector<int>(N+1, -1));
	vector< vector<int> > mxcost(N+1, vector<int>(N+1, -1));
	solve(0, N, cost, mxcost, A, b);
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << mxcost[l][r] << "\n";
	}
	return 0;}

// look at my code
// my code is amazing