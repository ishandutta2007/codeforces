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
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

typedef long long ll;
typedef long double ld;

const string FILENAME = "input";

const int MAXN = 151;

int n;
vector <pair <char, int>> a;
int ans[3];

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	for (int b = 0; b < 10; ++b) {
		int c[2] = {0, 1};
		for (int i = 0; i < n; ++i) {
			if (a[i].x == '|') {
				c[0] |= (a[i].y >> b) & 1;
				c[1] |= (a[i].y >> b) & 1;
			} else if (a[i].x == '&') {
				c[0] &= (a[i].y >> b) & 1;
				c[1] &= (a[i].y >> b) & 1;
			} else {
				c[0] ^= (a[i].y >> b) & 1;
				c[1] ^= (a[i].y >> b) & 1;
			}
		}
		if (c[0] == 0 && c[1] == 0) {
			continue;
		} else if (c[0] == 0 && c[1] == 1) {
			ans[0] |= 1 << b;
		} else if (c[0] == 1 && c[1] == 0) {
			ans[0] |= 1 << b;
			ans[1] |= 1 << b;
		} else {
			ans[2] |= 1 << b;
		}
	}
	cout << 3 << endl;
	cout << "& " << ans[0] << endl;
	cout << "^ " << ans[1] << endl;
	cout << "| " << ans[2] << endl;
}