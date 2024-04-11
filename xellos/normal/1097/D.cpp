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

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	cat N, mod = 1000000007;
	int K;
	cin >> N >> K;
	vector< pair<cat, int> > div_pw;
	for(cat i = 2; i*i <= N; i++) if(N%i == 0) {
		int e = 0;
		while(N%i == 0) N /= i, e++;
		div_pw.push_back({i, e});
	}
	if(N > 1) div_pw.push_back({N, 1});

	vector<cat> inv(1010, 1);
	for(int i = 1; i <= 1000; i++) inv[i] = pw(i, mod-2, mod) % mod;

	cat ans = 1;
	ALL_THE(div_pw, it) {
		vector< vector<cat> > E(K+1, vector<cat>(it->ss+1, 0));
		E[0][0] = 1;
		for(int i = 1; i <= it->ss; i++) E[0][i] = E[0][i-1] * it->ff % mod;
		for(int k = 1; k <= K; k++) for(int i = 0; i <= it->ss; i++) {
			for(int j = 0; j <= i; j++) E[k][i] += E[k-1][j];
			E[k][i] = E[k][i] % mod * inv[i+1] % mod;
		}
		ans = ans * E[K][it->ss] % mod;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing