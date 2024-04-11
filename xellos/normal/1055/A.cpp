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
	int N, S;
	cin >> N >> S;
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) cin >> B[i];
	if(A[0] == 0) {
		cout << "NO\n";
		return 0;
	}
	if(A[S-1] == 1) {
		cout << "YES\n";
		return 0;
	}
	if(B[S-1] == 0) {
		cout << "NO\n";
		return 0;
	}
	for(int i = S; i < N; i++) if(A[i] == 1 && B[i] == 1) {
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}

// look at my code
// my code is amazing