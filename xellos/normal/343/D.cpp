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
#define OVER9000 1234567890123456789LL
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

class IntervalTree {
	struct node {
		int time[2];
		int max_time[2];
	};

	int b;
	vector<node> T;

public:
	IntervalTree(int N) {
		b = 1;
		while(b < N) b *= 2;
		T.resize(2*b+10, {{-1, 0}, {-1, 0}});
	}

	void put(int I_l, int I_r, int val, int k, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return;
		T[cur].max_time[k] = val;
		if(I_l == l && I_r == r) {
			T[cur].time[k] = val;
			return;
		}
		put(I_l, I_r, val, k, 2*cur, l, (l+r)/2);
		put(I_l, I_r, val, k, 2*cur+1, (l+r)/2, r);
	}

	void get(int I_l, int I_r, int k, int & t, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return;
		t = max(t, T[cur].time[k]);
		if(I_l == l && I_r == r) {
			t = max(t, T[cur].max_time[k]);
			return;
		}
		get(I_l, I_r, k, t, 2*cur, l, (l+r)/2);
		get(I_l, I_r, k, t, 2*cur+1, (l+r)/2, r);
	}
};

void DFS(int R, int par, auto & G, auto & I) {
	I[R].ss = I[R].ff+1;
	for(auto v : G[R]) if(v != par) {
		I[v].ff = I[R].ss;
		DFS(v, R, G, I);
		I[R].ss = I[v].ss;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector< pair<int, int> > I(N, {0, 0});
	DFS(0, 0, G, I);
	IntervalTree T(N);
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		int c, v;
		cin >> c >> v;
		v--;
		if(c <= 2) {
			if(c == 1) T.put(I[v].ff, I[v].ss, q+1, 0);
			else T.put(I[v].ff, I[v].ff+1, q+1, 1);
		}
		else {
			int t[2] = {-1, -1};
			T.get(I[v].ff, I[v].ff+1, 0, t[0]);
			T.get(I[v].ff, I[v].ss, 1, t[1]);
			cout << (t[0] > t[1]) << "\n";
		}
	}
	return 0;
}

// look at my code
// my code is amazing