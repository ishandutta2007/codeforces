#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 2e5 + 10;
vector<int> g[N];
int pos[N], sz[N], h[N], V[N], pr[N], timer;

void dfs(int v, int p = 0, int ch = 1) {
    pos[v] = ++timer;
    V[timer] = v;
    h[v] = ch;
    pr[v] = p;
    sz[v] = 1;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v, ch + 1);
            sz[v] += sz[u];
        }
    }
}

pair<int, int> t[4 * N];
int f[4 * N];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = {h[V[l]], V[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

void push(int v) {
    if (f[v] != 0) {
        f[2 * v] += f[v];
        f[2 * v + 1] += f[v];
        t[2 * v].F += f[v];
        t[2 * v + 1].F += f[v];
        f[v] = 0;
    }
}

void update(int v, int l, int r, int a, int b, int delta) {
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        t[v].F += delta;
        f[v] += delta;
        return;
    }
    push(v);
    int mid = (l + r) / 2;
    update(2 * v, l, mid, a, b, delta);
    update(2 * v + 1, mid + 1, r, a, b, delta);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get(int white, int red, int remain) {
    if (remain <= red) {
        return white * (red - remain);
    }
    remain -= red;
    int l = 0, r = remain;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if ((white + remain - mid) * mid >= (white + remain - mid - 1) * (mid + 1)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return -max((white + remain - l) * l, (white + remain - r) * r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    /*for (int i = 1; i <= n; i++) {
        cerr << V[i] << ' ';
    }
    cerr << '\n';*/
    build(1, 1, n);
    int remain = n, ans = get(0, 0, n), white = 0;
    //cerr << pos[4] << ' ' << h[4] << '\n';
    for (int i = 1; i <= k; i++) {
        auto [val, v] = t[1];
        remain -= val;
        white += val - 1;
        ans = max(ans, get(white, i, remain));
        //cout << v << ' ' << val << ' ' << pos[v] << '\n';
        for (int j = 0; j < val; j++) {
            //cerr << v << ' ' << pos[v] << ' ' << pos[v] + sz[v] - 1 << '\n';
            update(1, 1, n, pos[v], pos[v] + sz[v] - 1, -1);
            v = pr[v];
            //cerr << t[2].F << ' ' << t[2].S << '\n';
        }
        //cout << i << ' ' << ' ' << remain << ' ' << white << ' ' << ans << '\n';
    }
    cout << ans << '\n';
}