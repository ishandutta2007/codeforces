#pragma GCC optimize(3)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 100100, mod = 998244353;
int n, a[MAXN];

unordered_map <int, int> cur, tmp;


int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        int ans = 0; tmp.clear(), cur.clear();
        for (i = n; i >= 1; i--) {
            bool done = 0; tmp.clear();
            for (auto j: cur) {
                int parts = (a[i] - 1) / j.fr + 1;
                ans = (ans + 1ll * (parts - 1) * j.se % mod * i) % mod;
                int to = a[i] / parts;
                tmp[to] += j.se;
            }
            ++tmp[a[i]]; swap(cur, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}