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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	constexpr int MOD = 998244353;
	int R,C;
	cin >> R >> C;
	vector<string> S(R);
	for(int i = 0; i < R; i++) cin >> S[i];
	if(R%2 == 0 && C%2 == 0) {
		int ans = 1;
		for(int i = 0; i < R*C; i++) if(S[i/C][i%C] == '?') {
			ans *= 2;
			if(ans >= MOD) ans -= MOD;
		}
		cout << ans << "\n";
		return 0;
	}
	if(C%2 == 0) {
		vector<string> St(C);
		for(int i = 0; i < R*C; i++) St[i%C] += S[i/C][i%C];
		S = St;
		swap(R,C);
	}
	if(R%2 == 0) {
		int fix[2] = {0, 0};
		int ans = 1;
		for(int i = 0; i < R; i++) {
			int n[2] = {0, 0};
			for(int j = 0; j < C; j++) {
				if(S[i][j] == '1') n[1]++;
				else if(S[i][j] == '?') n[0]++;
			}
			if(n[0] == 0) fix[n[1]&1]++;
			else for(int j = 0; j < n[0]-1; j++) {
				ans *= 2;
				if(ans >= MOD) ans -= MOD;
			}
		}
		if(fix[0] != 0 && fix[1] != 0) ans = 0;
		if(fix[0] == 0 && fix[1] == 0) {
			ans *= 2;
			if(ans >= MOD) ans -= MOD;
		}
		cout << ans << "\n";
		return 0;
	}
	// R, C odd
	vector< vector<int> > G(R+C);
	vector<int> in_comp(R+C);
	for(int i = 0; i < R+C; i++) in_comp[i] = i;
	vector<char> val(R+C, 0);
	int pr = 1;
	for(int i = 0; i < R*C; i++) {
		if(S[i/C][i%C] == '0') continue;
		if(S[i/C][i%C] == '1') {
			val[i/C] ^= 1;
			val[R+i%C] ^= 1;
			continue;
		}
		int c1 = in_comp[i/C], c2 = in_comp[R+i%C];
		if(c1 == c2) {
			pr *= 2;
			if(pr >= MOD) pr -= MOD;
			continue;
		}
		G[i/C].push_back(R+i%C);
		G[R+i%C].push_back(i/C);
		for(int j = 0; j < R+C; j++) if(in_comp[j] == c2) in_comp[j] = c1;
	}
	int ans = 0;
	for(int k = 0; k < 2; k++) {
		vector<int> D(R+C, 0);
		auto val_cur = val;
		queue<int> q;
		for(int i = 0; i < R+C; i++) {
			D[i] = G[i].size();
			if(D[i] == 1) q.push(i);
		}
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			if(D[v] != 1) continue;
			for(auto u : G[v]) if(D[u]) {
				val_cur[u] ^= val_cur[v];
				val_cur[v] = 0;
				D[u]--, D[v]--;
				if(D[u] == 1) q.push(u);
			}
		}
		bool ok = true;
		for(int i = 0; i < R+C; i++) if(val_cur[i]) ok = false;
		if(ok) {
			ans += pr;
			if(ans >= MOD) ans -= MOD;
		}
		for(int i = 0; i < R+C; i++) val[i] ^= 1;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing