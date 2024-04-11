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
using cat = unsigned long long;
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

struct range {
	int l,r,id;
	cat val;

	bool operator<(const range & R) const {
		return l < R.l;
	}
};

struct itree {
	int b;
	vector<cat> sum, val_set, fval;

	itree() {}

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		sum.resize(2*b, 0);
		val_set.resize(2*b, 0);
		fval.resize(2*b, 0);
	}

	void upd(int cur, int l, int r) {
		if(val_set[cur] == 0) return;
		sum[cur] = (r-l) * val_set[cur];
		fval[cur] = val_set[cur];
		if(l+1 != r) val_set[2*cur] = val_set[2*cur+1] = val_set[cur];
		val_set[cur] = 0;
	}

	void set(int I_l, int I_r, cat val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			val_set[cur] = val;
			upd(cur, l, r);
			return;
		}
		upd(cur, l, r);
		if(I_l >= I_r) return;
		int m = (l+r)/2;
		set(I_l, I_r, val, 2*cur, l, m);
		set(I_l, I_r, val, 2*cur+1, m, r);
		sum[cur] = sum[2*cur] + sum[2*cur+1];
		fval[cur] = fval[2*cur];
	}

	cat get_sum(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		upd(cur, l, r);
		if(I_l >= I_r) return 0;
		if(I_l == l && I_r == r) return sum[cur];
		int m = (l+r)/2;
		cat ret_l = get_sum(I_l, I_r, 2*cur, l, m);
		cat ret_r = get_sum(I_l, I_r, 2*cur+1, m, r);
		sum[cur] = sum[2*cur] + sum[2*cur+1];
		fval[cur] = fval[2*cur];
		return ret_l+ret_r;
	}

	int get_lt_id(int I_l, int I_r, cat val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		upd(cur, l, r);
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return I_l;
		if(l+1 == r) {
			if(fval[cur] >= val) return r;
			else return l;
		}
		int m = (l+r)/2;
		int ret;
		upd(2*cur+1, m, r);
		if(I_r <= m || fval[2*cur+1] < val)
			ret = get_lt_id(I_l, I_r, val, 2*cur, l, m);
		else {
			ret = get_lt_id(I_l, I_r, val, 2*cur+1, m, r);
			upd(2*cur, l, m);
		}
		sum[cur] = sum[2*cur] + sum[2*cur+1];
		fval[cur] = fval[2*cur];
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,M,Q;
	cin >> N >> M >> Q;
	vector<cat> W(N);
	for(int i = 0; i < N; i++) cin >> W[i];
	vector< vector< pair<int,int> > > G(N);
	for(int i = 0; i < M; i++) {
		int u,v,d;
		cin >> u >> v >> d;
		G[--u].push_back({--v, d});
		G[v].push_back({u, d});
	}
	vector<cat> dist(N, -1);
	dist[0] = 0;
	priority_queue< pair<cat,int>, vector< pair<cat,int> >, greater< pair<cat,int> > > qq;
	qq.push({0, 0});
	while(!qq.empty()) {
		auto [dv, v] = qq.top();
		qq.pop();
		if(dist[v] != dv) continue;
		for(auto [u, d] : G[v]) if(dist[u] == (~0ULL) || dist[u] > dv+d) {
			dist[u] = dv+d;
			qq.push({dist[u], u});
		}
	}
	vector< pair<cat,int> > seq(N);
	for(int i = 0; i < N; i++) seq[i] = {dist[i], i};
	sort(begin(seq), end(seq));
	vector<int> id(N);
	for(int i = 0; i < N; i++) id[seq[i].ss] = i;
	vector<int> nxt(N);
	for(int i = 0, j = 0; i < N; i++) {
		j = max(i,j);
		while(j < N && seq[j].ff == seq[i].ff) j++;
		nxt[i] = j;
	}
	vector<int> bad(N, -1);
	for(int i = 1; i < N; i++) {
		int n_prev = 0;
		for(auto [u, d] : G[seq[i].ss]) if(dist[u] == seq[i].ff-d) n_prev++, bad[i] = id[u];
		if(n_prev > 1) bad[i] = -1;
		if(bad[i] == 0) bad[i] = i;
	}
	vector<cat> Ws(N);
	for(int i = 0; i < N; i++) Ws[id[i]] = W[i];
	W = Ws;
	vector<int> id2(N);
	M = 0;
	for(int i = 0; i < N; i++) if(bad[i] != -1) id2[i] = M++;
	vector<int> nxt2(N, M);
	for(int i = N-1, j = N, k = M; i >= 0; i--) {
		while(j > nxt[i]) {
			j--;
			if(bad[j] != -1) k = id2[j];
		}
		nxt2[i] = k;
	}
	vector<int> bad2(M);
	for(int i = 0; i < N; i++) if(bad[i] != -1) bad2[id2[i]] = bad[i];

	vector< pair<int,cat> > queries(Q);
	for(int i = 0; i < Q; i++) {
		cin >> queries[i].ff >> queries[i].ss;
		queries[i].ff = id[--queries[i].ff];
		W[queries[i].ff] += queries[i].ss;
	}
	vector< vector<int> > bad_ids(N);
	for(int i = 0; i < M; i++) if(bad2[i] != -1 && i >= nxt2[bad2[i]])
		bad_ids[bad2[i]].push_back(i);
	vector<int> bad_last(N, 0);
	vector<itree> bad_min2(N);
	for(int i = 0; i < N; i++) bad_min2[i] = itree(bad_ids[i].size());
	set<range> R;
	R.insert(range{.l = 0, .r = M, .id = 0, .val = W[0]});
	cat ans_base = M*W[0], ans_add = 0;
	for(int i = 1; i < N; i++) if(nxt2[i] != M) {
		auto it = R.lower_bound(range{.l = nxt2[i], .r = 0, .id = 0, .val = 0});
		if(it == end(R) || it->l != nxt2[i]) {
			it--;
			range r = *it;
			if(r.val < W[i]) {
				int I_l = lower_bound(begin(bad_ids[it->id]), end(bad_ids[it->id]), nxt2[i]) - begin(bad_ids[it->id]);
				int I_r = bad_min2[it->id].get_lt_id(I_l, bad_last[it->id], W[i]);
				ans_add += (I_r-I_l) * W[i] - bad_min2[it->id].get_sum(I_l, I_r);
				bad_min2[it->id].set(I_l, I_r, W[i]);
				it++;
				if(it != end(R)) {
					I_r = bad_min2[it->id].get_lt_id(0, bad_last[it->id], W[i]);
					ans_add += I_r * W[i] - bad_min2[it->id].get_sum(0, I_r);
					bad_min2[it->id].set(0, I_r, W[i]);
				}
				continue;
			}
			auto jt = it;
			it++;
			R.erase(jt);
			R.insert(range{.l = r.l, .r = nxt2[i], .id = r.id, .val = r.val});
			R.insert(range{.l = nxt2[i], .r = r.r, .id = r.id, .val = r.val});
			it--;
		}
		range r_nw{.l = nxt2[i], .r = nxt2[i], .id = i, .val = W[i]};
		while(it != end(R) && it->val >= W[i]) {
			if(bad_last[it->id]) {
				int I_l = lower_bound(begin(bad_ids[it->id]), end(bad_ids[it->id]), nxt2[i]) - begin(bad_ids[it->id]);
				ans_add -= bad_min2[it->id].get_sum(I_l, bad_last[it->id]);
				ans_add += (bad_last[it->id]-I_l) * it->val;
				bad_last[it->id] = I_l;
			}
			if(it->id != i) {
				int I_l = lower_bound(begin(bad_ids[i]), end(bad_ids[i]), it->l) - begin(bad_ids[i]);
				int I_r = lower_bound(begin(bad_ids[i]), end(bad_ids[i]), it->r) - begin(bad_ids[i]);
				bad_min2[i].set(I_l, I_r, it->val);
			}
			r_nw.r = it->r;
			auto jt = it;
			it++;
			ans_base -= (jt->r-jt->l) * jt->val;
			R.erase(jt);
		}
		if(r_nw.l != r_nw.r) {
			ans_base += (r_nw.r-r_nw.l) * r_nw.val;
			bad_last[i] = lower_bound(begin(bad_ids[i]), end(bad_ids[i]), r_nw.r) - begin(bad_ids[i]);
			ans_add -= bad_last[i] * r_nw.val;
			ans_add += bad_min2[i].get_sum(0, bad_last[i]);
			R.insert(r_nw);
		}
		if(it != end(R)) {
			int I_r = bad_min2[it->id].get_lt_id(0, bad_last[it->id], W[i]);
			ans_add += I_r * W[i] - bad_min2[it->id].get_sum(0, I_r);
			bad_min2[it->id].set(0, I_r, W[i]);
		}
	}
	vector<cat> ans(Q+1);
	for(int q = Q; q >= 0; q--) {
		ans[q] = ans_base + ans_add;
		if(q > 0) {
			int i = queries[q-1].ff;
			W[i] -= queries[q-1].ss;
			if(nxt2[i] == M) continue;
			auto it = R.lower_bound(range{.l = nxt2[i], .r = 0, .id = 0, .val = 0});
			if(it == end(R) || it->l != nxt2[i]) {
				it--;
				range r = *it;
				if(r.val < W[i]) {
					int I_l = lower_bound(begin(bad_ids[it->id]), end(bad_ids[it->id]), nxt2[i]) - begin(bad_ids[it->id]);
					int I_r = bad_min2[it->id].get_lt_id(I_l, bad_last[it->id], W[i]);
					ans_add += (I_r-I_l) * W[i] - bad_min2[it->id].get_sum(I_l, I_r);
					bad_min2[it->id].set(I_l, I_r, W[i]);
					it++;
					if(it != end(R)) {
						I_r = bad_min2[it->id].get_lt_id(0, bad_last[it->id], W[i]);
						ans_add += I_r * W[i] - bad_min2[it->id].get_sum(0, I_r);
						bad_min2[it->id].set(0, I_r, W[i]);
					}
					continue;
				}
				auto jt = it;
				it++;
				R.erase(jt);
				R.insert(range{.l = r.l, .r = nxt2[i], .id = r.id, .val = r.val});
				R.insert(range{.l = nxt2[i], .r = r.r, .id = r.id, .val = r.val});
				it--;
			}
			range r_nw{.l = nxt2[i], .r = nxt2[i], .id = i, .val = W[i]};
			while(it != end(R) && it->val >= W[i]) {
				if(bad_last[it->id]) {
					int I_l = lower_bound(begin(bad_ids[it->id]), end(bad_ids[it->id]), nxt2[i]) - begin(bad_ids[it->id]);
					ans_add -= bad_min2[it->id].get_sum(I_l, bad_last[it->id]);
					ans_add += (bad_last[it->id]-I_l) * it->val;
					bad_last[it->id] = I_l;
				}
				if(it->id != i) {
					int I_l = lower_bound(begin(bad_ids[i]), end(bad_ids[i]), it->l) - begin(bad_ids[i]);
					int I_r = lower_bound(begin(bad_ids[i]), end(bad_ids[i]), it->r) - begin(bad_ids[i]);
					bad_min2[i].set(I_l, I_r, it->val);
				}
				r_nw.r = it->r;
				auto jt = it;
				it++;
				ans_base -= (jt->r-jt->l) * jt->val;
				R.erase(jt);
			}
			if(r_nw.l != r_nw.r) {
				ans_base += (r_nw.r-r_nw.l) * r_nw.val;
				bad_last[i] = lower_bound(begin(bad_ids[i]), end(bad_ids[i]), r_nw.r) - begin(bad_ids[i]);
				ans_add -= bad_last[i] * r_nw.val;
				ans_add += bad_min2[i].get_sum(0, bad_last[i]);
				R.insert(r_nw);
			}
			if(it != end(R)) {
				int I_r = bad_min2[it->id].get_lt_id(0, bad_last[it->id], W[i]);
				ans_add += I_r * W[i] - bad_min2[it->id].get_sum(0, I_r);
				bad_min2[it->id].set(0, I_r, W[i]);
			}
		}
	}
	for(int i = 0; i <= Q; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing