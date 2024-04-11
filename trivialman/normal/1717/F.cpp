#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e4 + 5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int hd[N << 1], iter[N << 1], dis[N << 1];
struct E {
    int v, w, nxt;
} e[N << 3];
queue<int> Q;
int n, m, d, tot = 1, S, T;
int s[N], a[N], b[N], x[N], y[N];

inline void add(int u, int v, int w) {
    e[++tot] = {v, w, hd[u]}, hd[u] = tot;
    e[++tot] = {u, 0, hd[v]}, hd[v] = tot;
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
    for (int& i = iter[x]; i; i = e[i].nxt)
        if (e[i].w && dis[y = e[i].v] == dis[x] + 1) {
            int w = dfs(y, min(f, e[i].w));
            e[i].w -= w, e[i ^ 1].w += w;
            f -= w, sf += w;
            if (!f)
                break;
        }
    return sf;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> s[i];
    rep(i, 1, n) cin >> a[i];

    S = 0, T = m + n + 1;
    rep(i, 1, m) {
        cin >> x[i] >> y[i];
        add(S, i, 1), add(i, m + x[i], 1), add(i, m + y[i], 1);
        a[x[i]]++, a[y[i]]++;
    }
    bool flag = true;
    int sum = 0, flow = 0;
    rep(i, 1, n) if (s[i]) {
        if (a[i] < 0 || a[i] % 2)
            flag = false;
        a[i] /= 2, sum += a[i];
        add(m + i, T, a[i]);
    }
    else {
        add(m + i, T + 1, INF);
    }
    add(T + 1, T, max(m - sum, 0));

    while (bfs())
        flow += dfs(S);
    if (!flag || sum > m || flow < m)
        cout << "NO";
    else {
        cout << "YES\n";
        rep(i, 1, m) {
            int tmp = 0;
            for (int u = hd[i]; u; u = e[u].nxt)
                tmp = e[u].w == 0 && e[u].v > m ? e[u].v - m : tmp;
            cout << x[i] + y[i] - tmp << " " << tmp << "\n";
        }
    }
    return 0;
}