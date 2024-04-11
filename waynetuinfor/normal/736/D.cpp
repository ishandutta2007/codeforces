#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int maxk = 5e5 + 5;
int a[maxk], b[maxk];

#define getchar gtx
inline int gtx() {
    const int N = 4096;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}
template <typename T>
inline bool rit(T& x) {
    char c = 0; bool flag = false;
    while (c = getchar(), (c < '0' && c != '-') || c > '9') if (c == -1) return false;
    c == '-' ? (flag = true, x = 0) : (x = c - '0');
    while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    if (flag) x = -x;
    return true;
}
template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int main() {
    // int n, m; scanf("%d%d", &n, &m);
    int n, m; rit(n, m);
    vector<valarray<uint64_t>> v(n), w(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize((n + 63) >> 6);
        w[i].resize((n + 63) >> 6);
    }
    for (int i = 0; i < m; ++i) {
        // scanf("%d%d", &a[i], &b[i]);
        rit(a[i], b[i]);
        --a[i], --b[i];
        v[a[i]][b[i] >> 6] ^= 1ull << (b[i] & 63);
    }
    for (int i = 0; i < n; ++i) {
        w[i][i >> 6] ^= 1ull << (i & 63);
    }
    for (int i = 0; i < n; ++i) {
        int p = -1;
        for (int j = i; j < n; ++j) {
            if (v[j][i >> 6] >> (i & 63) & 1ull) p = j;
        }
        if (p == -1) continue;
        swap(v[i], v[p]);
        swap(w[i], w[p]);
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (v[j][i >> 6] >> (i & 63) & 1ull) {
                v[j] ^= v[i];
                w[j] ^= w[i];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (w[b[i]][a[i] >> 6] >> (a[i] & 63) & 1ull) puts("NO");
        else puts("YES");
    }
}