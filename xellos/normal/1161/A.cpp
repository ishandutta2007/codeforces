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
	int N, K;
	cin >> N >> K;
	vector<int> Q(K);
	for(int i = 0; i < K; i++) {
		cin >> Q[i];
		Q[i]--;
	}
	vector<int> asked(N, 0), first_occ(N, -1);
	for(int i = K-1; i >= 0; i--) first_occ[Q[i]] = i;
	int ans = 0;
	for(int i = K-1; i >= 0; i--) {
		if(first_occ[Q[i]] == i) {
			if(Q[i] > 0 && asked[Q[i]-1] == 0) ans++;
			if(Q[i]+1 < N && asked[Q[i]+1] == 0) ans++;
		}
		asked[Q[i]]++;
	}
	for(int i = 0; i < N; i++) if(asked[i] == 0) {
		ans++;
		if(i > 0) ans++;
		if(i < N-1) ans++;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing