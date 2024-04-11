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
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";
typedef long long base;

int n, k;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if (!(k == 2 || k == 3) || n < 4 || (n == 4 && k == 2)) {
        cout << -1 << endl;
        return 0;
    }
    if (k == 3) {
        cout << (n - 4) * 2 + 3 << endl;
        cout << 1 << ' ' << 2 << endl;
        cout << 2 << ' ' << 3 << endl;
        cout << 1 << ' ' << 4 << endl;
        for (int j = 5; j <= n; ++j) {
            cout << 1 << ' ' << j << endl;
            cout << 2 << ' ' << j << endl;
        }
        return 0;
    }
    if (k == 2) {
        cout << n - 1 << endl;
        for (int i = 1; i < n; ++i) {
            cout << i << ' ' << i + 1 << endl;
        }
    } 
}