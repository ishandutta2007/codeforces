#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100, magic = 320;
int n, a[MAXN];

using ll = long long;
unordered_map <ll, int> cnt2[MAXN << 1];

namespace Hash {
    const int mod = 1e7 + 19;
    struct Edge { int nex; ll val, cnt; } edge[MAXN];
    int head[mod], cnt;
    int add (ll val) {
        int id = (val % mod + mod) % mod;
        for (int i = head[id]; i; i = edge[i].nex) if (edge[i].val == val) { ++edge[i].cnt; return edge[i].cnt; }
        ++cnt; edge[cnt] = {head[id], val, 1}, head[id] = cnt; return 1;
    }
    void clear () {
        for (int i = 1; i <= cnt; i++) {
            int id = (edge[i].val % mod + mod) % mod;
            head[id] = 0; edge[i] = {0, 0, 0};
        }
        cnt = 0;
    }
}

int tmp[MAXN], top;

int main () {
    n = read(); int i, j, ans = n - 1;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = -magic; i <= magic; i++) {
        Hash::clear();
        for (j = 1; j <= n; j++) {
            ll val = a[j] - 1ll * j * i;
            int res = Hash::add(val); ans = min(ans, n - res);
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = max(1, i - magic); j < i; j++) {
            if ((a[i] - a[j]) % (i - j) != 0) continue;
            ll d = (a[i] - a[j]) / (i - j), val = a[i] - 1ll * d * i;
            ++cnt2[d + 100000][val]; tmp[++top] = d + 100000;
            ans = min(ans, n - cnt2[d + 100000][val] - 1);
        }
        for (j = 1; j <= top; j++) cnt2[tmp[j]].clear();
        top = 0;
    }
    printf("%lld\n", ans);
    return 0;
}