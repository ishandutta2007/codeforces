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
#define OVER9000 1234567890123LL
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

cat calc(cat sum, int n_inc, int n_dec, cat W) {
	if(n_inc < 0 || n_dec < 0) return OVER9000;
	if(n_inc >= n_dec) return sum + W * n_inc;
	else return sum + W * n_dec;
}

void DFS(int R, int par, auto & G, auto & W, auto & H, auto & dp) {
	for(auto s : G[R]) if(s != par) DFS(s, R, G, W, H, dp);
	for(int k = -1; k <= 1; k++) {
		if(k == 0 && R != par) continue;
		static vector<cat> dif;
		cat sum_incdec = 0;
		int n_inc = 0, n_dec = 0;
		dif.clear();
		for(auto s : G[R]) if(s != par) {
			if(H[s] > H[R]) sum_incdec += dp[s*3+2], n_inc++;
			if(H[s] < H[R]) sum_incdec += dp[s*3], n_dec++;
			if(H[s] == H[R]) {
				sum_incdec += dp[s*3];
				n_dec++;
				dif.push_back(dp[s*3+2]-dp[s*3]);
			}
		}
		sort(begin(dif), end(dif));
		cat best = calc(sum_incdec, n_inc+(k==-1), n_dec+(k==1), W[R]);
		for(int i = 0; i < (int)dif.size(); i++) {
			sum_incdec += dif[i];
			n_inc++;
			n_dec--;
			best = min(best, calc(sum_incdec, n_inc+(k==-1), n_dec+(k==1), W[R]));
		}
		dp[R*3+k+1] = min(best, OVER9000);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	vector<cat> W(N);
	vector<int> H(N);
	for(int i = 0; i < N; i++) cin >> W[i];
	for(int i = 0; i < N; i++) cin >> H[i];
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<cat> dp(N*3, OVER9000);
	DFS(0, 0, G, W, H, dp);
	cout << dp[1] << "\n";
}

// look at my code
// my code is amazing