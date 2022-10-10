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
	int N;
	int K[2];
	cin >> N >> K[0] >> K[1];
	vector<int> A[2];
	for(int k = 0; k < 2; k++) {
		A[k].resize(N);
		for(int i = 0; i < N; i++) cin >> A[k][i];
	}
	set< pair<int, int> > S;
	for(int i = 0; i < N; i++) S.insert(make_pair(abs(A[0][i]-A[1][i]), i));
	for(int k = 0; k < K[0]+K[1]; k++) {
		auto it = S.end(); it--;
		pair<int, int> p = *it;
		S.erase(it);
		if(p.ff == 0) p.ff = 1;
		else p.ff--;
		S.insert(p);
	}
	cat ans = 0;
	ALL_THE(S, it) ans += 1LL*(it->ff)*(it->ff);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing