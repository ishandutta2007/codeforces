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
	cat K;
	cin >> N >> K;
	vector<int> par(N, 0);
	vector<cat> W(N, 0);
	for(int i = 0; i < N-1; i++) {
		int p;
		cat w;
		cin >> p >> w;
		par[i+1] = p-1;
		W[i+1] = W[p-1] ^ w;
	}
	sort(begin(W), end(W));
	vector<cat> A[2];
	A[0].resize(2*N);
	for(int i = 0; i < N; i++) A[0][i] = A[0][i+N] = W[i];
	vector<int> I[2];
	I[0] = {0, N, 2*N};
	vector<cat> w_nw0f, w_nw0s, w_nw1f, w_nw1s;
	cat ans = 0;
	for(int B = 61; B >= 0; B--) {
		cat cnt0 = 0;
		auto & I_cur = I[1-(B&1)];
		auto & I_nxt = I[B&1];
		auto & A_cur = A[1-(B&1)];
		auto & A_nxt = A[B&1];
		int n = I_cur.size()/3;
		for(int j = 0; j < n; j++) {
			int lf = I_cur[3*j], rf = I_cur[3*j+1];
			int ls = I_cur[3*j+1], rs = I_cur[3*j+2];
			cat cnt_cur0 = 0, cnt_cur1 = 0;
			for(int i = lf; i < rf; i++) {
				if((A_cur[i]>>B)&1) cnt_cur1++;
				else cnt_cur0++;
			}
			for(int i = ls; i < rs; i++) {
				if((A_cur[i]>>B)&1) cnt0 += cnt_cur1;
				else cnt0 += cnt_cur0;
			}
		}
		I_nxt.clear();
		A_nxt.clear();
		for(int j = 0; j < n; j++) {
			int lf = I_cur[3*j], rf = I_cur[3*j+1];
			int ls = I_cur[3*j+1], rs = I_cur[3*j+2];
			w_nw0f.clear();
			w_nw1f.clear();
			w_nw0s.clear();
			w_nw1s.clear();
			for(int i = lf; i < rf; i++) {
				if((A_cur[i]>>B)&1) w_nw1f.push_back(A_cur[i]);
				else w_nw0f.push_back(A_cur[i]);
			}
			for(int i = ls; i < rs; i++) {
				if((A_cur[i]>>B)&1) w_nw1s.push_back(A_cur[i]);
				else w_nw0s.push_back(A_cur[i]);
			}
			if(cnt0 >= K) {
				// bit 0
				if(!w_nw0f.empty() && !w_nw0s.empty()) {
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw0f, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw0s, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
				}
				if(!w_nw1f.empty() && !w_nw1s.empty()) {
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw1f, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw1s, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
				}
			}
			else {
				// bit 1
				if(!w_nw0f.empty() && !w_nw1s.empty()) {
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw0f, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw1s, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
				}
				if(!w_nw0s.empty() && !w_nw1f.empty()) {
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw0s, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
					ALL_THE(w_nw1f, it) A_nxt.push_back(*it);
					I_nxt.push_back(A_nxt.size());
				}
			}
		}
		if(cnt0 < K) {
			// bit 1
			ans ^= 1LL<<B;
			K -= cnt0;
		}
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing