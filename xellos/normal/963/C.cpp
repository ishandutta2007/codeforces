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
#define OVER9000 1234567890123456789LL
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
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat gcd(cat x, cat y) {
	if(x > y) swap(x, y);
	return (x == 0) ? y : gcd(y%x, x);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	map<cat, int> sw, sh;
	vector< vector<cat> > C;
	for(int i = 0; i < N; i++) {
		cat w, h, c;
		cin >> w >> h >> c;
		if(sw.find(w) == sw.end()) {
			sw[w] = C.size();
			C.push_back(vector<cat>(sh.size(), 0));
		}
		if(sh.find(h) == sh.end()) {
			sh[h] = C[0].size();
			for(int j = 0; j < (int)C.size(); j++) C[j].push_back(0);
		}
		C[sw[w]][sh[h]] = c;
		if(1LL * C.size() * C[0].size() > N) {
			cout << "0\n";
			return 0;
		}
	}
	int nw = C.size(), nh = C[0].size();
	for(int i = 0; i < nw; i++) for(int j = 0; j < nh; j++) if(C[i][j] == 0) {
		cout << "0\n";
		return 0;
	}

	int ans = 1;
	for(cat i = 2; i <= 2000000; i++) {
		if(C[0][0] == 1) break;
		if(i*i > C[0][0]) i = C[0][0];
		if(C[0][0]%i != 0) continue;
		vector< vector<int> > mxp(nw, vector<int>(nh, 0));
		for(int j = 0; j < nw; j++) for(int k = 0; k < nh; k++)
			while(C[j][k]%i == 0) C[j][k] /= i, mxp[j][k]++;
		int cnt = 0;
		for(int a = 0; a <= mxp[0][0]; a++) {
			vector<int> xw(nw), xh(nh);
			xw[0] = a;
			for(int j = 0; j < nh; j++) xh[j] = mxp[0][j]-xw[0];
			for(int j = 1; j < nw; j++) xw[j] = mxp[j][0]-xh[0];
			bool ok = true;
			for(int j = 0; j < nh; j++) if(xh[j] < 0) ok = false;
			for(int j = 0; j < nw; j++) if(xw[j] < 0) ok = false;
			for(int j = 0; j < nw; j++) for(int k = 0; k < nh; k++)
				if(xw[j] + xh[k] != mxp[j][k]) ok = false;
			if(ok) cnt++;
		}
		ans *= cnt;
	}
	vector<cat> xw(nw), xh(nh);
	for(int i = 0; i < nw; i++) xw[i] = C[i][0];
	for(int i = 0; i < nh; i++) xh[i] = C[0][i];
	for(int i = 0; i < nw; i++) for(int j = 0; j < nh; j++)
		if(xw[i] * xh[j] != C[i][j]) ans = 0;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing