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
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int lst[10000][4];
int popcnt[10000][10];
vector<int> ans[10000][9];

void solve(int cap, int fl, int qpos, auto & A, auto & B) {
	if(ans[cap][fl][qpos] != OVER9000) return;
	int N = A.size();
	for(int i = 0; i < 4; i++) if(lst[cap][i] != 9) {
		int fl_nw = lst[cap][i];
		int lst_nw[4] = {lst[cap][0], lst[cap][1], lst[cap][2], lst[cap][3]};
		for(int j = 0; j < 4; j++) if(lst_nw[j] == fl_nw) lst_nw[j] = 9;
		int qpos_nw = qpos;
		for(int j = 0; j < 4; j++) if(lst_nw[j] == 9 && qpos_nw < N && A[qpos_nw] == fl_nw) {
			lst_nw[j] = B[qpos_nw];
			qpos_nw++;
		}
		sort(lst_nw, lst_nw+4);
		int cap_nw = 0;
		for(int i = 3; i >= 0; i--) cap_nw = 10 * cap_nw + lst_nw[i];
		solve(cap_nw, fl_nw, qpos_nw, A, B);
		ans[cap][fl][qpos] = min(ans[cap][fl][qpos], ans[cap_nw][fl_nw][qpos_nw] + abs(fl-fl_nw));
	}
	if(qpos != N) if(cap%10 != 9 || (cap/10)%10 || (cap/100)%10 || cap/1000 != 9) {
		int fl_nw = A[qpos];
		int lst_nw[4] = {lst[cap][0], lst[cap][1], lst[cap][2], lst[cap][3]};
		for(int j = 0; j < 4; j++) if(lst_nw[j] == fl_nw) lst_nw[j] = 9;
		int qpos_nw = qpos;
		for(int j = 0; j < 4; j++) if(lst_nw[j] == 9 && qpos_nw < N && A[qpos_nw] == fl_nw) {
			lst_nw[j] = B[qpos_nw];
			qpos_nw++;
		}
		sort(lst_nw, lst_nw+4);
		int cap_nw = 0;
		for(int i = 3; i >= 0; i--) cap_nw = 10 * cap_nw + lst_nw[i];
		solve(cap_nw, fl_nw, qpos_nw, A, B);
		ans[cap][fl][qpos] = min(ans[cap][fl][qpos], ans[cap_nw][fl_nw][qpos_nw] + abs(fl-fl_nw));
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	for(int i = 0; i < 10000; i++) {
		int x = i;
		for(int j = 0; j < 10; j++) popcnt[i][j] = 0;
		for(int j = 0; j < 4; j++) {
			lst[i][j] = x % 10;
			popcnt[i][x%10]++;
			x /= 10;
		}
		sort(lst[i], lst[i]+4);
	}
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		A[i]--, B[i]--;
	}

	for(int i = 0; i < 10000; i++) for(int j = 0; j < 9; j++) {
		int x = 0;
		for(int k = 3; k >= 0; k--) x = 10 * x + lst[i][k];
		ans[x][j].resize(N+1, OVER9000);
	}
	for(int i = 0; i < 9; i++) ans[9999][i][N] = 0;
	solve(9999, 0, 0, A, B);
	cout << ans[9999][0][0] + 2*N << "\n";
	return 0;}

// look at my code
// my code is amazing