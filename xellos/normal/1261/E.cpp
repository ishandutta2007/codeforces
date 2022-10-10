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
#define OVER9000 1234567890123456789LL
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

void solve(auto A, auto & ops) {
	int N = A.size();
	if(N == 1) { // A[0] <= 1
		if(A[0].ff) ops.push_back({A[0].ss});
		return;
	}
	if(A[N-1].ff < N) {
		auto B = A;
		B.erase(begin(B));
		solve(B, ops);
		for(int i = 0; i < A[0].ff; i++) ops[i].push_back(A[0].ss);
		return;
	}
	auto B = A;
	B.pop_back();
	if(A[N-2].ff == N) {
		vector<int> op;
		for(int i = 0; i < N-1; i++) if(B[i].ff == N) {
			B[i].ff--;
			op.push_back(B[i].ss);
		}
		solve(B, ops);
		for(int i = 0; i < (int)ops.size(); i++) ops[i].push_back(A[N-1].ss);
		if((int)ops.size() < N) ops.push_back({A[N-1].ss});
		ops.push_back(op);
		return;
	}
	for(int i = 0; i < N-1-A[N-2].ff; i++) B[i].ff--;
	solve(B, ops);
	for(int i = 0; i < N-1-A[N-2].ff; i++) ops.push_back({A[i].ss});
	for(int i = 0; i < (int)ops.size(); i++) ops[i].push_back(A[N-1].ss);
	if((int)ops.size() < N) ops.push_back({A[N-1].ss});
	return;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<int, int> > A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i].ff;
		A[i].ss = i;
	}
	sort(begin(A), end(A));
	vector< vector<int> > ops;
	solve(A, ops);
	cout << ops.size() << "\n";
	for(int i = 0; i < (int)ops.size(); i++) {
		string S(N, '0');
		for(auto x : ops[i]) S[x] = '1';
		cout << S << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing