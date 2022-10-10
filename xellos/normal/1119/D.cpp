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
	vector<cat> S(N);
	for(int i = 0; i < N; i++) cin >> S[i];
	sort(begin(S), end(S));
	vector<cat> dist(N);
	for(int i = 1; i < N; i++) dist[i] = S[i]-S[i-1];
	sort(begin(dist)+1, end(dist));
	vector<cat> Sdist(N+1, 0);
	for(int i = N-1; i >= 0; i--) Sdist[i] = Sdist[i+1] + dist[i];
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		cat l, D;
		cin >> l >> D;
		D -= l; // [0, D]
		cat ans = S[N-1]+D-S[0]+1;
		auto it = upper_bound(begin(dist)+1, end(dist), D);
		int i_min = it-begin(dist);
		ans += (D+1) * (N-i_min) - Sdist[i_min];
		cout << ans << ((q == Q-1) ? "\n" : " ");
	}
	return 0;
}

// look at my code
// my code is amazing