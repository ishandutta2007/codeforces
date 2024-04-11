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
#define soclose 1e-7
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename data_t>
class IntervalTree {
	struct node {
		int l, r;
		int son[2];
		int min_val;
	};
	vector<node> T;
	int N;

	void construct(int node_num) {
		node n = T[node_num];
		if(n.l+1 == n.r) return;
		for(int i = 0; i < 2; i++) {
			if(i == 0) n.r = (n.l+n.r) / 2;
			else {n.l = n.r; n.r = T[node_num].r;}
			T[node_num].son[i] = T.size();
			T.push_back(n);
			construct(T[node_num].son[i]);
		}
	}
	
public:
	IntervalTree(int N) : T{{0, N, {-1, -1}, OVER9000}}, N(N) {
		construct(0);
	}

	void put(int pos, data_t val, int node_num = 0) {
		node & n = T[node_num];
		if(n.l == pos && n.r == pos+1) {
			n.min_val = min(n.min_val, val);
			return;
		}
		if(pos < (n.l+n.r)/2) put(pos, val, n.son[0]);
		else put(pos, val, n.son[1]);
		n.min_val = min(T[n.son[0]].min_val, T[n.son[1]].min_val);
	}

	int get(int l, int r, int node_num = 0) {
		node & n = T[node_num];
		if(n.l >= r || l >= n.r) return OVER9000;
		if(n.l == l && n.r == r) return n.min_val;
		int val_l = get(l, min(r, (n.l+n.r)/2), n.son[0]);
		int val_r = get(max(l, (n.l+n.r)/2), r, n.son[1]);
		return min(val_l, val_r);
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int MX[3];
	int N[2], Q;
	cin >> MX[0] >> MX[1] >> MX[2] >> N[0] >> N[1] >> Q;
	vector< vector<int> > info[2];
	int sure_range[3][2];
	for(int i = 0; i < 3; i++) sure_range[i][0] = MX[i]+1, sure_range[i][1] = -1;
	for(int k = 0; k < 2; k++) {
		info[k].resize(N[k], vector<int>(3));
		for(int i = 0; i < N[k]; i++) {
			int ok = 0;
			for(int j = 0; j < 3; j++) {
				cin >> info[k][i][j];
				if(k == 0) {
					sure_range[j][0] = min(sure_range[j][0], info[k][i][j]);
					sure_range[j][1] = max(sure_range[j][1], info[k][i][j]);
				}
				else if(sure_range[j][0] > info[k][i][j] || sure_range[j][1] < info[k][i][j]) ok++;
			}
			if(ok == 0 && k == 1) {
				cout << "INCORRECT\n";
				return 0;
			}
		}
	}
	cout << "CORRECT\n";
	vector< vector<int> > query(Q, vector<int>(3));
	vector<int> ans(Q);
	for(int q = 0; q < Q; q++) {
		bool is_yes = true;
		for(int i = 0; i < 3; i++) {
			cin >> query[q][i];
			if(query[q][i] < sure_range[i][0]) is_yes = false;
			if(query[q][i] > sure_range[i][1]) is_yes = false;
		}
		if(is_yes) ans[q] = 1;
		else ans[q] = -1;
	}
	vector<int> qg[8];
	for(int i = 0; i < Q; i++) if(ans[i] == -1) {
		int b = 0;
		for(int j = 0; j < 3; j++) if(query[i][j] < sure_range[j][0]) b |= 1<<j;
		qg[b].push_back(i);
	}
	for(int b = 0; b < 8; b++) {
		int Qc = qg[b].size();
		vector< vector<int> > q_val(Qc, vector<int>(3));
		for(int i = 0; i < Qc; i++) for(int j = 0; j < 3; j++)
			q_val[i][j] = ((b>>j)&1) ? MX[j]-query[qg[b][i]][j] : query[qg[b][i]][j];
		int lim[3];
		for(int j = 0; j < 3; j++) lim[j] = ((b>>j)&1) ? MX[j]-sure_range[j][0] : sure_range[j][1];
		vector< vector<int> > info_val;
		for(int i = 0; i < N[1]; i++) {
			bool skip = false;
			vector<int> val(3);
			for(int j = 0; j < 3; j++) {
				val[j] = ((b>>j)&1) ? MX[j]-info[1][i][j] : info[1][i][j];
				if(val[j] < (((b>>j)&1) ? MX[j]-sure_range[j][1] : sure_range[j][0])) skip = true;
			}
			if(!skip) info_val.push_back(val);
		}
		int n = info_val.size();
		vector< vector<int> > vs(MX[0]+10), qs(MX[0]+10);
		for(int i = 0; i < n; i++) vs[info_val[i][0]].push_back(i);
		for(int i = 0; i < Qc; i++) qs[q_val[i][0]].push_back(i);
		IntervalTree<int> I(MX[1]+10);
		for(int i = 0; i <= lim[0]; i++)
			ALL_THE(vs[i], it) I.put(info_val[*it][1], info_val[*it][2]);
		for(int i = 0; i < MX[0]+10; i++) {
			if(i > lim[0]) ALL_THE(vs[i], it) I.put(info_val[*it][1], info_val[*it][2]);
			ALL_THE(qs[i], it) if(I.get(0, max(lim[1], q_val[*it][1])+1) > max(lim[2], q_val[*it][2])) ans[qg[b][*it]] = 0;
		}
	}
	for(int i = 0; i < Q; i++) {
		if(ans[i] == 1) cout << "OPEN\n";
		if(ans[i] == 0) cout << "UNKNOWN\n";
		if(ans[i] == -1) cout << "CLOSED\n";
	}
	return 0;
}

// look at my code
// my code is amazing