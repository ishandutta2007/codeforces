#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
int n, m, a[MAXN];
vector <int> b[MAXN], d;

int dis (int u, int v) { return min(abs(u - v), n - (u - v)); }

bool vis[MAXN];
bool attempt (vector <int> &v, int k) {
    int s = v.size(), i, j, d0 = 0;
    for (auto i: v) vis[i] = 1;
    for (auto i: v) if (!vis[(i + k) % n]) return 0;
    return 1;
    // for (i = 1; i < s; i++) if (v[i] - v[0] == k) { d0 = i; break; }
    // if (!d0) return 0;
    // for (i = 0; i < s; i++) if ((v[(i + d0) % s] - v[i] + n) % n != k) return 0;
    // return 1;
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) if (n % i == 0) d.push_back(i);
    for (i = 1; i <= m; i++) {
        int u = read() - 1, v = read() - 1;
        if (u > v) swap(u, v);
        if (v - u > n - (v - u)) {
            // printf("go %d\n", n - (v - u));
            b[n - (v - u)].push_back(v);
            b[n - (v - u)].push_back(u);
        }
        else {
            b[v - u].push_back(u);
            b[v - u].push_back(v);
        }
    }
    long long cur = 1;
    for (i = 1; i <= n; i++) if (b[i].size() == 1) {
        if (i == (n >> 1) && n % 2 == 0) cur = n >> 1;
        else { puts("No"); return 0; }
    }
    for (i = 1; i <= n; i++) if (!b[i].empty() && b[i].size() != 1) {
        // printf("!! %d %d\n", i, b[i].size());
        sort(b[i].begin(), b[i].end());
        // for (auto j: b[i]) vis[j] = 1, cout << j << ' ';cout << endl;
        bool fin = 0;
        // cout << attempt(b[i], 5) << endl; return 0;
        for (auto k: d) if (attempt(b[i], k)) {
            // cout << k << endl;
            fin = 1;
            cur = 1ll * cur * k / __gcd(cur, 1ll * k);
            if (cur == n) { puts("No"); return 0; }
            break;
        }
        for (auto j: b[i]) vis[j] = 0;
        if (!fin) { puts("No"); return 0; }
    }
    puts("Yes");
    return 0;
}