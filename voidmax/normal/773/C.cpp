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
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
 
using namespace std;
 
typedef long long base;
typedef pair <int, int> point;
 
const string FILENAME = "input";
const int MAXN = 1e5 + 1;

int n;
long long a[MAXN];
int cnt2[60];
vector <long long> good, bad, res;

bool check(int M) {
    good.clear();
    res.clear();
    for (int i = 0; i < MAXN; ++i)
        a[i] = -1;
    int r = M;
    for (int i = 0; i < 60; ++i) {
        if (r == 0) break;
        r = min(cnt2[i], r);
        for (int j = 0; j < (cnt2[i] - r); ++j) {
            good.pb(1LL << i);
        }
        for (int j = 0; j < r; ++j) {
            a[j] = 1LL << i;
        }
    }   
    res.resize(good.size() + bad.size());
    merge(good.begin(), good.end(), bad.begin(), bad.end(), res.begin());
    for (int i = 0; i < M; ++i) {
        if (res.size() == 0) break;
        if (res.back() / a[i] >= 2)
            return false; 
        res.pop_back();
    }
    return res.size() == 0;
}   

int main() {
    ios::sync_with_stdio(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        if ((c & (c - 1)) == 0) {
            long long r = c, k = 0;
            while ((r % 2) == 0) {
                ++k;
                r /= 2;
            }
            ++cnt2[k];
        } else {
            bad.pb(c);
        }
    }
    int L = 0, R = cnt2[0] + 1;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    //check(2);
    if (R > cnt2[0]) {
        cout << -1 << endl;
    } else {
        for (int i = R; i <= cnt2[0]; ++i) {
            cout << i << ' ';
        }
        cout << endl;
    }
}