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
	cin >> N;
	vector<int> A(N), P(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> Pp_occ[18];
	for(int i = 0; i < 18; i++) Pp_occ[i].resize(1<<(18-i), 0);
	multiset<int> Pp[12];
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		for(int j = 0; j < 12; j++) Pp[j].insert(P[i]>>j);
		for(int j = 12; j < 30; j++) Pp_occ[j-12][P[i]>>j]++;
	}
	for(int i = 0; i < N; i++) {
		int K = 0;
		for(int j = 29; j >= 0; j--) {
			int b = A[i]&(1<<j);
			if(j < 12) {
				if(Pp[j].find((K|b)>>j) != end(Pp[j])) K |= b;
				else K |= b^(1<<j);
			}
			else {
				if(Pp_occ[j-12][(K|b)>>j] != 0) K |= b;
				else K |= b^(1<<j);
			}
		}
		for(int j = 0; j < 12; j++) Pp[j].erase(Pp[j].find(K>>j));
		for(int j = 12; j < 30; j++) Pp_occ[j-12][K>>j]--;
		cout << (A[i]^K) << ((i == N-1)?"\n":" ");
	}
	return 0;}

// look at my code
// my code is amazing