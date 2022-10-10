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
	cat N;
	cin >> N;
	cat L[2] = {1, 1}, R[2] = {N+1, N+1}, C[2] = {0, 0};
	while(R[0]-L[0] > 1 || R[1]-L[1] > 1) {
		cat d[2] = {R[0]-C[0]-1, R[1]-C[1]-1};
		cat mid[2] = {(C[0]+R[0]+1)/2, (C[1]+R[1]+1)/2};
		if(min(d[0], d[1])*2 < max(d[0], d[1]))
			if(2*d[0] < R[0]-L[0] && 2*d[1] < R[1]-L[1]) {
				if(d[0] < d[1]) mid[0] = max(L[0], C[0]);
				else mid[1] = max(L[1], C[1]);
			}
		cout << N+1-mid[0] << " " << N+1-mid[1] << "\n";
		cout << flush;
		int ans;
		cin >> ans;
		if(ans == 0) return 0;
		if(ans == 3) {
			C[0] = mid[0];
			C[1] = mid[1];
		}
		else R[ans-1] = mid[ans-1];
		if(C[0]+1 >= R[0]) {
			L[1] = C[1]+1;
			C[0] = L[0]-1;
		}
		else if(C[1]+1 >= R[1]) {
			L[0] = C[0]+1;
			C[1] = L[1]-1;
		}
	}
	cout << N+1-L[0] << " " << N+1-L[1] << "\n";
	cout << flush;
	int ans;
	cin >> ans;
	return 0;
}

// look at my code
// my code is amazing