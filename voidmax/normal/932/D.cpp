// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
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
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
  
typedef long double base;
typedef pair<base, base> point;

const string FILENAME = "input";
const int MAXN = 400001, LOG = 19;

int t = 1;
long long last;
long long maxv[MAXN][LOG];
int up[MAXN][LOG];
int up1[MAXN][LOG];
long long w[MAXN][LOG];

void add(long long R, long long W) {
	R ^= last;
	W ^= last;
	//cout << "+" << t << ' '<< R << ' ' << W << endl;
	up[t][0] = R;
	maxv[t][0] = W;
	for (int i = 0; i + 1 < LOG; ++i) {
		if (up[t][i] == -1 || up[up[t][i]][i] == -1) {
			up[t][i + 1] = maxv[t][i + 1] = -1;
		} else {
			up[t][i + 1] = up[up[t][i]][i];
			maxv[t][i + 1] = max(maxv[t][i], maxv[up[t][i]][i]);
		}
	} 
	int u = R;
	if (maxv[u][0] < W) {
		for (int i = LOG; i--;) {
			if (up[u][i] != -1 && maxv[u][i] < W) {
				//cout << u << endl;
				u = up[u][i];
				//cout << u << endl;
			}
		}
	} 
	//cout << "				" << t << ' ' << u << endl;
	up1[t][0] = u;
	w[t][0] = W;
	for (int i = 0; i + 1 < LOG; ++i) {
		if (up1[t][i] == -1 || up1[up1[t][i]][i] == -1) {
			up1[t][i + 1] = w[t][i + 1] = -1;
		} else {
			up1[t][i + 1] = up1[up1[t][i]][i];
			w[t][i + 1] = w[t][i] + w[up1[t][i]][i];
		}
	} 
	++t;
}

long long get(long long R, long long X) {
	R ^= last;
	X ^= last;
	int ans = 0;
	//cout << R << ' ' << X << '?' << endl;
	for (int i = LOG; i--;) {
		if (up1[R][i] > 0 && w[R][i] <= X) {
			ans += (1 << i);
			X -= w[R][i];
			R = up1[R][i];
		}
	}
	//cout << "!" << R << endl;
	if (w[R][0] <= X) ++ans;
	return ans;
}

int n;

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	w[0][0] = 1e18;
	for (int i = 0; i < LOG; ++i) {
		up[0][i + 1] = -1;
	} 
	add(0, 0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		long long P, Q;
		cin >> t >> P >> Q;
		if (t == 1) {
			add(P, Q);
		} else {
			last = get(P, Q);
			cout << last << '\n';
		}
	}
}