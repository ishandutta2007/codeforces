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
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
       
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
     
const string FILENAME = "subrev";
const int MAXN = 1e6;

int n, k;
int L, R;
int p[MAXN + 1], used[MAXN + 1], cnt[MAXN + 1];
bool bag[MAXN + 1];

int main(int argc, char const *argv[]) {
    srand(time(0));
    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int j = i, c = 0;
        while (!used[j]) {
            used[j] = true;
            ++c;
            j = p[j];
        }
        ++cnt[c];
    }
    int m = min(k, n - k);
    bag[m] = true;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) continue;
        for (int j = 0; j <= m; ++j) {
            if (bag[j]) {
                for (int k = 1; k <= cnt[i]; ++k) {
                    if (j - k * i < 0 || bag[j - k * i])
                        break;
                    bag[j - k * i] = true;
                }
            }
        }
    }
    if (bag[0]) L = k;
    else L = k + 1;
    m = cnt[1];
    for (int i = 2; i <= n; ++i) {
        int r = i / 2;
        if (i & 1) m += cnt[i];
        while (k && cnt[i]) {
            if (k >= r) {
                k -= r;
                R += r * 2;
                --cnt[i];
            } else {
                R += k * 2;
                k = 0;
            }
        }
    }
    R += min(m, k);
    cout << L << ' ' << R << endl;
}