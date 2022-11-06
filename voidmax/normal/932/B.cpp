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
const int MAXN = 1e6 + 1;

int n;
int g[MAXN];
vector<int> res[10];

int get(int R, int k) {
	return upper_bound(res[k].begin(), res[k].end(), R) - res[k].begin();
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	for (int i = 0; i < MAXN; ++i) {
		if (i < 10) {
			g[i] = i;
		} else {
			int a = 1;
			int j = i;
			while (j > 0) {
				if (j % 10 != 0) {
					a *= (j % 10);
				}
				j /= 10;
			}
			g[i] = g[a];
			//cout << f[i] << ' ' << i << endl;
		}
		res[g[i]].pb(i);
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int L, R, k;
		cin >> L >> R >> k;
		cout << get(R, k) - get(L - 1, k) << '\n';
		// for (int j : res[k]) {
		// 	if (L <= j && j <= R) cout << j << ' ';
		// }
		// cout << endl;
	}
}