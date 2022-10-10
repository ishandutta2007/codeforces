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
#define OVER9000 1234567890LL
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

struct quest {
	int x, y, t;

	bool operator<(const quest &q) const {
		return t < q.t;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector<int> XV(N), YV(N);
	for(int i = 0; i < N; i++) cin >> XV[i] >> YV[i];
	vector<quest> Q(M);
	for(int i = 0; i < M; i++) cin >> Q[i].x >> Q[i].y >> Q[i].t;
	sort(begin(Q), end(Q));
	vector<cat> reach(2*M, 0);
	for(int k = 1; k < M; k++)
		for(int j = 0; j < k; j++) if(Q[k].t >= Q[j].t + abs(Q[j].x-Q[k].x)+abs(Q[j].y-Q[k].y))
			reach[2*k+j/56] |= 1LL<<(j%56);
	vector< vector<int> > min_dist_Q(1<<N, vector<int>(M, Q[M-1].t+1));
	for(int i = 0; i < (1<<N); i++) for(int j = 0; j < M; j++)
		for(int k = 0; k < N; k++) if((i>>k)&1) min_dist_Q[i][j] = min(min_dist_Q[i][j], abs(XV[k]-Q[j].x)+abs(YV[k]-Q[j].y));
	vector< vector<int> > min_dist_T(N, vector<int>((M/8+20)<<8, Q[M-1].t+1));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j += 8) for(int k = j; k < min(M, j+8); k++)
		for(int b = 0; b < (1<<8); b++) if((b>>(k-j))&1)
			min_dist_T[i][(j<<(8-3))+b] = min(min_dist_T[i][(j<<(8-3))+b], Q[k].t + abs(XV[i]-Q[k].x)+abs(YV[i]-Q[k].y));
	int ans = 0;
	vector< vector<int> > live(1<<N, vector<int>(M, -1));
	vector<int> min_turn(1<<N, Q[M-1].t+1);
	for(int i = 0; i < N; i++) min_turn[1<<i] = 0;
	while(true) {
		if(ans == 0) for(int i = 0; i < M; i++) live[0][i] = 1;
		bool has_live = (ans == 0);
		// move from quest to tower/quest
		for(int i = 0; i < (1<<N); i++) for(int j = 0; j < M; j++) if(live[i][j] >= ans) {
			min_turn[i] = min(min_turn[i], Q[j].t);
			break;
		}
		for(int i = 0; i < (1<<N); i++) {
			cat live_mask[2] = {0, 0};
			for(int k = 0; k < M; k++) {
				if((live_mask[0] & reach[2*k]) | (live_mask[1] & reach[2*k+1])) {
					live[i][k] = ans+1;
					has_live = true;
				}
				if(live[i][k] >= ans) live_mask[k/56] |= 1LL<<(k%56);
			}
			for(int k = 0; k < N; k++) if(((i>>k)&1) == 0) for(int l = 0; l < 2; l++) {
				cat m = live_mask[l];
				for(int s = 7*l; s < 7*l+7; s++) {
					min_turn[i+(1<<k)] = min(min_turn[i+(1<<k)], min_dist_T[k][(s<<8)+(m&((1<<8)-1))]);
					m >>= 8;
				}
			}
		}
		// move tower->tower
		for(int i = 0; i < (1<<N); i++) for(int k = 0; k < N; k++) if(((i>>k)&1) == 0) {
			int min_dist_TT = min_turn[i+(1<<k)];
			for(int j = 0; j < N; j++) if((i>>j)&1) min_dist_TT = min(min_dist_TT, abs(XV[k]-XV[j])+abs(YV[k]-YV[j]));
			min_turn[i+(1<<k)] = min(min_turn[i+(1<<k)], min_turn[i] + min_dist_TT);
		}
		// move tower->quest
		for(int i = 0; i < (1<<N); i++) for(int k = 0; k < M; k++) if(Q[k].t >= min_turn[i] + min_dist_Q[i][k]) {
			live[i][k] = ans+1;
			has_live = true;
		}
		if(has_live) ans++;
		else break;
		for(int i = 0; i < (1<<N); i++) min_turn[i] = Q[M-1].t+1;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing