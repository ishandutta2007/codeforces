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

struct pt {
	cat x, y;

	pt operator-(const pt & P) const {
		return {x-P.x, y-P.y};
	}

	bool operator<(const pt & P) const {
		if(x != P.x) return x < P.x;
		return y < P.y;
	}
};

cat vs(pt A, pt B) {
	return A.x * B.y - A.y * B.x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<pt> P(N);
	for(int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
	vector< vector<int> > G(N*N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(i != j)
		for(int k = 0; k < N; k++) if(i != k && j != k)
			if(vs(P[k]-P[i], P[j]-P[i]) > 0)
				G[i*N+j].push_back(j*N+k);

	vector< vector<int> > cnt_c(N, vector<int>(N, 0));
	for(int i = 1; i < N; i++) for(int j = 1; j < N; j++) {
		if(vs(P[i]-P[0], P[j]-P[0]) <= 0) continue;
		bool sgn_0 = (vs(P[0]-P[i], P[j]-P[i]) > 0);
		for(int k = 1; k < N; k++) if(i != k && j != k) {
			if(vs(P[i]-P[0], P[k]-P[0]) <= 0) continue;
			if(vs(P[k]-P[0], P[j]-P[0]) <= 0) continue;
			bool sgn_k = (vs(P[k]-P[i], P[j]-P[i]) > 0);
			if(sgn_k == sgn_0) cnt_c[i][j]++;
		}
		cnt_c[j][i] = cnt_c[i][j];
	}

	cat ans = 1LL * N * (N-1) * (N-2) * (N-3) * (N-4) / 60;
	for(int i = 1; i < N; i++) for(int j = 1; j < N; j++) {
		if(vs(P[i]-P[0], P[j]-P[0]) <= 0) continue;
		// convex hull = quadrilateral
		ans -= 1LL * cnt_c[i][j] * (N-4);
		// convex hull = triangle
		ans += 1LL * cnt_c[i][j] * (cnt_c[i][j]-1);
		for(int k = 1; k < N; k++) if(i != k && j != k) {
			bool s1 = (vs(P[i]-P[0], P[k]-P[0]) > 0);
			bool s2 = (vs(P[k]-P[0], P[j]-P[0]) > 0);
			if(s1 != s2) continue;
			if(!s1) if(k > i || k > j) continue;
			int cnt;
			if(s1) {
				cnt = cnt_c[i][k] + cnt_c[j][k] - cnt_c[i][j];
				if(cnt < 0) cnt = -cnt-1;
			}
			else cnt = 1 + cnt_c[i][k] + cnt_c[j][k] + cnt_c[i][j];
			// convex hull = quadrilateral
			ans -= 1LL * cnt * (N-4);
			// convex hull = triangle
			ans += 1LL * cnt * (cnt-1);
		}
	}

	ans /= 2;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing