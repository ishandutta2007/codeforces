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

int pos[20][1<<20];

struct node {
	int h, id, b;

	bool operator<(const node & U) const {
		const node & T = *this;
		int T_sw = T.b>>(h-1);
		int T_pos_l = pos[h-1][(T.id<<h)^T.b];
		int U_sw = U.b>>(h-1);
		int U_pos_l = pos[h-1][(U.id<<h)^U.b];
		if(T_pos_l < U_pos_l) return true;
		if(T_pos_l > U_pos_l) return false;
		int T_pos_r = pos[h-1][(T.id<<h)^T.b^(1<<(h-1))];
		int U_pos_r = pos[h-1][(U.id<<h)^U.b^(1<<(h-1))];
		return (T_pos_r < U_pos_r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int D;
	cin >> D;
	string S;
	cin >> S;
	vector<node> seq[20];
	seq[0].resize(1<<D);
	for(int i = 0; i < (1<<D); i++) seq[0][i] = {.h = 0, .id = i, .b = 0};
	for(int k = 0, m = 0; k < 26; k++) {
		int cnt = 0;
		for(int i = 0; i < (1<<D); i++) if(S[i] == 'a'+k) {
			pos[0][i] = m;
			cnt++;
		}
		m += cnt;
	}
	for(int h = 1; h <= D; h++) {
		seq[h].resize(1<<D);
		for(int i = 0; i < (1<<D); i++) seq[h][i] = {.h = h, .id = i>>h, .b = i&((1<<h)-1)};
		sort(begin(seq[h]), end(seq[h]));
		int m = 0;
		for(int i = 0; i < (1<<D); i++) {
			if(i == 0 || seq[h][i-1] < seq[h][i]) m = i;
			pos[h][(seq[h][i].id<<h)+seq[h][i].b] = m;
		}
	}
	string ans;
	for(int i = 0; i < (1<<D); i++) ans += S[i^seq[D][0].b];
	cout << ans << "\n";
}

// look at my code
// my code is amazing