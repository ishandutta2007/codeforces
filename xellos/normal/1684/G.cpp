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

void DFS(int v, auto & prev, auto & C) {
	for(int i = 0; i < (int)prev.size(); i++) if(prev[i] == -1 && C[v][i]) {
		prev[i] = v;
		if(prev[(int)prev.size()-1] != -1) break;
		DFS(i, prev, C);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cat M;
	cin >> N >> M;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(begin(A), end(A));
	int ng = 0;
	while(ng < N && A[N-1-ng]*3 > M) ng++;
	vector< vector<char> > C(N+2, vector<char>(N+2, 0));
	for(int i = N-ng; i < N; i++) C[0][1+i] = 1;
	for(int i = 0; i < N-ng; i++) C[1+i][N+1] = 1;
	for(int i = N-ng; i < N; i++) for(int j = 0; j < N-ng; j++) {
		if(2*A[i]+A[j] > M) break;
		if(A[i]%A[j] == 0) C[1+i][1+j] = 1;
	}
	int nf = 0;
	while(true) {
		vector<int> prev(N+2, -1);
		prev[0] = 0;
		DFS(0, prev, C);
		if(prev[N+1] == -1) break;
		nf++;
		int cur = N+1;
		while(cur) {
			C[prev[cur]][cur] = 0;
			C[cur][prev[cur]] = 1;
			cur = prev[cur];
		}
	}
	if(nf != ng) {
		cout << "-1\n";
		return 0;
	}
	vector<char> used(N, 0);
	vector< pair<cat,cat> > ans;
	for(int i = N-ng; i < N; i++) {
		for(int j = 0; j < N-ng; j++) if(C[1+j][1+i]) {
			used[i] = used[j] = 1;
			ans.push_back({2*A[i]+A[j], A[i]+A[j]});
			break;
		}
	}
	for(int i = 0; i < N; i++) if(!used[i])
		ans.push_back({2*A[i], 3*A[i]});
	cout << ans.size() << "\n";
	for(auto p : ans) cout << p.ff << " " << p.ss << "\n";
}

// look at my code
// my code is amazing