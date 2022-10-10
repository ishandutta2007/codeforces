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
#define soclose 1e-10
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
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i] += val;
		}
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret += node_val[i];
		}
		return ret;
	}
};

struct PT {
	dbl x,y;

	PT operator+(const PT b) const { return {.x = this->x+b.x, .y = this->y+b.y}; }
	PT operator-(const PT b) const { return {.x = this->x-b.x, .y = this->y-b.y}; }
	dbl operator*(const PT b) const { return this->x*b.x+this->y*b.y; }
	dbl operator^(const PT b) const { return this->x*b.y-this->y*b.x; }
};

struct PT_rel : public PT {
	int pos; // |pos| < L
	dbl dist, atan2;
};

int test_min_dist(vector<int> & A, int K, int L) {
	int N = A.size();
	for(int i = 0; i <= N-K; i++) if(A[i+K-1]-A[i] <= L-1) return i+1;
	return 0;
}

bool test_R(vector<PT_rel> & A, int K, int L, dbl & R) {
	int N = A.size(), n_cand = 0;
	for(int i = 0; i < N; i++) if(A[i].dist < 2*R*(1+soclose)) n_cand++;
	if(n_cand < K-1) return false;
	static vector< pair<dbl,int> > B;
	B.clear();
	static vector<int> cur;
	cur.clear();
	for(int i = 0; i < N; i++) {
		if(A[i].dist > 2*R*(1+soclose)) break;
		dbl c = 1-A[i].dist*A[i].dist/(2*R*R);
		if(c < -1+soclose) continue;
		dbl ang_c = A[i].atan2;
		dbl ang_d = (pi-acos(c))/2;
		PT vec2 = {A[i].x+R, A[i].y};
		if(sqrt(vec2*vec2) < R*(1-soclose)) {
			cur.push_back(A[i].pos);
			if(ang_c > 0) {
				B.push_back({ang_c+ang_d-2*pi, A[i].pos});
				B.push_back({ang_c-ang_d, A[i].pos});
			}
			else {
				B.push_back({ang_c+ang_d, A[i].pos});
				B.push_back({ang_c-ang_d+2*pi, A[i].pos});
			}
		}
		else {
			B.push_back({ang_c+ang_d, A[i].pos});
			B.push_back({ang_c-ang_d, A[i].pos});
		}
	}
	if((int)cur.size()+(int)B.size()/2 < K-1) return false;
	sort(begin(cur), end(cur));
	static vector<int> ans;
	ans.clear();
	if(int l = test_min_dist(cur, K-1, L)) {
		for(int i = l-1; i < l-1+K-1; i++) ans.push_back(cur[i]);
	}
	if(ans.empty()) sort(begin(B), end(B));
	for(int i = 0; i < (int)B.size(); i++) {
		if(!ans.empty()) break;
		int j = 0, sz = cur.size();
		while(j < sz && cur[j] < B[i].ss) {
			j++;
			continue;
		}
		if(j < sz && cur[j] == B[i].ss) cur.erase(begin(cur)+j);
		else cur.insert(begin(cur)+j, B[i].ss);
		if(int l = test_min_dist(cur, K-1, L)) {
			for(j = l-1; j < l-1+K-1; j++) ans.push_back(cur[j]);
		}
	}
	if(ans.empty()) return false;
	PT_rel P[20];
	for(int i = 0; i < K-1; i++) for(int j = 0; j < N; j++) if(A[j].pos == ans[i]) {
		P[i] = A[j];
		break;
	}
	// find circle
	for(int i = 0; i < K-1; i++) {
		dbl min_cos[2] = {-1,-1};
		for(int k = 0; k < K-1; k++) if(k != i) {
			dbl dpr = P[k]*P[i], cpr = P[k]^P[i];
			dbl d = sqrt(P[i].dist*P[i].dist+P[k].dist*P[k].dist-2*dpr);
			min_cos[cpr>0] = max(min_cos[cpr>0], (P[k].dist*P[k].dist-dpr)/(d*P[k].dist));
		}
		if(min_cos[0]+min_cos[1] > 0) continue;
		if(min_cos[0] < 0 && min_cos[1] < 0) {
			R = min(R, P[i].dist/2);
			continue;
		}
		R = min(R, P[i].dist/2/sqrt(1-pow(max(min_cos[0], min_cos[1]), 2)));
	}
	return true;
}

dbl solve(vector<PT_rel> & A, int K, int L, dbl R0) {
	if((int)A.size() < K-1) return R0;
	dbl R_lt = A[K-2].dist/2*(1-soclose), R_gt = R0;
	while(R_gt-R_lt > R_lt*soclose) {
		dbl R = (R_lt + R_gt) / 2;
		if(test_R(A, K, L, R)) R_gt = R;
		else R_lt = R;
	}
	return R_gt;
}

