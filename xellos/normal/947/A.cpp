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

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int X;
	cin >> X;
	int Y = X;
	vector<int> P;
	for(int i = 2; i <= Y; i++) if(Y%i == 0) {
		P.push_back(i);
		while(Y%i == 0) Y /= i;
	}
	int MX = 1000000;
	vector<bool> isP(MX+1, 1);
	for(int p = 2; p <= MX; p++) if(isP[p])
		for(int i = 2; i <= MX/p; i++) isP[i*p] = 0;
	int ans = X;
	ALL_THE(P, it) {
		int p = *it;
		// X2 >= X1, X2-p < X1, p < X1
		// max(X2-p, p) < X1 <= X2
		for(int r = 2; r <= MX; r++) if(isP[r]) {
			// r < X0 <= X1, X1%r == 0, X1-r < X0
			// max(r, X1-r) < X0 <= X1; X0 == max(r, X1-r)+1
			// min. X1: X1%r == 0, max(X2-p, p, r) < X1 <= X2
			int minx1 = max(X-p, max(p, r))+1;
			if(minx1%r != 0) minx1 += r-minx1%r;
			if(minx1 <= X)
				ans = min(ans, max(r, minx1-r)+1);
		}
	}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing