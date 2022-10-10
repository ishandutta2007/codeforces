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

cat lcm(cat a, cat b) {
	return a / gcd(a, b) * b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K, A, B;
	cin >> N >> K >> A >> B;
	cat min_stops = 1LL*N*K, max_stops = 0;
	for(int sa = 0; sa < 2; sa++) for(int sb = 0; sb < 2; sb++) {
		int s = sa ? (K-A) % K : A;
		int nxt_rem = sb ? (K-B) % K : B;
		for(int i = 0; i < N; i++) {
			cat nxt = nxt_rem + 1LL * i * K;
			cat L = nxt - s;
			if(L < 0) L += 1LL*N*K;
			L %= 1LL*N*K;
			if(L == 0) L += 1LL*N*K;
			cat stops = 1LL*N*K / gcd(L, 1LL*N*K);
			min_stops = min(min_stops, stops);
			max_stops = max(max_stops, stops);
		}
	}
	cout << min_stops << " " << max_stops << "\n";
	return 0;
}

// look at my code
// my code is amazing