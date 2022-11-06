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
#define point pair <int, int>
#define x first
#define y second
#define free free228
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
typedef long long base;
const int MAXN = 2e6 + 1;

int n, k;

bool check(int M) {
	int res = k - 2;
	long long cnt = M;
	int L = (M + 1) / 2, R = M / 2 + 1;
		//cout << M << endl;

	while (res && L) {
		//cout << L << '!' << R << endl;
		cnt += L - 1;
		--res;
		//--L, ++R;
	}
	return cnt >= n - k;
}

void init(int M, int n, int k) {
	int id = M + 3;
	int L = (M + 1) / 2, R = M / 2 + 1;
	while (k && n) {
		//cout << n << '-' << k << ' ' << L - 1 << endl;
		int lst = L + 1;
		for (int i = 0; i < min(L - 1, n); ++i) {
			cout << lst << ' ' << id << endl;
			lst = id;
			++id;
		}
		n -= min(L - 1, n);
		cout << lst << ' ' << id << endl;
		++id, --k;
	}
	while (k) {
		cout << id << ' ' << 2 << endl;
		++id, --k;
	}
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n >> k;
    int L = 0, R = 2e5 + 1;
    while (R - L > 1) {
    	int M = (L + R) >> 1;
    	if (check(M)) {
    		R = M;
    	} else {
    		L = M;
    	}
    }
    cout << R + 1 << endl;
    for (int i = 1; i <= R + 1; ++i) {
    	cout << i << ' ' << i + 1 << '\n';
    }
    init(R, n - R - k, k - 2);
}