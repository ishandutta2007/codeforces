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
	vector< vector<int> > A(N);
	vector<int> mx(N), mi(N), has(N, 0);
	for(int i = 0; i < N; i++) {
		int l;
		cin >> l;
		A[i].resize(l);
		for(int j = 0; j < l; j++) cin >> A[i][j];
		mx[i] = mi[i] = A[i][0];
		for(int j = 0; j < l; j++) mx[i] = max(mx[i], A[i][j]);
		for(int j = 0; j < l; j++) mi[i] = min(mi[i], A[i][j]);
		bool dec = true;
		for(int j = 1; j < l; j++) if(A[i][j-1] < A[i][j]) dec = false;
		if(dec) has[i] = 0;
		else has[i] = 1;
	}
	cat ans = 1LL * N * N;
	vector<int> MX, MI;
	for(int i = 0; i < N; i++) if(!has[i]) {
		MX.push_back(mx[i]);
		MI.push_back(mi[i]);
	}
	int K = MX.size();
	sort(begin(MX), end(MX));
	sort(begin(MI), end(MI));
	for(int i = 0, j = 0; i < K; i++) {
		while(j < K && MX[j] <= MI[i]) j++;
		ans -= j;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing