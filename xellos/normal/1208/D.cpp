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

class IntervalTree {
	struct node {
		cat val, add;
	};
	int b;
	vector<node> T;

	void construct(int cur, int l, int r, vector<cat> & A) {
		if(l+1 == r) {
			T[cur].val = A[l];
			return;
		}
		construct(2*cur, l, (l+r)/2, A);
		construct(2*cur+1, (l+r)/2, r, A);
		T[cur].val = min(T[2*cur].val, T[2*cur+1].val);
	}

	void upd(int cur, int l, int r) {
		T[cur].val += T[cur].add;
		if(l+1 == r) {
			T[cur].add = 0;
			return;
		}
		T[2*cur].add += T[cur].add;
		T[2*cur+1].add += T[cur].add;
		T[cur].add = 0;
	}

public:
	IntervalTree(vector<cat> A) {
		int N = A.size();
		b = 1;
		while(b < N) b *= 2;
		T.resize(2*b+10, {0, 0});
		A.resize(b, 1LL*A.size()*(A.size()+1)+10);
		construct(1, 0, b, A);
	}

	void add(int pos, cat add_v, int cur = 1, int l = 0, int r = 0) {
		// [pos..b) += add
		if(cur == 1) r = b;
		upd(cur, l, r);
		if(r <= pos) return;
		if(l >= pos) {
			T[cur].add += add_v;
			upd(cur, l, r);
			return;
		}
		add(pos, add_v, 2*cur, l, (l+r)/2);
		add(pos, add_v, 2*cur+1, (l+r)/2, r);
		T[cur].val = min(T[2*cur].val, T[2*cur+1].val);
	}

	void set(int pos, cat val, int cur = 1, int l = 0, int r = 0) {
		// [pos] = val
		if(cur == 1) r = b;
		upd(cur, l, r);
		if(r <= pos || pos < l) return;
		if(l == pos && r == l+1) {
			T[cur].val = val;
			upd(cur, l, r);
			return;
		}
		set(pos, val, 2*cur, l, (l+r)/2);
		set(pos, val, 2*cur+1, (l+r)/2, r);
		T[cur].val = min(T[2*cur].val, T[2*cur+1].val);
	}

	int get_zero(int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		upd(cur, l, r);
		if(T[cur].val != 0) return b;
		if(l+1 == r) return l;
		int zl = get_zero(2*cur, l, (l+r)/2), zr = b;
		if(zl == b) zr = get_zero(2*cur+1, (l+r)/2, r);
		else upd(2*cur+1, (l+r)/2, r);
		T[cur].val = min(T[2*cur].val, T[2*cur+1].val);
		return min(zl, zr);
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> S(N, 0);
	for(int i = 0; i < N; i++) cin >> S[i];
	vector<int> P(N, 0);
	IntervalTree I(S);
	set<int> Z;
	while(true) {
		int z = I.get_zero();
		if(z >= N) break;
		Z.insert(z);
		I.set(z, 1LL*N*(N+1)+10);
	}
	for(int i = 1; i <= N; i++) {
		int id = *(Z.rbegin());
		Z.erase(--Z.end());
		P[id] = i;
		I.add(id+1, -i);
		while(true) {
			int z = I.get_zero();
			if(z >= N) break;
			Z.insert(z);
			I.set(z, 1LL*N*(N+1)+10);
		}
	}
	for(int i = 0; i < N; i++) cout << P[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing