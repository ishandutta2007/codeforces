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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> p(N), p_inv(N), A(M);
	for(int i = 0; i < N; i++) {
		cin >> p[i];
		p[i]--;
		p_inv[p[i]] = i;
	}
	for(int i = 0; i < M; i++) {
		cin >> A[i];
		A[i]--;
	}
	vector<int> first_occ_nxt(M);
	vector<int> last_occ(N, M);
	for(int i = M-1; i >= 0; i--) {
		last_occ[A[i]] = i;
		int p_nxt = p[(p_inv[A[i]] + 1) % N];
		first_occ_nxt[i] = last_occ[p_nxt];
	}
	vector< vector<int> > jump_nxt(20, vector<int>(M+1, M));
	for(int i = 0; i < M; i++) jump_nxt[0][i] = first_occ_nxt[i];
	for(int k = 1; k < 19; k++) for(int i = 0; i < M; i++)
		jump_nxt[k][i] = jump_nxt[k-1][jump_nxt[k-1][i]];
	vector<int> smallest_r(M+1, M);
	for(int i = 0; i < M; i++) {
		int cur = i, d = N-1;
		for(int k = 17; k >= 0; k--) if(d & (1<<k)) {
			cur = jump_nxt[k][cur];
			d -= 1<<k;
		}
		smallest_r[i] = cur;
	}
	vector< vector<int> > RMQ(20, vector<int>(M+1, M));
	RMQ[0] = smallest_r;
	for(int k = 1; k < 19; k++) for(int i = 0; i < M; i++)
		if(i+(1<<(k-1)) <= M) RMQ[k][i] = min(RMQ[k-1][i], RMQ[k-1][i+(1<<(k-1))]);
	for(int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		bool ans = (N == 1);
		int cur = l;
		for(int k = 17; k >= 0; k--) if(cur+(1<<k) <= r+1) {
			if(RMQ[k][cur] <= r) ans = true;
			cur += 1<<k;
		}
		cout << (ans ? "1" : "0");
	}
	cout << "\n";
	return 0;
}

// look at my code
// my code is amazing