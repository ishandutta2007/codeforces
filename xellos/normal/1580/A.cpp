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
		int N,M;
		cin >> N >> M;
		vector<string> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector< vector<int> > sum(N, vector<int>(M+1, 0));
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
			sum[i][j+1] = sum[i][j] + (A[i][j]-'0');
		int ans = N*M;
		for(int b = 4; b <= M; b++) {
			vector< vector<int> > cost_in(N, vector<int>(M, N*M));
			for(int i = 0; i < N; i++) for(int j = 0; j <= M-b; j++)
				cost_in[i][j] = sum[i][j+b-1] - sum[i][j+1] + (A[i][j] == '0') + (A[i][j+b-1] == '0');
			vector< vector<int> > cost(N, vector<int>(M, N*M));
			for(int i = N-1; i >= 0; i--) {
				if(i < N-1) for(int j = 0; j <= M-b; j++)
					cost[i][j] = cost[i+1][j]+cost_in[i][j];
				if(i+3 < N) for(int j = 0; j <= M-b; j++)
					cost[i][j] = min(cost[i][j], cost_in[i][j]+cost_in[i+1][j]+cost_in[i+2][j]+b-2-(sum[i+3][j+b-1]-sum[i+3][j+1]));
			}
			for(int i = 0; i < N-1; i++) for(int j = 0; j <= M-b; j++)
				ans = min(ans, cost[i+1][j] + b-2-(sum[i][j+b-1]-sum[i][j+1]));
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing