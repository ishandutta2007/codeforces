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

template <typename T>
class maxfin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	maxfin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = max(node_val[i], val);
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = max(ret, node_val[i]);
		return ret;
	}
};

struct itree {
	vector<int> val_mi;
	vector<int> pos_mi;
	vector<int> val_add;
	int b;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		val_mi.resize(2*b, 0);
		pos_mi.resize(2*b, 0);
		for(int i = 0; i < b; i++) pos_mi[b+i] = i;
		for(int i = b-1; i > 0; i--) pos_mi[i] = pos_mi[2*i];
		val_add.resize(2*b, 0);
	}

	void push(int cur, int l, int r) {
		if(val_add[cur] == 0) return;
		val_mi[cur] += val_add[cur];
		if(l+1 < r) {
			val_add[2*cur] += val_add[cur];
			val_add[2*cur+1] += val_add[cur];
		}
		val_add[cur] = 0;
	}

	void add(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			val_add[cur] += val;
			push(cur, l, r);
			return;
		}
		push(cur, l, r);
		if(I_l >= I_r) return;
		int mid = (l+r)/2;
		add(I_l, I_r, val, 2*cur, l, mid);
		add(I_l, I_r, val, 2*cur+1, mid, r);
		val_mi[cur] = min(val_mi[2*cur], val_mi[2*cur+1]);
		if(val_mi[cur] == val_mi[2*cur]) pos_mi[cur] = pos_mi[2*cur];
		else pos_mi[cur] = pos_mi[2*cur+1];
	}

	pair<int,int> get_min(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		push(cur, l, r);
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return {OVER9000, 0};
		if(I_l == l && I_r == r) return {val_mi[cur], pos_mi[cur]};
		int mid = (l+r)/2;
		return min(get_min(I_l, I_r, 2*cur, l, mid), get_min(I_l, I_r, 2*cur+1, mid, r));
	}
};

void upd(int id, int add, int N, auto & pos, cat & sum_lo, cat & sum_hi) {
	if(id < 0 || id+1 > 2*N) return;
	int l = pos[id], r = pos[id+1];
	int dif = (l < r) ? (r-l) : (r+2*N+1-l);
	if(add >= 1) {
		if(id < N) sum_lo += dif;
		else sum_hi += dif;
	}
	else {
		if(id < N) sum_lo -= dif;
		else sum_hi -= dif;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	vector<int> P(2*N+1), pos(2*N+1);
	itree I(2*N+2);
	for(int i = 0; i < 2*N+1; i++) cin >> P[i];
	for(int i = 0; i < 2*N+1; i++) {
		pos[--P[i]] = i;
		if(P[i] < N) I.add(i+1, 2*N+2, -1);
		if(P[i] > N) I.add(i+1, 2*N+2, 1);
	}
	cat sum_lo = 0, sum_hi = 0;
	for(int i = 0; i < 2*N; i++) upd(i, 1, N, pos, sum_lo, sum_hi);
	for(int q = 0; q < Q; q++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		set<int> ids;
		for(int i = P[v]-1; i <= P[v]; i++) ids.insert(i);
		for(int i = P[u]-1; i <= P[u]; i++) ids.insert(i);
		for(auto id : ids) upd(id, -1, N, pos, sum_lo, sum_hi);
		if(P[u] < N) I.add(u+1, 2*N+2, 1);
		if(P[u] > N) I.add(u+1, 2*N+2, -1);
		if(P[v] < N) I.add(v+1, 2*N+2, 1);
		if(P[v] > N) I.add(v+1, 2*N+2, -1);
		pos[P[v]] = u, pos[P[u]] = v;
		swap(P[u], P[v]);
		if(P[u] < N) I.add(u+1, 2*N+2, -1);
		if(P[u] > N) I.add(u+1, 2*N+2, 1);
		if(P[v] < N) I.add(v+1, 2*N+2, -1);
		if(P[v] > N) I.add(v+1, 2*N+2, 1);
		for(auto id : ids) upd(id, 1, N, pos, sum_lo, sum_hi);
		pair<int, int> mi = I.get_min(0, 2*N+2);
		if(mi.ff != I.get_min(pos[N], pos[N]+1).ff) {
			cout << mi.ss%(2*N+1) << "\n";
			continue;
		}
		if(sum_hi > 2*N) cout << pos[N] << "\n";
		else if(sum_lo > 2*N) cout << (pos[N]+1)%(2*N+1) << "\n";
		else cout << "-1\n";
	}
}

// look at my code
// my code is amazing