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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	return (a == 0) ? b : gcd(b%a, a);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	cat L[2], R[2], T[2];
	for(int i = 0; i < 2; i++) cin >> L[i] >> R[i] >> T[i];
	cat g = gcd(T[0], T[1]);
	cat ans = 0;
	for(int k = 0; k < 2; k++) {
		cat r0 = L[0] % T[1], y = L[1];
		// x >= y, x = r0 + g*k
		cat x = y - y % g + r0;
		while(x < y) x += g;
		while(x-g >= y) x -= g;
		if(x < T[1]) {
			cat r1 = y+R[1]-L[1], r0 = x+R[0]-L[0];
			ans = max(ans, min(r1, r0)-max(x, y)+1);
		}
		swap(L[0], L[1]);
		swap(R[0], R[1]);
		swap(T[0], T[1]);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing