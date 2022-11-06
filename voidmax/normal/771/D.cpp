#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FileName = "input";
const int INF = 2e9;
const int MAXN = 1 << 18;
typedef pair <int, int> point;
typedef long double base;

int n;
string s;
int dp[80][80][80][2];

int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FileName);
	cin >> n >> s;
	for (int V = 0; V <= n; ++V) {
		for (int K = 0; V + K <= n; ++K) {
			for (int Q = 0; V + K + Q <= n; ++Q) {
				dp[V][K][Q][0] = dp[V][K][Q][1] = 1e9;
			}
		}
	}
	dp[0][0][0][0] = 0;
	for (int V = 0; V <= n; ++V) {
		for (int K = 0; V + K <= n; ++K) {
			for (int Q = 0; V + K + Q < n; ++Q) {
				if (dp[V][K][Q][0] == 1e9 && dp[V][K][Q][1] == 1e9) {
					continue;
				}
				int v = V, k = K, q = Q;
				int c = 0;
				int v1 = -1, k1 = -1, q1 = -1;
				for (int i = 0; i < n; ++i) {
					if (s[i] == 'V') {
						if (v == 0) v1 = c;
						if (v <= 0) ++c;
						--v;
					} else if (s[i] == 'K') {
						if (k == 0) k1 = c;
						if (k <= 0) ++c;
						--k;
					} 
					else {
						if (q == 0) q1 = c;
						if (q <= 0) ++c;
						--q;
					} 
				}
				int res = min(dp[V][K][Q][0], dp[V][K][Q][1]);
				//cout << V + K + Q << ' ' << dp[V][K][Q][0] << ' ' << dp[V][K][Q][1] << ' ' << V << ':' << K << ':' << Q << ' ' << v1 << ' ' << k1 << ' ' << q1 << endl;
				if (v1 != -1) chkmin(dp[V + 1][K][Q][1], res + v1);
				if (k1 != -1) chkmin(dp[V][K + 1][Q][0], dp[V][K][Q][0] + k1);
				if (q1 != -1) chkmin(dp[V][K][Q + 1][0], res + q1);
			}
		}
	}
	int ans = 1e9;
	for (int V = 0; V <= n; ++V) {
		for (int K = 0; V + K <= n; ++K) {
			int Q = n - V - K;
			chkmin(ans, dp[V][K][Q][0]);
			chkmin(ans, dp[V][K][Q][1]);
		}
	}
	cout << ans << endl;
}  

/*

AAAAA 2121212
*/