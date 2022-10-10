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

struct line {
	cat c, v; // xv+c
	int id, active;

	bool operator<(const line & L) const {
		return v < L.v;
	}

	cat get_val(cat x) {
		return x*v+c;
	}
};

void DFS(int R, auto & G, auto & I) {
	I[R].ss = I[R].ff+1;
	for(auto v : G[R]) {
		I[v].ff = I[R].ss;
		DFS(v, G, I);
		I[R].ss = I[v].ss;
	}
}

void find_hull(vector<line> & H, vector<int> & ids) {
	ids = {0};
	for(int i = 1; i < (int)H.size(); i++) {
		while(!ids.empty() && H[ids.back()].v == H[i].v) {
			if(H[ids.back()].c < H[i].c) ids.pop_back();
			else break;
		}
		if(!ids.empty() && H[ids.back()].v == H[i].v) continue;
		while((int)ids.size() >= 2) {
			line & l0 = H[ids.back()];
			line & l1 = H[ids[ids.size()-2]];
			if(1.*(l0.c-H[i].c)*(l0.v-l1.v) <= 1.*(l1.c-l0.c)*(H[i].v-l0.v)+soclose)
				ids.pop_back();
			else break;
		}
		ids.push_back(i);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector< vector<int> > sons(N);
	vector<int> par(N, 0);
	for(int i = 1; i < N; i++) {
		cin >> par[i];
		sons[--par[i]].push_back(i);
	}
	vector< pair<int, int> > I(N, {0, 0});
	DFS(0, sons, I);

	vector<cat> A(N), C(N), A0(N), C0(N);
	for(int i = 0; i < N; i++) cin >> A0[i];
	for(int i = 1; i < N; i++) A0[i] += A0[par[i]];
	for(int i = 0; i < N; i++) A[I[i].ff] = A0[i];
	for(int i = 0; i < N; i++) cin >> C0[i];
	for(int i = 1; i < N; i++) C0[i] += C0[par[i]];
	for(int i = 0; i < N; i++) C[I[i].ff] = C0[i];

	int K = 250;
	vector< vector<line> > H[2];
	vector<int> hull_pos[2], hull_cur[2];
	vector<cat> hull_add[2];
	vector< vector<int> > hull_active_ids[2];
	for(int k = 0; k < 2; k++) {
		H[k].resize(N/K+1);
		for(int i = 0; i < N; i++) {
			int c = (k == 0) ? C[i] : -C[i];
			H[k][i/K].push_back({c*A[i], c, i, 1});
		}
		hull_pos[k].resize(N);
		hull_cur[k].resize(N/K+1);
		hull_add[k].resize(N/K+1);
		hull_active_ids[k].resize(N/K+1);
		for(int i = 0; i <= N/K; i++) {
			sort(begin(H[k][i]), end(H[k][i]));
			for(int j = 0; j < (int)H[k][i].size(); j++) hull_pos[k][H[k][i][j].id] = j;
			find_hull(H[k][i], hull_active_ids[k][i]);
			hull_cur[k][i] = 0;
			hull_add[k][i] = 0;
		}
	}

	for(int q = 0; q < Q; q++) {
		int tp, v;
		cin >> tp >> v;
		int l = I[v-1].ff, r = I[v-1].ss;

		if(tp == 2) {
			cat ans = 0;
			while(l < r && l%K != 0) {
				cat val = C[l] * (A[l] + hull_add[0][l/K]);
				ans = max(ans, abs(val));
				l++;
			}
			while(l < r && r%K != 0) {
				r--;
				cat val = C[r] * (A[r] + hull_add[0][r/K]);
				ans = max(ans, abs(val));
			}
			for(int i = l/K; i < r/K; i++) for(int k = 0; k < 2; k++) {
				int sz = hull_active_ids[k][i].size(), cur = hull_cur[k][i];
				vector<int> & ids = hull_active_ids[k][i];
				cat val_cur = H[k][i][ids[cur]].get_val(hull_add[k][i]);
				while(cur+1 < sz) {
					cat val_nxt = H[k][i][ids[cur+1]].get_val(hull_add[k][i]);
					if(val_nxt < val_cur) break;
					cur++;
					val_cur = val_nxt;
				}
				hull_cur[k][i] = cur;
				ans = max(ans, abs(val_cur));
			}
			cout << ans << "\n";
			continue;
		}

		cat x;
		cin >> x;
		if(l%K != 0) {
			int hid = l/K;
			for(int i = l-l%K; i < l; i++) {
				A[i] += hull_add[0][hid];
				H[0][hid][hull_pos[0][i]].c += C[i] * (hull_add[0][hid]);
				H[1][hid][hull_pos[1][i]].c -= C[i] * (hull_add[1][hid]);
			}
			for(int i = l; i < min(r, l-l%K+K); i++) {
				A[i] += x + hull_add[0][hid];
				H[0][hid][hull_pos[0][i]].c += C[i] * (x + hull_add[0][hid]);
				H[1][hid][hull_pos[1][i]].c -= C[i] * (x + hull_add[1][hid]);
			}
			for(int i = min(r, l-l%K+K); i < min(N, l-l%K+K); i++) {
				A[i] += hull_add[0][hid];
				H[0][hid][hull_pos[0][i]].c += C[i] * (hull_add[0][hid]);
				H[1][hid][hull_pos[1][i]].c -= C[i] * (hull_add[1][hid]);
			}
			find_hull(H[0][hid], hull_active_ids[0][hid]);
			find_hull(H[1][hid], hull_active_ids[1][hid]);
			hull_cur[0][hid] = hull_cur[1][hid] = 0;
			hull_add[0][hid] = hull_add[1][hid] = 0;
			l = min(r, l-l%K+K);
		}
		if(l < r && r%K != 0) {
			int hid = r/K;
			for(int i = min(N-1, hid*K+K-1); i >= r; i--) {
				A[i] += hull_add[0][hid];
				H[0][hid][hull_pos[0][i]].c += C[i] * (hull_add[0][hid]);
				H[1][hid][hull_pos[1][i]].c -= C[i] * (hull_add[1][hid]);
			}
			for(int i = r-1; i >= max(l, hid*K); i--) {
				A[i] += x + hull_add[0][hid];
				H[0][hid][hull_pos[0][i]].c += C[i] * (x + hull_add[0][hid]);
				H[1][hid][hull_pos[1][i]].c -= C[i] * (x + hull_add[1][hid]);
			}
			for(int i = max(l, hid*K)-1; i >= hid*K; i--) {
				A[i] += hull_add[0][hid];
				H[0][hid][hull_pos[0][i]].c += C[i] * (hull_add[0][hid]);
				H[1][hid][hull_pos[1][i]].c -= C[i] * (hull_add[1][hid]);
			}
			find_hull(H[0][hid], hull_active_ids[0][hid]);
			find_hull(H[1][hid], hull_active_ids[1][hid]);
			hull_cur[0][hid] = hull_cur[1][hid] = 0;
			hull_add[0][hid] = hull_add[1][hid] = 0;
			r = max(l, r-r%K);
		}
		for(int i = l/K; i < r/K; i++) {
			hull_add[0][i] += x;
			hull_add[1][i] += x;
		}
	}
	return 0;
}

// look at my code
// my code is amazing