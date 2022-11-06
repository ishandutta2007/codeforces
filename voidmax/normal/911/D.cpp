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


const string FILENAME = "input";
typedef pair<int, int> point;
typedef long double base;

const int MAXN = 1501;
const int MAXB = MAXN / 64;

struct fen {
	bitset<MAXN> a;

	void add(int i) {
		while (i < MAXN) {
			a[i] = !a[i];
			i |= (i + 1);
		}	
	}

	int get(int i) {
		bool ans = 0;
		while (i >= 0) {
			ans ^= a[i];
			i &= (i + 1);
			--i;
		}
		return ans;
	}
};

int n, m;
int a[MAXN];
fen box;

int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	cin >> m;
    bool ans = 0;
    for (int j = n - 1; j >= 0; --j) {
        ans ^= box.get(a[j]);
        box.add(a[j]);
    }
    box.a.reset();
	for (int i = 0; i < m; ++i) {
		int L, R;
		cin >> L >> R;
		--L, --R;
		if (((R - L + 1) * (R - L) / 2) & 1) {
            ans ^= 1;
        }
		if (ans) {
			cout << "odd\n";
		} else {
			cout << "even\n";
		}
	}	
}