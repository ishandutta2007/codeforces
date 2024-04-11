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
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	cat n_min = 0, n_max = 1LL * N * OVER9000 + 1;
	while(n_max-n_min > 1) {
		cat n_tr = (n_min + n_max) / 2;
		cat n_cur = n_tr;
		vector< pair<cat, cat> > B(N);
		for(int i = N-1; i >= 0; i--) {
			cat x = min(A[i]/2, n_cur);
			n_cur -= x;
			B[i].ss = x;
			B[i].ff = A[i] - 2 * x;
		}
		bool ok = (n_cur == 0);
		int pos = 0;
		if(ok) for(int i = 0; i < N; i++) {
			while(B[i].ss > 0 && pos <= i) {
				cat x = min(B[i].ss, B[pos].ff);
				B[pos].ff -= x;
				B[i].ss -= x;
				if(B[pos].ff == 0) pos++;
			}
			if(B[i].ss > 0) {
				ok = false;
				break;
			}
		}
		if(ok) n_min = n_tr;
		else n_max = n_tr;
	}
	cout << n_min << "\n";
	return 0;
}

// look at my code
// my code is amazing