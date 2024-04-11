#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n;
int a[200200] = {};
int cnt = 0;

map <int, int> mp;

struct rua {
    int l;
    int r;
} c[200200] = {};
bool cmp (rua x, rua y) { return x.r< y.r; }

signed main () {
    n = read();
    int i, j;
    int ans = n * (n + 1) / 2;
    mp[0] = 1;
    for (i = 1; i <= n; i++) a[i] = a[i - 1] + read();
    for (i = 1; i <= n; i++) {
        if (mp[a[i]] != 0) {
            c[++cnt].l = mp[a[i]], c[cnt].r = i;
        }
        mp[a[i]] = i + 1;
    }
    sort(c + 1, c + cnt + 1, cmp);
    int l = 0;
    for (i = 1; i <= cnt; i++) {
        if (c[i].l < l) continue;
        ans -= (c[i].l - l) * (n - c[i].r + 1);
        l = c[i].l;
    }
    cout <<ans;
    return 0;
}