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
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void subsetsum(vector<int> H, vector<cat> &bitset) {
	int sz = bitset.size();
	for(int i = 0; i < (int)H.size(); i++) {
		int h = H[i]/60, hoff = H[i]%60, hoff2 = 60-H[i]%60;
		bitset[sz-1] |= (bitset[sz-1-h]<<hoff)&((1LL<<60)-1);
		for(int j = sz-2-h; j >= 0; j--) if(bitset[j]) {
			bitset[j+h+1] |= bitset[j]>>hoff2;
			bitset[j+h] |= (bitset[j]<<hoff)&((1LL<<60)-1);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, L, R;
	cin >> N >> L >> R;
	vector<int> A(N), B(N), H, H0;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) {
		cin >> B[i];
		if(B[i]) H0.push_back(A[i]);
		else H.push_back(A[i]);
	}
	sort(begin(H0), end(H0));
	N = H.size();
	int M = H0.size();
	vector<int> H0s = H0;
	H0s.insert(begin(H0s), 0);
	for(int i = 0; i < M; i++) H0s[i+1] += H0s[i];

	int lv = R/60+1;
	vector<cat> X(lv+1, 0);
	X[0] = 1;
	subsetsum(H, X);
	int ans = 0;
	for(int i = M-1; i >= 0; i--) {
		int minh = -1;
		for(int j = L/60; j <= lv; j++) if(X[j]) {
			for(int k = 0; k < 60; k++) if(60*j+k >= L) if((X[j]>>k)&1) {
				minh = 60*j+k;
				break;
			}
			if(minh >= L) break;
		}
		if(minh <= R && minh >= L) {
			auto it = upper_bound(begin(H0s), end(H0s), R-minh);
			it--;
			ans = max(ans, min(i+1, (int)(it-begin(H0s))));
		}
		subsetsum(vector<int>(1, H0[i]), X);
	}

	X = vector<cat>(lv+1, 0);
	X[0] = 1;
	vector<int> H1;
	for(int i = ans; i < M; i++) H1.push_back(H0[i]);
	subsetsum(H1, X);
	if(H0s[M]-H0s[ans] < 60*(lv+1)) {
		cat b = X[(H0s[M]-H0s[ans])/60] & (1LL<<((H0s[M]-H0s[ans])%60));
		X[(H0s[M]-H0s[ans])/60] ^= b;
	}
	subsetsum(H, X);
	for(int i = L; i <= R-H0s[ans]; i++) if((X[i/60]>>(i%60))&1) {
		ans++;
		break;
	}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing