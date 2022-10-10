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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> P(N), pos(N);
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		P[i]--;
		pos[P[i]] = i;
	}
	vector< pair<int,int> > R[2];
	R[0].resize(N);
	R[1].resize(N);
	R[0][N-1] = {N,-1};
	R[1][N-1] = {N,N};
	for(int i = N-2; i >= 0; i--) {
		// R[0][i]: P[i] v rastucej, P[i+1] > P[i] v rastucej, P[i+1] < P[i] v klesajucej
		// R[1][i]: P[i] v dec, P[i+1] > P[i] v inc, P[i+1] < P[i] v dec
		if(P[i+1] > P[i]) {
			R[0][i] = R[0][i+1];
			if(R[0][i+1].ss < P[i]) R[1][i] = {R[0][i+1].ff, P[i+1]};
			else R[1][i] = {pos[R[0][i+1].ss], P[i+1]};
		}
		else {
			R[1][i] = R[1][i+1];
			if(R[1][i+1].ss > P[i]) R[0][i] = {R[1][i+1].ff, P[i+1]};
			else R[0][i] = {pos[R[1][i+1].ss], P[i+1]};
		}
	}
	vector< pair<int,int> > L[2];
	L[0].resize(N);
	L[1].resize(N);
	L[0][0] = {-1,N};
	L[1][0] = {-1,-1};
	for(int i = 1; i < N; i++) {
		// L[0][i]: P[i] v inc, P[i+1] > P[i] v rastucej, P[i+1] < P[i] v klesajucej
		// L[1][i]: P[i] v dec, P[i+1] > P[i] v inc, P[i+1] < P[i] v dec
		if(P[i-1] < P[i]) {
			L[0][i] = L[0][i-1];
			if(L[0][i-1].ss > P[i]) L[1][i] = {L[0][i-1].ff, P[i-1]};
			else L[1][i] = {pos[L[0][i-1].ss], P[i-1]};
		}
		else {
			L[1][i] = L[1][i-1];
			if(L[1][i-1].ss < P[i]) L[0][i] = {L[1][i-1].ff, P[i-1]};
			else L[0][i] = {pos[L[1][i-1].ss], P[i-1]};
		}
	}
	vector< pair<int,int> > I;
	for(int i = 0; i < N; i++) {
		I.push_back({i, R[0][i].ff});
		I.push_back({i, R[1][i].ff});
		I.push_back({L[0][i].ff+1, i+1});
		I.push_back({L[1][i].ff+1, i+1});
		if(i > 0) {
			if(P[i] > P[i-1] && L[0][i-1].ss > R[0][i].ss) I.push_back({L[0][i-1].ff+1, R[0][i].ff});
			if(P[i] < P[i-1] && L[1][i-1].ss < R[1][i].ss) I.push_back({L[1][i-1].ff+1, R[1][i].ff});
			if(P[i] > L[1][i-1].ss && P[i-1] > R[0][i].ss) I.push_back({L[1][i-1].ff+1, R[0][i].ff});
			if(P[i] < L[0][i-1].ss && P[i-1] < R[1][i].ss) I.push_back({L[0][i-1].ff+1, R[1][i].ff});
		}
	}
	vector<int> IR(N+1, 0);
	for(auto p : I) IR[p.ff] = max(IR[p.ff], p.ss);
	for(int i = 1; i <= N; i++) IR[i] = max(IR[i], IR[i-1]);
	cat ans = 0;
	for(int i = 0; i < N; i++) if(IR[i] > i) ans += IR[i]-i;
	cout << ans << "\n";
}

// look at my code
// my code is amazing