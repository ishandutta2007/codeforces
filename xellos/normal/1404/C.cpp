// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

struct query {
	int x, y, id;

	bool operator<(const query & q) const {
		return x < q.x;
	}
};

struct fin {
	vector<int> T;

	fin(int N) { T.resize(N+10, 0); }
	int lastone(int x) { return x & (x ^ (x-1)); }

	void put(int pos) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i]++;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

struct itree {
	int b;
	vector<int> mi, mi_pos, sub;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mi.resize(2*b, OVER9000);
		mi_pos.resize(2*b);
		for(int i = 0; i < b; i++) mi_pos[b+i] = i;
		sub.resize(2*b, 0);
	}

	void push(int cur) {
		mi[cur] -= sub[cur];
		if(sub[cur] && cur < b) {
			sub[2*cur] += sub[cur];
			sub[2*cur+1] += sub[cur];
		}
		sub[cur] = 0;
	}

	void upd(int cur) {
		mi[cur] = min(mi[2*cur], mi[2*cur+1]);
		if(mi[2*cur+1] == mi[cur]) mi_pos[cur] = mi_pos[2*cur+1];
		else mi_pos[cur] = mi_pos[2*cur];
	}

	void set(int pos, int val, int cur = 1, int l = 0, int r = 0) {
		push(cur);
		if(cur == 1) r = b;
		if(l+1 == r) {
			mi[cur] = val;
			sub[cur] = 0;
			return;
		}
		if(pos < (l+r)/2) {
			set(pos, val, 2*cur, l, (l+r)/2);
			push(2*cur+1);
		}
		else {
			set(pos, val, 2*cur+1, (l+r)/2, r);
			push(2*cur);
		}
		upd(cur);
	}

	void dec(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		push(cur);
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return;
		if(I_l == l && I_r == r) {
			sub[cur]++;
			push(cur);
			return;
		}
		dec(I_l, I_r, 2*cur, l, (l+r)/2);
		dec(I_l, I_r, 2*cur+1, (l+r)/2, r);
		upd(cur);
	}

	pair<int, int> get_mi() {
		return {mi[1], mi_pos[1]};
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	vector<query> qu(Q);
	for(int i = 0; i < Q; i++) {
		cin >> qu[i].x >> qu[i].y;
		qu[i].id = i;
	}
	sort(begin(qu), end(qu));
	itree I(N);
	fin F_rm(N);
	vector<int> ans(Q, 0);
	for(int st = N-1, a = Q-1; st >= 0; st--) {
		if(st-A[st] >= 0) I.set(st, st-A[st]);
		while(true) {
			pair<int, int> mi = I.get_mi();
			if(mi.ff > 0) break;
			I.dec(mi.ss, N);
			F_rm.put(mi.ss);
			I.set(mi.ss, OVER9000);
		}
		while(a >= 0 && qu[a].x == st) {
			ans[qu[a].id] = F_rm.get(N-qu[a].y-1) - F_rm.get(st-1);
			a--;
		}
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing