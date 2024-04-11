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
	vector<int> L(N), R(N);
	vector< pair<int, int> > S(N);
	for(int i = 0; i < N; i++) {
		cin >> L[i];
		S[i] = {L[i], i};
	}
	for(int i = 0; i < N; i++) {
		cin >> R[i];
		S[i].ff += R[i];
	}
	sort(begin(S), end(S));
	vector<int> A(N, 0);
	int mxa = N;
	for(int i = 0; i < N; i++) if(i == 0 || S[i].ff != S[i-1].ff) {
		for(int j = i; j < N; j++) if(S[j].ff == S[i].ff) {
			int x = S[j].ss;
			int l = 0, r = 0;
			for(int k = 0; k < x; k++) if(A[k] > mxa) l++;
			for(int k = x+1; k < N; k++) if(A[k] > mxa) r++;
			if(l != L[x] || r != R[x]) {
				cout << "NO\n";
				return 0;
			}
			A[x] = mxa;
		}
		mxa--;
	}
	cout << "YES\n";
	for(int i = 0; i < N; i++) cout << A[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing