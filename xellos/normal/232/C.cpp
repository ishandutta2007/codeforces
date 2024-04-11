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

cat sz[82] = {1, 2};
 
pair<int, int> solve_pair(cat x, int k) {
	// dist. to 0, sz[k]-1
	if(x == 0) return {0, (k+1)/2};
	if(x == sz[k]-1) return {(k+1)/2, 0};
	if(x >= sz[k-1]) {
		pair<int, int> prev = solve_pair(x-sz[k-1], k-2);
		prev.ff++;
		return prev;
	}
	// x < sz[k-1]
	pair<int, int> prev = solve_pair(x, k-1);
	return {min(prev.ff, prev.ss+2), min(prev.ff, prev.ss) + (k+1)/2};
}
 
int solve(cat a, cat b, int k) {
	if(a > b) swap(a, b);
	if(a == b) return 0;
	if(k == 1) return 1;
	while(sz[k-2] > b) k--;
	if(a == 0 && b == sz[k]-1) return (k+1)/2;
	if(a >= sz[k-1]) return solve(a-sz[k-1], b-sz[k-1], k-2);
	if(b >= sz[k-1] && a < sz[k-1]) {
		pair<int, int> d_a = solve_pair(a, k-1);
		pair<int, int> d_b = solve_pair(b-sz[k-1], k-2);
		return min(d_a.ff, d_a.ss) + d_b.ff + 1;
	}
	else { // a, b < sz[k-1]
		int d0 = solve(a, b, k-1);
		pair<int, int> d_a = solve_pair(a, k-1);
		pair<int, int> d_b = solve_pair(b, k-1);
		return min(d0, min(d_a.ff+d_b.ss, d_a.ss+d_b.ff)+2);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T, N;
	cin >> T >> N;
	N = min(N, 81);
	for(int i = 2; i <= 81; i++) sz[i] = sz[i-1] + sz[i-2];
	while(T--) {
		cat a, b;
		cin >> a >> b;
		cout << solve(a-1, b-1, N) << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing