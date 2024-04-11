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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N), Gi(N);
	vector<int> outdeg(N, 0);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		Gi[--v].push_back(--u);
		G[u].push_back(v);
		outdeg[u]++;
	}
	vector<int> SG(N, 0);
	queue<int> q;
	for(int i = 0; i < N; i++) if(outdeg[i] == 0) q.push(i);
	while(!q.empty()) {
		int cur = q.front();
		static vector<char> used(N+10, 0);
		for(auto v : G[cur]) used[SG[v]] = 1;
		while(used[SG[cur]]) SG[cur]++;
		for(auto v : G[cur]) used[SG[v]] = 0;
		for(auto v : Gi[cur]) {
			outdeg[v]--;
			if(outdeg[v] == 0) q.push(v);
		}
		q.pop();
	}
	int MX = 512;
	cat mod = 998244353;
	cat inv = pw(N+1, mod-2, mod);
	vector<cat> C(MX, 0);
	C[0] = inv;
	vector< vector<cat> > A(MX, vector<cat>(MX, 0));
	for(int i = 0; i < MX; i++) {
		A[i][i] = 1;
		for(int j = 0; j < N; j++) A[i][i^SG[j]] -= inv;
		for(int j = 0; j < MX; j++) A[i][j] %= mod;
	}
	// A * prob = C
	int r = 0;
	for(int col = 0; col < MX; col++) {
		int sw = MX;
		for(int i = r; i < MX; i++) if(A[i][col]) {
			sw = i;
			break;
		}
		if(sw == MX) continue;
		swap(A[r], A[sw]);
		swap(C[r], C[sw]);
		for(int i = 0; i < MX; i++) if(i != r && A[i][col]) {
			cat mul = A[i][col] * pw(A[r][col], mod-2, mod) % mod;
			for(int j = 0; j < MX; j++) A[i][j] = (A[i][j] - A[r][j] * mul) % mod;
			C[i] = (C[i] - C[r] * mul) % mod;
		}
		r++;
	}
	vector<cat> P(MX, 0);
	for(int i = MX-1; i >= 0; i--) {
		int st = 0;
		while(st < MX && A[i][st] == 0) st++;
		if(st == MX) continue;
		P[st] = C[i];
		for(int j = st+1; j < MX; j++) P[st] = (P[st] - A[i][j] * P[j]) % mod;
		P[st] = P[st] * pw(A[i][st], mod-2, mod) % mod;
	}
	cat ans = 0;
	for(int i = 1; i < MX; i++) ans += P[i];
	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing