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
	int N, K;
	cin >> N >> K;
	vector<int> A(N), X(N+1, 0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		X[i+1] = X[i] ^ A[i];
	}
	map<int, int> XM;
	for(int i = 0; i <= N; i++) XM[X[i]] = XM[(1<<K)-1-X[i]] = 0;
	for(int i = 0; i <= N; i++) XM[X[i]]++;
	ALL_THE(XM, it) {
		if(it->ff >= (1<<K)-1-it->ff) break;
		int s = it->ss + XM[(1<<K)-1-it->ff];
		it->ss = s/2;
		XM[(1<<K)-1-it->ff] = s-s/2;
	}
	cat ans = 0;
	ALL_THE(XM, it) {
		ans += 1LL * it->ss * (it->ss-1) / 2;
	}
	cout << 1LL*N*(N+1)/2 - ans << "\n";
	return 0;
}

// look at my code
// my code is amazing