struct itree {
	int b;
	vector<int> mx, add;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mx.resize(2*b, 0);
		add.resize(2*b, 0);
	}

	void upd(int cur) {
		if(add[cur] == 0) return;
		mx[cur] += add[cur];
		if(cur < b) {
			add[2*cur] += add[cur];
			add[2*cur+1] += add[cur];
		}
		add[cur] = 0;
	}

	void put(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			add[cur] += val;
			upd(cur);
			return;
		}
		upd(cur);
		if(I_l >= I_r) return;
		int mid = (l+r)/2;
		put(I_l, I_r, val, 2*cur, l, mid);
		put(I_l, I_r, val, 2*cur+1, mid, r);
		mx[cur] = max(mx[2*cur], mx[2*cur+1]);
	}

	int get() {
		upd(1);
		return mx[1];
	}
};

inline __attribute__((always_inline)) void insert_pt(auto & Ai, auto & Aj, int j, int K, dbl & R, auto & by_dist) {
	dbl d = 1LL*(Ai.ff-Aj.ff)*(Ai.ff-Aj.ff)+1LL*(Ai.ss-Aj.ss)*(Ai.ss-Aj.ss);
	if(d < 4*R*R*(1+soclose)) {
		d = sqrt(d);
		by_dist.push_back({d, j});
		for(int k = (int)by_dist.size()-1; k > 0; k--) {
			if(by_dist[k].ff < by_dist[k-1].ff) swap(by_dist[k], by_dist[k-1]);
			else break;
		}
		if((int)by_dist.size() >= 2*(K-1)) R = min(R, by_dist[2*K-3].ff);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N,L,K;
		cin >> N >> L >> K;
		vector< pair<int,int> > A(N);
		for(int i = 0; i < N; i++) cin >> A[i].ff >> A[i].ss;
		vector< pair< pair<int,int>, int> > As(N);
		for(int i = 0; i < N; i++) As[i] = {A[i], i};
		sort(begin(As), end(As));
		vector<int> sorted_pos(N);
		for(int i = 0; i < N; i++) sorted_pos[As[i].ss] = i;
		dbl R = 1e9;
		vector< vector<PT_rel> > nearest(N);
		itree I(N);
		for(int i = 0; i < N; i++) {
			static vector< pair<dbl,int> > by_dist;
			by_dist.clear();
			if(L > 2000) {
				for(int p = sorted_pos[i]+1; p < N; p++) {
					if(As[p].ff.ff-A[i].ff > 2*R*(1+soclose)) break;
					int j = As[p].ss;
					if(j > i-L && j < i+L) insert_pt(A[i], As[p].ff, j, K, R, by_dist);
				}
				for(int p = sorted_pos[i]-1; p >= 0; p--) {
					if(A[i].ff-As[p].ff.ff > 2*R*(1+soclose)) break;
					int j = As[p].ss;
					if(j > i-L && j < i+L) insert_pt(A[i], As[p].ff, j, K, R, by_dist);
				}
			}
			else {
				for(int j = max(0,i-L+1); j <= min(N-1,i+L-1); j++) if(j != i)
					insert_pt(A[i], A[j], j, K, R, by_dist);
			}
			for(int j = 0; j <= (int)by_dist.size(); j++) {
				if(j == (int)by_dist.size() || by_dist[j].ff > R) {
					j--;
					while(j >= 0) {
						I.put(max(max(0,i-L+1),by_dist[j].ss-L+1), min(i,by_dist[j].ss)+1, -1);
						j--;
					}
					break;
				}
				I.put(max(max(0,i-L+1),by_dist[j].ss-L+1), min(i,by_dist[j].ss)+1, 1);
				if(j < K-1 || I.get() < K-1) continue;
				R = min(R, by_dist[j].ff);
				while(j >= 0) {
					I.put(max(max(0,i-L+1),by_dist[j].ss-L+1), min(i,by_dist[j].ss)+1, -1);
					j--;
				}
				break;
			}
			while(!by_dist.empty() && by_dist.back().ff > 2*R*(1+soclose)) by_dist.pop_back();
			nearest[i].dibs(by_dist.size());
			for(auto [d,id] : by_dist) {
				dbl x = A[id].ff-A[i].ff, y = A[id].ss-A[i].ss;
				nearest[i].push_back({{.x = x, .y = y}, .pos = id-i, .dist = d, .atan2 = atan2(y,x)});
			}
		}
		vector<int> cand;
		for(int i = 0; i < N; i++) cand.push_back(i);
		while(!cand.empty()) {
			int r = rand()%cand.size();
			R = solve(nearest[cand[r]], K, L, R);
			vector<int> cand_nw;
			for(auto i : cand) if(i != cand[r]) if(test_R(nearest[i], K, L, R)) cand_nw.push_back(i);
			cand = cand_nw;
		}
		cout << R << "\n";
	}
}

// look at my code
// my code is amazing