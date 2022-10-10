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
#include <cstring>
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

struct Component {
	int l, r;
};

constexpr int MX = 500000;
int mi[MX+1];
int mx[MX+1];

inline __attribute__((always_inline))
int find_last_gt_comp(int id, int val, auto & comp, int C, auto in_comp) {
	int l = -1, r = C;
	while(r > l+1) {
		int c = (l+r)/2;
		if(mx[comp[c].l] > val) l = c;
		else r = c;
	}
	int ret = l;
	if(ret >= 0 && comp[ret].l < id) ret = -1;
	if(in_comp != -1) ret = max(ret, in_comp);
	return ret;
}

inline __attribute__((always_inline))
int find_first_lt_comp(int id, int val, auto & comp, int C, auto in_comp) {
	int l = -1, r = C;
	while(r > l+1) {
		int c = (l+r)/2;
		if(mi[comp[c].r+1] < val) r = c;
		else l = c;
	}
	int ret = r;
	if(ret < C && comp[ret].r > id) ret = C;
	if(in_comp != -1) ret = min(ret, in_comp);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	constexpr int B = 300;
	char fix[MX];
	memset(fix, 1, N);
	for(int q = 0; q < Q; q += B) {
		vector< pair<int, int> > upd(min(Q, q+B)-q);
		vector<int> ids;
		for(int i = q; i < min(Q, q+B); i++) {
			cin >> upd[i-q].ff >> upd[i-q].ss;
			fix[--upd[i-q].ff] = 0;
			ids.push_back(upd[i-q].ff);
		}
		sort(begin(ids), end(ids));
		auto it = unique(begin(ids), end(ids));
		ids.resize(it-begin(ids));
		int K = ids.size();
		mi[0] = OVER9000;
		for(int i = 0; i < N; i++) {
			if(A[i] > mi[i] || !fix[i]) mi[i+1] = mi[i];
			else mi[i+1] = A[i];
		}
		mx[N] = 0;
		for(int i = N-1; i >= 0; i--) {
			if(A[i] < mx[i+1] || !fix[i]) mx[i] = mx[i+1];
			else mx[i] = A[i];
		}
		static Component comp[MX];
		int C = 0;
		for(int i = 0, l = 0; i < N; i++) if(mx[i+1] <= mi[i+1] && fix[i]) {
			while(l < N && !fix[l]) l++;
			comp[C++] = {l, i};
			l = i+1;
		}
		vector<int> in_comp(K, -1), prev_comp(K, -1), next_comp(K, C);
		for(int i = 0; i < K; i++) {
			int prev_l = -1, prev_r = C;
			while(prev_r-prev_l > 1) {
				int prev_c = (prev_l+prev_r)/2;
				if(comp[prev_c].l < ids[i]) prev_l = prev_c;
				else prev_r = prev_c;
			}
			prev_comp[i] = prev_l;
			if(prev_l >= 0 && comp[prev_l].r > ids[i])
				in_comp[i] = next_comp[i] = prev_comp[i];
			else next_comp[i] = prev_comp[i]+1;
		}
		vector<int> A_comp(K);
		for(int i = 0; i < K; i++) A_comp[i] = A[ids[i]];
		vector<int> last_gt(K), first_lt(K);
		for(int i = 0; i < K; i++) {
			last_gt[i] = find_last_gt_comp(ids[i], A_comp[i], comp, C, in_comp[i]);
			first_lt[i] = find_first_lt_comp(ids[i], A_comp[i], comp, C, in_comp[i]);
		}
		static uint64_t G[B][B/64+1];
		for(int i = 0; i < K; i++) memset(G[i], 0, (B/64+1)*8);
		for(int i = 0; i < K; i++) for(int j = i+1; j < K; j++) {
			uint64_t g = (A_comp[i] < A_comp[j]);
			if(!g) {
				int m = min(last_gt[i], last_gt[j]);
				if(m >= 0 && comp[m].r > ids[j]) g = 1;
			}
			if(!g) {
				int m = max(first_lt[i], first_lt[j]);
				if(m < C && comp[m].l < ids[i]) g = 1;
			}
			G[i][j/64] |= g<<(j&63);
		}
		vector<int> last_1(K);
		for(int i = 0; i < K; i++) {
			last_1[i] = (K-1)/64;
			while(last_1[i] >= 0 && !G[i][last_1[i]]) last_1[i]--;
			if(last_1[i] == -1) continue;
			int d = 0;
			uint64_t a = G[i][last_1[i]];
			while(a>>1) a >>= 1, d++;
			last_1[i] = 64 * last_1[i] + d;
		}
		for(auto [pos, val] : upd) {
			A[pos] = val;
			int x = 0;
			while(ids[x] != pos) x++;
			A_comp[x] = val;
			last_gt[x] = find_last_gt_comp(pos, A_comp[x], comp, C, in_comp[x]);
			first_lt[x] = find_first_lt_comp(pos, A_comp[x], comp, C, in_comp[x]);
			for(int i = x, j = x+1; j < K; j++) {
				uint64_t g = (A_comp[i] < A_comp[j]);
				if(!g) {
					int m = min(last_gt[i], last_gt[j]);
					if(m >= 0 && comp[m].r > ids[j]) g = 1;
				}
				if(!g) {
					int m = max(first_lt[i], first_lt[j]);
					if(m < C && comp[m].l < ids[i]) g = 1;
				}
				G[i][j/64] ^= ((G[i][j/64]>>(j&63))^g)<<(j&63);
			}
			for(int i = x; i <= x; i++) {
				last_1[i] = (K-1)/64;
				while(last_1[i] >= 0 && !G[i][last_1[i]]) last_1[i]--;
				if(last_1[i] == -1) continue;
				int d = 0;
				uint64_t a = G[i][last_1[i]];
				while(a>>1) a >>= 1, d++;
				last_1[i] = 64 * last_1[i] + d;
			}
			for(int j = x, i = 0; i < x; i++) {
				uint64_t g = (A_comp[i] < A_comp[j]);
				if(!g) {
					int m = min(last_gt[i], last_gt[j]);
					if(m >= 0 && comp[m].r > ids[j]) g = 1;
				}
				if(!g) {
					int m = max(first_lt[i], first_lt[j]);
					if(m < C && comp[m].l < ids[i]) g = 1;
				}
				G[i][j/64] ^= (((G[i][j/64]>>(j&63))&1)^g)<<(j&63);
			}
			for(int j = 0; j < x; j++) {
				int g = G[j][x/64]>>(x&63);
				if(last_1[j] == x && !g) {
					last_1[j] = (K-1)/64;
					while(last_1[j] >= 0 && !G[j][last_1[j]]) last_1[j]--;
					if(last_1[j] == -1) continue;
					int d = 0;
					uint64_t a = G[j][last_1[j]];
					while(a>>1) a >>= 1, d++;
					last_1[j] = 64 * last_1[j] + d;
				}
				if(g) last_1[j] = max(last_1[j], x);
			}
			int ans = C;
			for(int i = 0, l = 0, r = 0; i < K; i++) {
				r = max(r, last_1[i]);
				if(i == r) {
					int l_comp = next_comp[l], r_comp = prev_comp[r];
					for(int j = l; j <= r; j++) l_comp = min(l_comp, first_lt[j]);
					for(int j = l; j <= r; j++) r_comp = max(r_comp, last_gt[j]);
					if(l_comp == C) ans++;
					else ans -= r_comp-l_comp;
					l = r = i+1;
				}
			}
			cout << ans << "\n";
		}
		for(auto id : ids) fix[id] = 1;
	}
	return 0;
}

// look at my code
// my code is amazing