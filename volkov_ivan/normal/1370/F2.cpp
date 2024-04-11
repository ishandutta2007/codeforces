#include <bits/stdc++.h>

using namespace std;

const int N = 1007;
vector <int> g[N];
int pr[N], h[N];

void init() {
    for (int i = 0; i < N; i++) g[i].clear();
}

pair <int, int> ask(vector <int> v) {
    assert(!v.empty());
    cout << "? " << v.size() << ' ';
    for (int elem : v) cout << elem << ' ';
    cout << endl;
    int a, b;
    cin >> a >> b;
    assert(a != -1 && b != -1);
    return {a, b};
}

void dfs(int v, int hh = 0, int par = -1) {
    h[v] = hh;
    pr[v] = par;
    for (int u : g[v]) {
        if (u != par) dfs(u, hh + 1, v);
    }
}

void solve() {
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    cout << "? " << n << ' ';
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << endl;
    int v, d;
    cin >> v >> d;
    dfs(v); 
    int l = d / 2 - 1, r = d + 1, ans1 = -1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector <int> cur;
        for (int i = 1; i <= n; i++) {
            if (h[i] >= mid) cur.push_back(i);
        }
        if (cur.empty()) {
            r = mid;
            continue;
        }
        auto [x, cd] = ask(cur);
        if (cd == d) {
            ans1 = x;
            l = mid;
        } else r = mid;
    }
    int dpth2 = d - l;
    assert(dpth2 >= 0);
    assert(ans1 != -1);
    if (dpth2 == 0) {
        cout << "! " << v << ' ' << ans1 << endl;
        return;
    }
    int cv = ans1, cd = l;
    while (cd != dpth2) {
        cd--;
        cv = pr[cv];
    }
    vector <int> cur;
    for (int i = 1; i <= n; i++) {
        if (h[i] == dpth2 && i != cv) cur.push_back(i);
    }
    assert(!cur.empty());
    auto [ans2, dd] = ask(cur);
    assert(dd == d);
    cout << "! " << ans1 << ' ' << ans2 << endl;
}

signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        string s;
        cin >> s;
        assert(s == "Correct");
    }
    return 0;
}