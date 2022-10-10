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

class itree {
	vector<cat> min_val;
	int b;

	void put(int pos, cat val, int cur, int l, int r) {
		if(l == r-1) {
			min_val[cur] = val;
			return;
		}
		int m = (l+r)/2;
		if(pos < m) put(pos, val, 2*cur, l, m);
		else put(pos, val, 2*cur+1, m, r);
		min_val[cur] = min(min_val[2*cur], min_val[2*cur+1]);
	}

	void get(int l, int r, int cur, int I_l, int I_r, cat & val, int & id) {
		l = max(l, I_l);
		r = min(r, I_r);
		if(l >= r) return;
		if(l == I_l && r == I_r) {
			if(min_val[cur] < val) val = min_val[cur], id = cur;
			return;
		}
		get(l, r, 2*cur, I_l, (I_l+I_r)/2, val, id);
		get(l, r, 2*cur+1, (I_l+I_r)/2, I_r, val, id);
	}

public:
	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		min_val.resize(2*b, OVER9000);
	}

	void put(int pos, cat val) {
		put(pos, val, 1, 0, b);
	}

	pair<cat, int> get_min_id(int l, int r) {
		cat val = OVER9000;
		int node_id = -1;
		get(l, r, 1, 0, b, val, node_id);
		if(val == OVER9000) return {OVER9000, node_id};
		while(node_id < b) {
			node_id *= 2;
			if(min_val[node_id] != val) node_id++;
		}
		return {val, node_id-b};
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector< pair<cat, cat> > fixed(N+1, {0, 0});
	for(int i = 1; i <= N; i++) cin >> fixed[i].ff >> fixed[i].ss;
	vector< pair<cat, int> > by_diag(N+1);
	for(int i = 0; i <= N; i++) by_diag[i] = {fixed[i].ff-fixed[i].ss, i};
	sort(begin(by_diag), end(by_diag));
	itree Ix(N+1), Iy(N+1);
	for(int i = 0; i <= N; i++) Ix.put(i, fixed[by_diag[i].ss].ff);
	for(int i = 0; i <= N; i++) Iy.put(i, fixed[by_diag[i].ss].ss);
	map< cat, map<cat, cat> > D;
	cat cur_x = 0, cur_y = 0;
	while(true) {
		pair<cat, int> p = {cur_x-cur_y, 0};
		auto it = lower_bound(begin(by_diag), end(by_diag), p);
		cat l_x = OVER9000;
		while(true) {
			auto [val, id] = Ix.get_min_id(it-begin(by_diag), N+1);
			if(val < cur_x) Ix.put(id, OVER9000);
			else {
				if(val != OVER9000) l_x = fixed[by_diag[id].ss].ff - cur_x;
				break;
			}
		}
		p = {cur_x-cur_y+1, 0};
		it = lower_bound(begin(by_diag), end(by_diag), p);
		cat l_y = OVER9000;
		while(true) {
			auto [val, id] = Iy.get_min_id(0, it-begin(by_diag));
			if(val < cur_y) Iy.put(id, OVER9000);
			else {
				if(val != OVER9000) l_y = fixed[by_diag[id].ss].ss - cur_y;
				break;
			}
		}
		cat l = min(l_x, l_y);
		if(l) {
			D[cur_x-cur_y][cur_x+cur_y+2*(l-1)] = cur_x+cur_y;
			cur_x += l;
			cur_y += l;
		}
		if(l == OVER9000) break;
		if(l_x == l) cur_x++;
		if(l_y == l) cur_y++;
	}
	set< pair<cat, cat> > fixed_S;
	for(int i = 0; i <= N; i++) fixed_S.insert(fixed[i]);
	for(int i = 0; i < M; i++) {
		cat x, y;
		cin >> x >> y;
		if(fixed_S.count({x, y})) {
			cout << "LOSE\n";
			continue;
		}
		auto it = D.find(x-y);
		if(it == end(D)) {
			cout << "WIN\n";
			continue;
		}
		auto jt = it->ss.lower_bound(x+y);
		if(jt == end(it->ss)) cout << "WIN\n";
		else cout << ((jt->ss <= x+y) ? "LOSE\n" : "WIN\n");
	}
}

// look at my code
// my code is amazing