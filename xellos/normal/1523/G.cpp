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
	int init_val;
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin() {}

	fin(int N, T init_val_) : init_val{init_val_} {
		node_val.resize(N+10, init_val_);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

struct seg {
	int l, r, id;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector<seg> A(M);
	vector< vector<int> > id_by_size(N);
	vector< vector< pair<int,int> > > S[17];
	for(int k = 0; k < 17; k++) S[k].resize((N>>k)+1);
	for(int i = 0; i < M; i++) {
		cin >> A[i].l >> A[i].r;
		A[i].id = i;
		A[i].l--, A[i].r--;
		id_by_size[A[i].r-A[i].l].push_back(i);
		for(int k = 0; k < 17; k++)
			S[k][A[i].l>>k].push_back({A[i].r, i});
	}
	vector<int> pos[17];
	vector< fin<int> > F[17];
	for(int k = 0; k < 17; k++) {
		pos[k].resize(M);
		F[k].resize((N>>k)+1);
		for(int i = 0; i <= (N>>k); i++) {
			sort(begin(S[k][i]), end(S[k][i]));
			F[k][i] = fin(S[k][i].size(), M);
			for(int j = 0; j < (int)S[k][i].size(); j++) pos[k][S[k][i][j].ss] = j;
		}
	}
	vector<int> ans(N, 0);
	for(int x = N-1; x >= 0; x--) {
		for(auto id: id_by_size[x]) {
			int l = A[id].l;
			for(int k = 0; k < 17; k++)
				F[k][l>>k].put(pos[k][id], S[k][l>>k][pos[k][id]].ss);
		}
		static queue< pair<int, int> > space;
		space.push({0, N-1});
		while(!space.empty()) {
			auto [L, R] = space.front();
			space.pop();
			int min_id = M;
			int cur_L = L;
			while(cur_L <= R) {
				int k = 16;
				while(cur_L+(1<<k) > R+1) k--;
				while(cur_L&((1<<k)-1)) k--;
				auto & V = S[k][cur_L>>k];
				auto it = lower_bound(begin(V), end(V), make_pair(R+1, 0));
				min_id = min(min_id, F[k][cur_L>>k].get(it-begin(V)-1));
				cur_L += 1<<k;
			}
			if(min_id == M) continue;
			int l = A[min_id].l, r = A[min_id].r;
			ans[x] += r-l+1;
			if(l-1-L >= x) space.push({L, l-1});
			if(R-r-1 >= x) space.push({r+1, R});
		}
	}
	for(int i = 0; i < N; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing