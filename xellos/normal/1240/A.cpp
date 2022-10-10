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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> P(N);
		for(int i = 0; i < N; i++) {
			cin >> P[i];
			P[i] /= 100;
		}
		vector<int> C(N, 0);
		int X, A, Y, B;
		cin >> X >> A >> Y >> B;
		for(int i = A-1; i < N; i += A) C[i] += X;
		for(int i = B-1; i < N; i += B) C[i] += Y;
		cat max_C = 0;
		sort(begin(P), end(P));
		vector<int> Cs = C;
		sort(begin(Cs), end(Cs));
		for(int i = 0; i < N; i++) max_C += 1LL * P[i] * Cs[i];
		cat K;
		cin >> K;
		if(max_C < K) {
			cout << "-1\n";
			continue;
		}
		int nl = 0, nr = N;
		while(nr-nl > 1) {
			int n = (nl+nr)/2;
			vector<char> used(n, 0);
			max_C = 0;
			int n_cur = 0;
			for(int k = 0; k < 4; k++) {
				int v = 0;
				for(int i = 0; i < n; i++) if(!used[i]) v = max(v, C[i]);
				for(int i = 0; i < n; i++) if(!used[i] && v == C[i]) {
					max_C += 1LL * P[N-1-n_cur] * v;
					used[i] = 1;
					n_cur++;
				}
			}
			if(max_C >= K) nr = n;
			else nl = n;
		}
		cout << nr << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing