#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 50005;

vector <int> adj[N];
int fa[N], _a[N], _dep[N], a[N], t[N], dep[N], tops[N], siz[N];
int n, q, cnt, ans, dfn;

void dfs0(int u) {
    tops[u] = ++dfn; siz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) _dep[adj[u][i]] = _dep[u] + 1, dfs0(adj[u][i]), siz[u] += siz[adj[u][i]];
}

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(_a[i]);
    for (int i = 2; i <= n; i++) read(fa[i]), adj[fa[i]].push_back(i);
    dfs0(1);
    for (int i = 1; i <= n; i++) a[tops[i]] = _a[i], dep[tops[i]] = _dep[i];
    for (int T = 1; T <= q; T++) {
        int x; read(x); ans = cnt = 0;
        for (register int i = tops[x]; i <= tops[x] + siz[x] - 1; ++i) {
            if (t[i] <= T) {
                ans += dep[i];
                ++cnt;
                t[i] = T + a[i];
            }
        }
        print(ans - cnt * _dep[x], ' '); print(cnt, '\n');
    }
    return 0;
}