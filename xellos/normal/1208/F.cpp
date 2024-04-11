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

void upd(int x, int b, auto & first_occ, auto & occ, int pos, bool used = false) {
	if(first_occ[x] >= 0) return;
	if(!used) occ[x]++;
	if(occ[x] >= 2) first_occ[x] = pos;
	if(x < (1<<b)) return;
	while(((x>>b)&1) == 0) b++;
	upd(x^(1<<b), b+1, first_occ, occ, pos, false);
	upd(x, b+1, first_occ, occ, pos, true);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, MX = (1<<22);
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> first_occ(MX, -1), occ(MX, 0);
	first_occ[0] = N-2;
	for(int i = N-1; i >= 0; i--)
		upd(A[i], 0, first_occ, occ, i);
	for(int i = MX-1; i >= 0; i--) for(int j = 0; j < 22; j++)
		if((i>>j)&1) first_occ[i^(1<<j)] = max(first_occ[i^(1<<j)], first_occ[i]);
	int ans = 0;
	for(int i = 0; i < N-2; i++) {
		int r = MX-1-A[i];
		int x = 0;
		for(int b = 21; b >= 0; b--) if((r>>b)&1)
			if(first_occ[x|(1<<b)] > i) x |= 1<<b;
		ans = max(ans, A[i]+x);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing