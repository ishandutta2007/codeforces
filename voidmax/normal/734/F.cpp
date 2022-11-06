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
#define x first
#define y second
#define pb push_back
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
 
const string FILENAME = "input";
typedef long long base;

const int MAXN = 2e5 + 1, LOG = 31;

int n;
long long sum;
int cnt[31];
long long a[MAXN], b[MAXN], c[MAXN];

int dev(long long a, int b) {
    if ((a % b) || (a < 0)) {
        cout << -1 << endl;
        exit(0);
    }
    return a / b;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum += b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    sum = dev(sum, n * 2);
    for (int i = 0; i < n; ++i) {
        a[i] = dev(b[i] + c[i] - sum, n);
        for (int j = 0; j < LOG; ++j) {
            cnt[j] += (a[i] >> j) & 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        long long b = 0, c = 0;
        for (int j = 0; j < LOG; ++j) {
            if (a[i] & (1 << j)) {
                b += (1LL << j) * cnt[j];
                c += (1LL << j) * n;
            } else {
                c += (1LL << j) * cnt[j];
            }
        }
        if (::b[i] != b || ::c[i] != c) {
            cout << -1 << endl;
            exit(0);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}