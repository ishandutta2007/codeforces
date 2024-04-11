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
	int N[2];
	vector<int> A[2], X[2];
	map<int, int> As[2];
	for(int k = 0; k < 2; k++) {
		cin >> N[k];
		A[k].resize(N[k]);
		X[k].resize(N[k]);
		for(int i = 0; i < N[k]; i++) {
			cin >> A[k][i] >> X[k][i];
			As[k][A[k][i]] = X[k][i];
		}
	}
	map<int, int> common;
	cat ans = 0;
	for(int k = 0; k < 2; k++) ALL_THE(As[k], it) {
		if(As[1-k].find(it->ff) == end(As[1-k])) ans += it->ss;
		else common[it->ff] = max(it->ss, As[1-k][it->ff]);
	}
	ALL_THE(common, it) ans += it->ss;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing