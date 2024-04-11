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
	int Q;
	cin >> Q;
	vector<cat> rot(1000, 0);
	for(int q = 0; q < Q; q++) {
		int tp;
		cat X, K;
		cin >> tp >> X;
		int lvl = 0;
		cat x = X;
		while(x > 1) {
			x /= 2;
			lvl++;
		}
		if(tp <= 2) {
			cin >> K;
			K %= 1LL<<lvl;
			if(K < 0) K += 1LL<<lvl;
			rot[lvl] = (rot[lvl] + K) % (1LL<<lvl);
			if(rot[lvl] < 0) rot[lvl] += (1LL<<lvl);
			if(tp == 2) for(int i = lvl+1; i < 80; i++) {
				rot[i] = (rot[i] + (1LL<<(i-lvl)) * K) % (1LL<<i);
				if(rot[i] < 0) rot[i] += (1LL<<i);
			}
			continue;
		}
		cat w = X - (1LL<<lvl);
		cat X_orig = (w+rot[lvl]) % (1LL<<lvl);
		if(X_orig < 0) X_orig += 1LL<<lvl;
		X_orig += 1LL<<lvl;
		cat Y_orig = X_orig;
		for(int i = lvl; i >= 0; i--) {
			cat Y = Y_orig - (1LL<<i);
			Y = (Y - rot[i]) % (1LL<<i);
			if(Y < 0) Y += 1LL<<i;
			Y += 1LL<<i;
			cout << Y << ((i == 0)?"\n":" ");
			Y_orig /= 2;
		}
	}
	return 0;}

// look at my code
// my code is amazing