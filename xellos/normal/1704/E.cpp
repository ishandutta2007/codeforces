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
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<cat> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector< vector<int> > G(N), Gi(N);
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			Gi[v].push_back(u);
		}
		vector<int> seq, D(N, 0);
		for(int i = 0; i < N; i++) D[i] = G[i].size();
		for(int i = 0; i < N; i++) if(D[i] == 0) seq.push_back(i);
		for(int i = 0; i < N-1; i++) {
			for(auto v : Gi[seq[i]]) {
				D[v]--;
				if(D[v] == 0) seq.push_back(v);
			}
		}
		reverse(begin(seq), end(seq));
		vector<int> id(N);
		for(int i = 0; i < N; i++) id[seq[i]] = i;
		vector<cat> AP(N);
		for(int i = 0; i < N; i++) AP[i] = A[seq[i]];
		vector< pair<int,int> > EP;
		for(int i = 0; i < N; i++) for(auto v : G[seq[i]]) EP.push_back({i, id[v]});
		cat ans = 0, MOD = 998244353;
		while(true) {
			bool stop = true;
			for(int i = 0; i < M; i++) if(AP[EP[i].ff] != 0 && AP[EP[i].ss] == 0) stop = false;
			if(stop) break;
			if(AP[N-1] > 0) AP[N-1]--;
			for(int i = M-1; i >= 0; i--) if(AP[EP[i].ff] > 0) {
				AP[EP[i].ss]++;
				if(i == 0 || EP[i-1].ff != EP[i].ff) AP[EP[i].ff]--;
			}
			ans++;
		}
		for(int i = 0; i < N; i++) if(AP[i]) {
			AP[i] %= MOD;
			if(AP[i] == 0) AP[i] = MOD;
		}
		while(AP[N-1] > 0) {
			int k = -1;
			vector<char> top(N, 1);
			for(int i = 0; i < M; i++) if(AP[EP[i].ff] > 0) top[EP[i].ss] = 0;
			for(int i = 0; i < N; i++) if(top[i] && AP[i] > 0) {
				if(k == -1) k = i;
				else if(AP[i] < AP[k]) k = i;
			}
			cat d = AP[k];
			ans += d;
			AP[N-1] -= d;
			for(int i = M-1; i >= 0; i--) if(AP[EP[i].ff] > 0) {
				AP[EP[i].ss] += d;
				if(i == 0 || EP[i-1].ff != EP[i].ff) AP[EP[i].ff] -= d;
			}
			for(int i = 0; i < N; i++) if(AP[i]) {
				AP[i] %= MOD;
				if(AP[i] == 0) AP[i] = MOD;
			}
		}
		cout << ans%MOD << "\n";
	}
}

// look at my code
// my code is amazing