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
	int N, Q;
	cat L;
	cin >> N >> Q >> L;
	vector<cat> A(N+2, L);
	for(int i = 0; i < N; i++) cin >> A[i+1];
	int cnt_pos = 0;
	for(int i = 1; i <= N+1; i++) {
		if(A[i] <= L && A[i-1] <= L) continue;
		if(A[i] > L && A[i-1] > L) continue;
		cnt_pos++;
	}
	for(int i = 0; i < Q; i++) {
		int tp;
		cin >> tp;
		if(tp == 0) {
			cout << cnt_pos/2 << "\n";
			continue;
		}
		int p, d;
		cin >> p >> d;
		for(int k = p; k <= p+1; k++) if(k >= 1 && k <= N+1)
			if((A[k] <= L) != (A[k-1] <= L)) cnt_pos--;
		A[p] += d;
		for(int k = p; k <= p+1; k++) if(k >= 1 && k <= N+1)
			if((A[k] <= L) != (A[k-1] <= L)) cnt_pos++;
	}
	return 0;
}

// look at my code
// my code is amazing