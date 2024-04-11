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
	int N, M, Ns, Ne, V, Q;
	cin >> N >> M >> Ns >> Ne >> V;
	set<int> S, E;
	for(int i = 0; i < Ns; i++) {
		int x;
		cin >> x;
		S.insert(x);
	}
	for(int i = 0; i < Ne; i++) {
		int x;
		cin >> x;
		E.insert(x);
	}
	cin >> Q;
	for(int i = 0; i < Q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2) {
			cout << abs(y1-y2) << "\n";
			continue;
		}
		auto it = S.lower_bound(y1);
		int ans = OVER9000;
		if(it != S.end())
			ans = min(ans, abs(x2-x1) + abs(y2-*it) + abs(y1-*it));
		it = S.lower_bound(y1);
		if(it != S.begin()) {
			it--;
			ans = min(ans, abs(x2-x1) + abs(y2-*it) + abs(y1-*it));
		}
		it = E.lower_bound(y1);
		if(it != E.end())
			ans = min(ans, (abs(x2-x1)+V-1)/V + abs(y2-*it) + abs(y1-*it));
		it = E.lower_bound(y1);
		if(it != E.begin()) {
			it--;
			ans = min(ans, (abs(x2-x1)+V-1)/V + abs(y2-*it) + abs(y1-*it));
		}
		cout << ans << "\n";
	}
	return 0;}

// look at my code
// my code is amazing