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
	vector< pair<cat, cat> > P(N);
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		P[i] = {x, y-1LL*x*x};
	}
	sort(begin(P), end(P));
	vector<int> H = {0};
	for(int i = 0; i < N; i++) {
		while((int)H.size() > 1) {
			int id2 = H.back(), id3 = H[H.size()-2];
			cat cp = (P[i].ss-P[id3].ss) * (P[id2].ff-P[id3].ff) - (P[i].ff-P[id3].ff) * (P[id2].ss-P[id3].ss); // cp == Club Penguin
			if(cp >= 0) H.pop_back();
			else break;
		}
		H.push_back(i);
	}
	while((int)H.size() > 1 && P[H.back()].ff == P[H[H.size()-2]].ff) H.pop_back();
	reverse(begin(H), end(H));
	while((int)H.size() > 1 && P[H.back()].ff == P[H[H.size()-2]].ff) H.pop_back();
	reverse(begin(H), end(H));
	int sz = H.size();
	// for(int i = 0; i < sz; i++) cout << P[H[i]].ff << " " << P[H[i]].ss << "\n";
	// vector<int> eq(sz-2, false);
	// for(int i = 0; i < sz-2; i++) {
	// 	int id1 = H[i+2], id2 = H[i+1], id3 = H[i];
	// 	cat cp = (P[id1].ss-P[id3].ss) * (P[id2].ff-P[id3].ff) - (P[id1].ff-P[id3].ff) * (P[id2].ss-P[id3].ss);
	// 	if(cp == 0) eq[i] = true;
	// }
	// cat ans = 0, last_eq = 0;
	// for(int i = 1; i < sz; i++) {
	// 	if(i > 1) {
	// 		if(!eq[i-2]) last_eq = i-1;
	// 	}
	// 	ans += i-last_eq;
	// }
	cout << sz-1 << "\n";
	// y = x^2 + x (y1-y2)/(x1-x2) - x (x1+x2) + (x1y2-x2y1) / x1-x2 + x1x2
	// v = x (v1-v2) / (x1-x2) + (x1v2-x2v1) / (x1-x2)
	// y3-x3^2 >= x3 (y1-x1^2-y2+x2^2)/(x1-x2) + (x1y2-x2y1)/(x1-x2) + x1x2
	// v3(x1-x2) >= (x3-x2)v1-(x3-x1)v2
	// v3x1+v1x2+v2x3 > v3x2+v1x3+v2x1
	// x1 < x2
	// x1=v1=0: v2x3-v3x2 > 0
	return 0;
}

// look at my code
// my code is amazing