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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

struct itree {
	struct node {
		int n_val;
		cat sum, ssum_l, ssum_r;
	};

	vector<node> T;
	int b;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		T.resize(2*b, {0, 0, 0, 0});
	}

	void upd(int cur) {
		T[cur].n_val = T[2*cur].n_val + T[2*cur+1].n_val;
		T[cur].sum = T[2*cur].sum + T[2*cur+1].sum;
		T[cur].ssum_l = T[2*cur].ssum_l + T[2*cur+1].ssum_l + T[2*cur].sum * T[2*cur+1].n_val;
		T[cur].ssum_r = T[2*cur].ssum_r + T[2*cur+1].ssum_r + T[2*cur+1].sum * T[2*cur].n_val;
	}

	void put(int pos, cat add, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l == pos && r == pos+1) {
			T[cur].sum += add;
			T[cur].n_val = (T[cur].sum != 0);
			T[cur].ssum_l = T[cur].ssum_r = T[cur].sum;
			return;
		}
		int mid = (l+r)/2;
		if(pos < mid) put(pos, add, 2*cur, l, mid);
		else put(pos, add, 2*cur+1, mid, r);
		upd(cur);
	}

	int find_pos(int n, int cur, int l, int r) {
		if(T[cur].n_val == n) return r;
		if(T[2*cur].n_val < n) return find_pos(n-T[2*cur].n_val, 2*cur+1, (l+r)/2, r);
		else return find_pos(n, 2*cur, l, (l+r)/2);
	}

	node get(int I_l, int I_r, int cur, int l, int r) {
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return {0, 0, 0, 0};
		if(I_l == l && I_r == r) return T[cur];
		node n_l = get(I_l, I_r, 2*cur, l, (l+r)/2);
		node n_r = get(I_l, I_r, 2*cur+1, (l+r)/2, r);
		return {
			.n_val = n_l.n_val + n_r.n_val,
			.sum = n_l.sum + n_r.sum,
			.ssum_l = n_l.ssum_l + n_r.ssum_l + n_l.sum * n_r.n_val,
			.ssum_r = n_l.ssum_r + n_r.ssum_r + n_r.sum * n_l.n_val,
		};
	}

	cat ssum_l(int n) {
		int pos = find_pos(n, 1, 0, b);
		return get(0, pos, 1, 0, b).ssum_l;
	}

	cat ssum_r(int n) {
		int pos = find_pos(T[1].n_val-n, 1, 0, b);
		return get(pos, b, 1, 0, b).ssum_r;
	}

	cat get_sum(int n, int cur, int l, int r) {
		if(T[cur].n_val == n) return T[cur].sum;
		if(T[2*cur].n_val >= n) return get_sum(n, 2*cur, l, (l+r)/2);
		return T[2*cur].sum + get_sum(n-T[2*cur].n_val, 2*cur+1, (l+r)/2, r);
	}

	cat sum(int n) {
		return get_sum(n, 1, 0, b);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	set<cat> S;
	map<cat, int> M;
	cat sum = 0;
	for(int i = 0; i < N; i++) {
		cat a;
		cin >> a;
		M[a] = 0;
		S.insert(a);
		sum += a;
	}
	if(N <= 1) cout << "0\n";
	else {
		auto l = begin(S);
		auto r = rbegin(S);
		l++;
		cat d = *begin(S), cnt = 0;
		for(int K = 1; K < N; K++) {
			d += *l;
			l++;
			d -= *r;
			r++;
			cnt += max(0LL, d);
		}
		cout << sum-(*begin(S))-cnt << "\n";
	}
	vector<cat> query(Q);
	for(int i = 0; i < Q; i++) {
		int t;
		cat a;
		cin >> t >> a;
		query[i] = (t == 1) ? a : -a;
		if(t == 1) M[a] = 0;
	}
	int m = 0;
	for(auto & p : M) p.ss = m++;
	itree T(m);
	for(auto x : S) T.put(M[x], x);
	for(int i = 0; i < Q; i++) {
		if(query[i] > 0) {
			S.insert(query[i]);
			N++;
			T.put(M[query[i]], query[i]);
		}
		else {
			S.erase(-query[i]);
			N--;
			T.put(M[-query[i]], query[i]);
		}
		sum += query[i];
		if(N <= 1) {
			cout << "0\n";
			continue;
		}
		cat min_d = T.sum((N+1)/2) - (sum - T.sum(N/2+1));
		if(min_d >= 0) {
			cout << sum - T.ssum_l(N) + T.ssum_r(N-1) << "\n";
			continue;
		}
		cat K_le = 0, K_gt = (N+1)/2-1;
		while(K_gt-K_le > 1) {
			cat K = (K_le + K_gt) / 2;
			cat d = T.sum(K+1) - (sum - T.sum(N-K));
			if(d >= 0) K_le = K;
			else K_gt = K;
		}
		cout << sum - 2 * (T.ssum_l(K_le+1) - T.ssum_r(K_le)) << "\n";
	}
}

// look at my code
// my code is amazing