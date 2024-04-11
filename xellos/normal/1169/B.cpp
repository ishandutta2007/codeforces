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
	vector< vector<int> > A(M, {0, 0});
	for(int i = 0; i < M; i++) cin >> A[i][0] >> A[i][1];
	for(int k = 0; k < 2; k++) {
		int f = 0;
		while(f < M && (A[f][0] == A[0][k] || A[f][1] == A[0][k])) f++;
		if(f == M) {
			cout << "YES\n";
			return 0;
		}
		for(int l = 0; l < 2; l++) {
			bool ok = true;
			for(int i = 0; i < M; i++)
				if(A[i][0] != A[0][k] && A[i][1] != A[0][k] && A[i][0] != A[f][l] && A[i][1] != A[f][l])
					ok = false;
			if(ok) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}

// look at my code
// my code is amazing