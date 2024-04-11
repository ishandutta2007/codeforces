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

class IntervalTree {
	struct node {
		int l, r;
		int son[2];
		priority_queue<int> q, q_active;
		int max_active, min_real;
	};
	vector<node> T;
	vector<bool> deactivated, deleted;

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
	
	void clean(node & n) {
		while(!n.q_active.empty() && deactivated[n.q_active.top()]) n.q_active.pop();
		while(!n.q.empty() && deleted[n.q.top()]) n.q.pop();

		n.min_real = -1;
		if(n.son[0] != -1 && n.son[1] != -1) n.min_real = min(T[n.son[0]].min_real, T[n.son[1]].min_real);
		if(!n.q.empty() && n.q.top() > n.min_real) n.min_real = n.q.top();

		n.max_active = n.q_active.empty() ? -1 : n.q_active.top();
		if(n.son[0] != -1) n.max_active = max(n.max_active, T[n.son[0]].max_active);
		if(n.son[1] != -1) n.max_active = max(n.max_active, T[n.son[1]].max_active);
		if(n.min_real > n.max_active) n.max_active = -1;
	}

public:
	IntervalTree(int N, int max_val) :
			T{{0, N, {-1, -1}, priority_queue<int>(), priority_queue<int>(), -1, -1}},
			deactivated(max_val, 0),
			deleted(max_val, 0) {
		construct(0);
	}

	void add(int l, int r, int val, int node_num = 0) {
		node & n = T[node_num];
		if(n.l >= r || l >= n.r) return;
		if(n.l == l && n.r == r) {
			n.q.push(val);
			n.q_active.push(val);
			clean(n);
			return;
		}
		add(l, min(r, (n.l+n.r)/2), val, n.son[0]);
		add(max(l, (n.l+n.r)/2), r, val, n.son[1]);
		clean(n);
	}

	void remove(int l, int r, int val, int node_num = 0) {
		node & n = T[node_num];
		if(n.l >= r || l >= n.r) return;
		if(n.l == l && n.r == r) {
			deleted[val] = true;
			deactivated[val] = true;
			clean(n);
			return;
		}
		remove(l, min(r, (n.l+n.r)/2), val, n.son[0]);
		remove(max(l, (n.l+n.r)/2), r, val, n.son[1]);
		clean(n);
	}

	void make_inactive(int l, int r, int val, int node_num = 0) {
		node & n = T[node_num];
		if(n.l >= r || l >= n.r) return;
		if(n.l == l && n.r == r) {
			deactivated[val] = true;
			clean(n);
			return;
		}
		make_inactive(l, min(r, (n.l+n.r)/2), val, n.son[0]);
		make_inactive(max(l, (n.l+n.r)/2), r, val, n.son[1]);
		clean(n);
	}

	int get_top() {
		return T[0].max_active;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> x1(N), y1(N), x2(N), y2(N);
	map<int, int> Mx, My;
	srand(0);
	for(int i = 0; i < N; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		Mx[x1[i]] = Mx[x2[i]] = My[y1[i]] = My[y2[i]] = 0;
	}
	int mx = 0, my = 0;
	ALL_THE(Mx, it) it->ss = mx++;
	ALL_THE(My, it) it->ss = my++;
	vector< vector<int> > starts(mx), ends(mx);
	for(int i = 0; i < N; i++) {
		x1[i] = Mx[x1[i]];
		x2[i] = Mx[x2[i]];
		y1[i] = My[y1[i]];
		y2[i] = My[y2[i]];
		starts[x1[i]].push_back(i);
		ends[x2[i]].push_back(i);
	}
	IntervalTree I(my, N);
	vector<int> ans(N, 0);
	for(int i = 0; i < mx; i++) {
		ALL_THE(starts[i], it) I.add(y1[*it], y2[*it], *it);
		ALL_THE(ends[i], it) I.remove(y1[*it], y2[*it], *it);
		int max_active = I.get_top();
		while(max_active != -1) {
			ans[max_active] = 1;
			I.make_inactive(y1[max_active], y2[max_active], max_active);
			max_active = I.get_top();
		}
	}
	int ans_sum = 1;
	for(int i = 0; i < N; i++) ans_sum += ans[i];
	cout << ans_sum << "\n";
	return 0;}

// look at my code
// my code is amazing