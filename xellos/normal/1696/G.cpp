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
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

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

constexpr int K = 200;

struct group {
	cat st_mi, st_mx, fin, s;
	cat fin_cost[2];

	group(int gr, auto & A) : st_mi{-OVER9000}, st_mx{OVER9000}, fin{0}, s{0} {
		fin_cost[0] = fin_cost[1] = 0;
		for(int i = gr*K; i < gr*K+K; i++) {
			cat a = A[i];
			if(i%2 != 0) a *= -1;
			if(st_mi != st_mx) {
				s += a;
				if(i%2 == 0) {
					if(-s < st_mi) continue;
					if(-s >= st_mx) {
						// st_mx+s
						a = s+st_mx;
						fin = 0;
						st_mi = st_mx;
					}
					else st_mi = -s;
				}
				else {
					if(-s > st_mx) continue;
					if(-s <= st_mi) {
						a = s+st_mi;
						fin = 0;
						st_mx = st_mi;
					}
					else st_mx = -s;
				}
			}
			if(st_mi == st_mx) {
				fin += a;
				if((i%2) == (fin >= 0)) {
					fin_cost[i%2] += abs(fin);
					fin = 0;
				}
			}
		}
	}

	void run(cat & v, cat * ans) {
		if(v > st_mi && v < st_mx) {
			v += s;
			return;
		}
		if(v <= st_mi) {
			ans[0] += st_mi-v;
			v = st_mi;
		}
		if(v >= st_mx) {
			ans[1] += v-st_mx;
			v = st_mx;
		}
		if(st_mi != st_mx) v += s;
		else v = fin;
		ans[0] += fin_cost[0];
		ans[1] += fin_cost[1];
	}
};

void run_single(int l, int r, int I_l, int I_r, auto & A, cat & v, cat * ans) {
	for(int i = I_l; i < I_r; i++) {
		cat a = (i == r) ? cat(0) : A[i];
		if(i%2 != 0) a *= -1;
		v += a;
		if((i%2) == (v >= 0)) {
			ans[i%2] += abs(v);
			v = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cat X, Y;
	cin >> N >> Q >> X >> Y;
	if(X < Y) swap(X, Y);
	vector<cat> A(N);
	vector<cat> B[2];
	B[0].resize(N);
	B[1].resize(N);
	fin<cat> F(N, 0LL);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		B[0][i] = (i%2?Y:X) * A[i];
		B[1][i] = (i%2?X:Y) * A[i];
		F.put(i, A[i]);
	}
	vector<group> gr[2];
	for(int k = 0; k < 2; k++)
		for(int i = 0; i <= N-K; i += K)
			gr[k].push_back(group(i/K, B[k]));
	for(int q = 0; q < Q; q++) {
		int tp;
		cin >> tp;
		if(tp == 1) {
			int k;
			cat v;
			cin >> k >> v;
			k--;
			F.put(k, v-A[k]);
			A[k] = v;
			B[0][k] = (k%2?Y:X) * A[k];
			B[1][k] = (k%2?X:Y) * A[k];
			int gr_id = k/K;
			if(gr_id*K <= N-K) {
				gr[0][gr_id] = group(gr_id, B[0]);
				gr[1][gr_id] = group(gr_id, B[1]);
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			l--;
			cat ans = 0, s = F.get(r-1)-F.get(l-1);
			for(int k = 0; k < 2; k++) {
				cat v = 0;
				cat cur[2] = {0, 0};
				int gr_l = l/K, gr_r = r/K;
				if(gr_l == gr_r) {
					run_single(l, r, l, r+1, B[k], v, cur);
				}
				else {
					run_single(l, r, l, (gr_l+1)*K, B[k], v, cur);
					for(int i = gr_l+1; i < gr_r; i++)
						gr[k][i].run(v, cur);
					run_single(l, r, gr_r*K, r+1, B[k], v, cur);
				}
				ans += cur[k];
			}
			cout << (ans+s*X)/dbl(X*(X+Y)) << "\n";
		}
	}
}

// look at my code
// my code is amazing