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
	int b;
	vector<cat> sumv, addv;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		sumv.resize(2*b, 0);
		addv.resize(2*b, 0);
	}

	void upd(int cur, int l, int r) {
		sumv[cur] += addv[cur] * (r-l);
		if(cur < b) {
			addv[2*cur] += addv[cur];
			addv[2*cur+1] += addv[cur];
		}
		addv[cur] = 0;
	}

	void add(int I_l, int I_r, cat val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			addv[cur] += val;
			return;
		}
		if(I_l >= I_r) return;
		sumv[cur] += val * (I_r-I_l);
		int mid = (l+r)/2;
		add(I_l, I_r, val, 2*cur, l, mid);
		add(I_l, I_r, val, 2*cur+1, mid, r);
	}

	cat get(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		upd(cur, l, r);
		if(I_l >= I_r) return 0;
		if(I_l == l && I_r == r) return sumv[cur];
		int mid = (l+r)/2;
		return get(I_l, I_r, 2*cur, l, mid) + get(I_l, I_r, 2*cur+1, mid, r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,Q;
	cin >> N >> Q;
	vector<int> P(N), pos(N);
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		pos[--P[i]] = i;
	}
	vector< vector< pair<int, int> > > I(N);
	for(int i = 1; i <= N; i++) for(int j = i+1; j <= N/i; j++) {
		int l = min(min(pos[i-1], pos[j-1]), pos[i*j-1]);
		int r = max(max(pos[i-1], pos[j-1]), pos[i*j-1]);
		I[pos[i*j-1]].push_back({l, r});
		// pre fixne i*j: intervaly [L,R] kde L <= l, R >= r, max([L,R]) = i*j-1 su dobre
		// ak l0 <= L <= l: zapnem R: r <= R <= r0
	}
	vector< pair<int, int> > Ig(N);
	vector< pair<int, int> > st = {{N, -1}};
	for(int i = 0; i < N; i++) {
		while(!st.empty() && st.back().ff < P[i]) st.pop_back();
		Ig[i].ff = st.back().ss+1;
		st.push_back({P[i], i});
	}
	st = {{N, N}};
	for(int i = N-1; i >= 0; i--) {
		while(!st.empty() && st.back().ff < P[i]) st.pop_back();
		Ig[i].ss = st.back().ss-1;
		st.push_back({P[i], i});
	}
	for(int i = 0; i < N; i++) {
		vector< pair<int, int> > Ic;
		for(auto p : I[i]) if(p.ff >= Ig[i].ff && p.ss <= Ig[i].ss) Ic.push_back(p);
		sort(begin(Ic), end(Ic));
		reverse(begin(Ic), end(Ic));
		I[i].clear();
		int r = N;
		for(auto p : Ic) if(p.ss < r) {
			r = p.ss;
			if(I[i].empty() || I[i].back().ff > p.ff) I[i].push_back(p);
			else I[i].back() = p;
		}
		reverse(begin(I[i]), end(I[i]));
	}
	vector< vector< pair<int,int> > > op(N), cl(N);
	for(int i = 0; i < N; i++) if(!I[i].empty()) {
		op[I[i][0].ff].push_back({I[i][0].ss, Ig[i].ss});
		if(Ig[i].ff) cl[Ig[i].ff-1].push_back({I[i][0].ss, Ig[i].ss});
		for(int j = 1; j < (int)I[i].size(); j++) {
			op[I[i][j].ff].push_back({I[i][j].ss, Ig[i].ss});
			cl[I[i][j-1].ff].push_back({I[i][j].ss, Ig[i].ss});
		}
	}
	vector< vector< pair<int, int> > > qs(N);
	for(int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		qs[l-1].push_back({r-1, q});
	}
	vector<cat> ans(Q, 0);

	itree Ia(N), Ic(N);
	for(int i = N-1; i >= 0; i--) {
		for(auto p : op[i]) {
			Ic.add(p.ff, p.ss+1, i+1);
			Ia.add(p.ff, p.ss+1, 1);
		}
		for(auto p : cl[i]) {
			Ic.add(p.ff, p.ss+1, -(i+1));
			Ia.add(p.ff, p.ss+1, -1);
		}
		for(auto p : qs[i])
			ans[p.ss] = Ic.get(0, p.ff+1) - i * Ia.get(0, p.ff+1);
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing