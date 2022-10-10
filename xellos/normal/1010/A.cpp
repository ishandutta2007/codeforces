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
#define soclose 1e-7
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl double
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
	dbl m;
	cin >> N >> m;
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if(A[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	for(int i = 0; i < N; i++) {
		cin >> B[i];
		if(B[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	dbl fmi = 0, fmx = 2e9;
	while(fmx-fmi > soclose) {
		dbl f = (fmi + fmx) / 2;
		bool ok = true;
		for(int i = 0; i < N; i++) {
			dbl x = (f+m)/A[i];
			if(x > f-soclose) {ok = false; break;}
			f -= x;
			dbl y = (f+m)/B[(i+1)%N];
			if(y > f-soclose) {ok = false; break;}
			f -= y;
		}
		if(ok) fmx = (fmi+fmx) / 2;
		else fmi = (fmi+fmx) / 2;
	}
	cout << fmx << "\n";
	return 0;
}

// look at my code
// my code is amazing