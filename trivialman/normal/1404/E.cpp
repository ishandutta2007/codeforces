#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 205, M = 8e4 + 5;
mt19937 rng(time(0));

int hd[M], iter[M], dis[M];
struct E {
    int v, w, nxt;
} e[M << 3];
queue<int> Q;
int n, m, tot = 1, S, T;
char s[N][N];

inline void add(int u, int v, int w) {
    e[++tot] = {v, w, hd[u]};
    hd[u] = tot;
    e[++tot] = {u, 0, hd[v]};
    hd[v] = tot;
}
inline bool bfs() {
    memcpy(iter, hd, sizeof(hd));
    memset(dis, -1, sizeof(dis));
    Q.push(S);
    dis[S] = 0;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = hd[x], y; i; i = e[i].nxt)
            if (e[i].w && dis[y = e[i].v] == -1) {
                dis[y] = dis[x] + 1, Q.push(y);
            }
    }
    return ~dis[T];
}
int dfs(int x = S, int f = INF) {
    if (x == T || !f)
        return f;
    int sf = 0, y;
    for (int &i = iter[x]; i; i = e[i].nxt)
        if (e[i].w && dis[y = e[i].v] == dis[x] + 1) {
            int w = dfs(y, min(f, e[i].w));
            e[i].w -= w, e[i ^ 1].w += w;
            f -= w, sf += w;
            if (!f)
                break;
        }
    return sf;
}

inline int key(int type, int i, int j) {
    //0: vertical; 1: horizontal
    return type * n * m + (i - 1) * m + j;
}

int main() {
    cin >> n >> m;
    rep(i, 1, n) cin >> (s[i] + 1);
    S = 0, T = 2 * n * m + 1;
    rep(i, 1, n - 1) rep(j, 1, m - 1) {
        if (s[i][j] == '#' && s[i][j + 1] == '#' && s[i + 1][j] == '#')
            add(key(0, i, j), key(1, i, j), 1);
        if (s[i][j] == '#' && s[i][j + 1] == '#' && s[i + 1][j + 1] == '#')
            add(key(0, i, j), key(1, i, j + 1), 1);
        if (s[i][j] == '#' && s[i + 1][j + 1] == '#' && s[i + 1][j] == '#')
            add(key(0, i + 1, j), key(1, i, j), 1);
        if (s[i + 1][j + 1] == '#' && s[i][j + 1] == '#' && s[i + 1][j] == '#')
            add(key(0, i + 1, j), key(1, i, j + 1), 1);
    }
    int nv = 0, nb = 0;
    rep(i, 1, n) rep(j, 1, m - 1) if (s[i][j] == '#' && s[i][j + 1] == '#') add(S, key(0, i, j), 1), nv++;
    rep(i, 1, n - 1) rep(j, 1, m) if (s[i][j] == '#' && s[i + 1][j] == '#') add(key(1, i, j), T, 1), nv++;
    rep(i, 1, n) rep(j, 1, m) nb += (s[i][j] == '#');
    int ans = 0;
    while (bfs())
        ans += dfs();
    cout << nb - nv + ans << endl;
    return 0;
}