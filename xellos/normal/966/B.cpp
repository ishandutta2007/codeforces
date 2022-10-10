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
	int X[2];
	cin >> N >> X[0] >> X[1];
	vector< pair<int, int> > C(N);
	for(int i = 0; i < N; i++) {
		cin >> C[i].ff;
		C[i].ss = i;
	}
	sort(begin(C), end(C));
	for(int k0 = 1; k0 < N; k0++) {
		if(1LL*C[N-k0].ff*k0 < X[0]) continue;
		for(int k1 = 1; k1 <= N-k0; k1++) {
			if(1LL*C[N-k0-k1].ff*k1 < X[1]) continue;
			cout << "Yes\n" << k0 << " " << k1 << "\n";
			for(int i = 0; i < k0; i++) cout << C[N-k0+i].ss+1 << ((i == k0-1)?"\n":" ");
			for(int i = 0; i < k1; i++) cout << C[N-k0-k1+i].ss+1 << ((i == k1-1)?"\n":" ");
			return 0;
		}
		break;
	}
	for(int k1 = 1; k1 < N; k1++) {
		if(1LL*C[N-k1].ff*k1 < X[1]) continue;
		for(int k0 = 1; k0 <= N-k1; k0++) {
			if(1LL*C[N-k0-k1].ff*k0 < X[0]) continue;
			cout << "Yes\n" << k0 << " " << k1 << "\n";
			for(int i = 0; i < k0; i++) cout << C[N-k0-k1+i].ss+1 << ((i == k0-1)?"\n":" ");
			for(int i = 0; i < k1; i++) cout << C[N-k1+i].ss+1 << ((i == k1-1)?"\n":" ");
			return 0;
		}
		break;
	}
	cout << "No\n";
	return 0;}

// look at my code
// my code is amazing