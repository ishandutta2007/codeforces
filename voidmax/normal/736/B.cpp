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

const int MAXN = 1 << 20;

int n;

bool prime(int n) {
    for (int j = 2; n / j >= j; ++j) {
        if (n % j == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n;
    if (prime(n)) {
        cout << 1 << endl;
        return 0;
    }
    int m = n;
    while (m > 4 && (n & 1)) {
        if (prime(m)) {
            m -= 1;
            continue;
        }
        if (prime(m - 1)) {
            m -= 2;
            continue;
        }
        if (prime(m - 2)) {
            m -= 3;
            continue;
        }
        //cout << m << ' ' << m - 1 << ' ' << m - 2 << endl;
        if ((n % m) % 2 != 1) {
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
        }
        exit(0);
    }
    cout << 2 << endl;
}
//27,35,51,57,65,77,87,93,95,[Finished in 0.5s]