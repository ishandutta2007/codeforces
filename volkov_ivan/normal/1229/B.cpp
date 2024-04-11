#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX_N = 1e5 + 7, K = 20, M = 1e9 + 7;
vector <int> g[MAX_N];
int jump[K][MAX_N], f[K][MAX_N];
int x[MAX_N];
int pr[MAX_N];
int d[MAX_N];
int ans = 0;
int up[MAX_N];

void dfs(int v, int p = -1, int dep = 0) {
    pr[v] = p;
    d[v] = dep;
    jump[0][v] = pr[v];
    f[0][v] = x[v];
    if (x[v] != 0) up[v] = v;
    else {
        if (v == 1) up[v] = 0;
        else up[v] = up[pr[v]];
    }
    for (int i = 1; i < K; i++) {
        if (jump[i - 1][v] == -1) jump[i][v] = -1;
        else { 
            jump[i][v] = jump[i - 1][jump[i - 1][v]];
            f[i][v] = __gcd(f[i - 1][v], f[i - 1][jump[i - 1][v]]);
        }
    }
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v, dep + 1);
        }
    }
}

void process(int v) {
    if (v == 0) return;
    if (x[v] == 0) {
        process(up[v]);
        return;
    }
    int cur = x[v];
    //int mem = ans;
    //int start = v;
    while (v != 0) {
        int t = v;
        for (int i = K - 1; i >= 0; i--) {
            if (jump[i][t] != -1 && f[i][t] % cur == 0) t = jump[i][t];
        }
        //cout << cur << ' ' << v << ' ' << t << endl;
        ans = (ans + cur * (d[v] - d[t])) % M;
        v = t;
        if (v == 0) break;
        cur = __gcd(cur, x[v]);
    }
    //cout << start << ' ' << ans - mem << endl;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    jump[0][1] = 0;
    d[0] = -1;
    for (int i = 1; i <= n; i++) process(i);
    cout << ans << endl;
    return 0;
}