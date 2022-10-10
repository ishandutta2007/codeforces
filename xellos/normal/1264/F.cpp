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
	cat f0 = 0, f1 = 1, offset = 0;
	constexpr cat m = 1'000'000;
	while(true) {
		cat f2 = f0+f1;
		if(f2 >= m*m) f2 -= m*m;
		f0 = f1;
		f1 = f2;
		offset++;
		if(f0%m == 0 && (f1-1)%m == 0) {
			cat x = (f1-1)/m;
			if(x%2 == 0 || x%5 == 0) continue;
			// F_(offset*k+1) = (xm+1)^k
			cat N, A, D;
			cin >> N >> A >> D;
			cat b = 0, e = 0;
			while((x*b - A) % m != 0) b++;
			while((x*e - D) % m != 0) e++;
			cout << offset * b + 1 << " " << offset * e << "\n";
			return 0;
		}
	}
	return 0;
}

// look at my code
// my code is amazing