#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

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

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 100100;

map <int, int> mp;
pii s[MAXN]; int top, n;

double k (pii x, pii y) { return 1.0 * (y.se - x.se) / (y.fr - x.fr); }

signed main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        int x = read(), y = read() - x * x;
        if (!mp.count(x)) mp[x] = y;
        else if (mp[x] < y) mp[x] = y;
    }
    for (auto i: mp) {
        while (top >= 2 && k(s[top - 1], s[top]) <= k(s[top], i)) --top;
        s[++top] = i;
    }
    printf("%lld\n", top - 1);
    return 0;
}