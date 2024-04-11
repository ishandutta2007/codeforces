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
	vector<int> B(N);
	bool all_zero = true;
	for(int i = 0; i < N; i++) {
		cin >> B[i];
		if(B[i] > 0) all_zero = false;
	}
	if(all_zero) {
		cout << "YES\n";
		for(int i = 0; i < N; i++) cout << 1 << ((i == N-1) ? "\n" : " ");
		return 0;
	}
	bool all_eq = true;
	for(int i = 1; i < N; i++) if(B[i] != B[0]) all_eq = false;
	if(all_eq) {
		cout << "NO\n";
		return 0;
	}
	int mx = 0;
	for(int i = 0; i < N; i++) mx = max(mx, B[i]);
	int mx_id = 0;
	for(int i = 0; i < N; i++) if(B[i] == mx && B[(i+N-1)%N] < B[i]) mx_id = i;
	vector<cat> A(N);
	A[mx_id] = B[mx_id];
	int cur = (mx_id+N-1)%N;
	for(int i = 0; i < N-1; i++) {
		int prev = (cur+1)%N, nxt = (cur+N-1)%N;
		A[cur] = B[cur];
		if(A[cur] <= B[nxt]) {
			// k * A[prev] > B[nxt]-A[cur]
			cat k = (B[nxt]-A[cur]) / A[prev];
			A[cur] += k * A[prev];
			while(A[cur] <= B[nxt]) A[cur] += A[prev];
		}
		cur = nxt;
	}
	cout << "YES\n";
	for(int i = 0; i < N; i++) cout << A[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing