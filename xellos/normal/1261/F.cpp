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
	int N[2];
	vector< pair<cat, cat> > S[2];
	for(int k = 0; k < 2; k++) {
		cin >> N[k];
		S[k].resize(N[k]);
		for(int i = 0; i < N[k]; i++) cin >> S[k][i].ff >> S[k][i].ss;
	}
	for(int k = 0; k < 2; k++) {
		sort(begin(S[k]), end(S[k]));
		int cur = 0;
		for(int i = 0; i < (int)S[k].size(); i++) {
			if(cur && S[k][i].ff <= S[k][cur-1].ss+1)
				S[k][cur-1].ss = max(S[k][cur-1].ss, S[k][i].ss);
			else S[k][cur++] = S[k][i];
		}
		S[k].resize(cur);
	}
	vector<cat> X[2][60], Y[2][60];
	for(int k = 0; k < 2; k++) for(int i = 0; i < N[k]; i++) {
		auto [l, r] = S[k][i];
		for(int d = 0; d < 60; d++) {
			if((l>>d)&1) {
				X[k][d].push_back(l >> d);
				l += 1LL<<d;
			}
			if(l <= r && ((r>>d)&1) == 0) {
				X[k][d].push_back(r >> d);
				r -= 1LL<<d;
			}
			if(l > r) break;
		}
		for(int d = 0; d < 60; d++) {
			Y[k][d].push_back(S[k][i].ff >> d);
			Y[k][d].push_back(S[k][i].ss >> d);
		}
	}
	for(int k = 0; k < 60; k++) {
		sort(begin(X[0][k]), end(X[0][k]));
		auto it = unique(begin(X[0][k]), end(X[0][k]));
		X[0][k].resize(it-begin(X[0][k]));
		sort(begin(X[1][k]), end(X[1][k]));
		it = unique(begin(X[1][k]), end(X[1][k]));
		X[1][k].resize(it-begin(X[1][k]));
		sort(begin(Y[0][k]), end(Y[0][k]));
		it = unique(begin(Y[0][k]), end(Y[0][k]));
		Y[0][k].resize(it-begin(Y[0][k]));
		sort(begin(Y[1][k]), end(Y[1][k]));
		it = unique(begin(Y[1][k]), end(Y[1][k]));
		Y[1][k].resize(it-begin(Y[1][k]));
	}
	vector< pair<cat, cat> > seg;
	for(int k = 59; k >= 0; k--) {
		static vector< pair<cat, cat> > seg_next;
		seg_next.clear();
		static vector<cat> Z;
		Z.dibs((X[0][k].size() + Y[0][k].size()) * (X[1][k].size() * Y[1][k].size()));
		Z.clear();
		for(auto x : X[0][k]) for(auto y : Y[1][k]) Z.push_back(x^y);
		for(auto x : Y[0][k]) for(auto y : X[1][k]) Z.push_back(x^y);
		for(auto x : X[0][k]) for(auto y : X[1][k]) Z.push_back(x^y);
		sort(begin(Z), end(Z));
		int a = 0;
		for(int i = 0; i < (int)Z.size(); i++) {
			if(i && Z[i] == Z[i-1]) continue;
			cat l = Z[i] << k;
			while(a < (int)seg.size() && seg[a].ss <= l) {
				seg_next.push_back(seg[a]);
				a++;
			}
			if(a < (int)seg.size() && seg[a].ff <= l) continue;
			seg_next.push_back({l, l + (1LL<<k)});
		}
		while(a < (int)seg.size()) {
			seg_next.push_back(seg[a]);
			a++;
		}
		seg.clear();
		for(int i = 0; i < (int)seg_next.size(); i++) {
			if(i && seg.back().ss == seg_next[i].ff)
				seg.back().ss = seg_next[i].ss;
			else seg.push_back(seg_next[i]);
		}
	}
	cat mod = 998244353, ans = 0;
	for(auto [l, r] : seg) {
		cat f1 = r-l, f2 = r+l-1;
		if(f1%2 == 0) f1 /= 2;
		else f2 /= 2;
		f1 %= mod, f2 %= mod;
		// cerr << l << " " << r << "\n";
		ans += f1 * f2 % mod;
	}
	ans %= mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing